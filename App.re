/* open Revery; */
open Revery;
open Revery.Math;
/* open Revery.UI; */
open Reglfw;

module Gl = Reglfw.Glfw;

open Revenge;
open Revenge.Scene;
open Revenge.Scene.Primitives;


let isNative =
  switch (Sys.backend_type) {
  | Native => true
  | Bytecode => true
  | _ => false
  };


let getExecutingDirectory = () =>
  isNative ? Filename.dirname(Sys.argv[0]) ++ Filename.dir_sep : "";

/* The 'main' function for our app */
let init = app => {
  let s = Scene.create();
  /* Scene.React3d.test(); */

  /* Create a window! */
  let w = App.createWindow(app, "test");

  let size = Window.getSize(w);
  let aspectRatio = float_of_int(size.width) /. float_of_int(size.height);

  let view = Mat4.create();
  let projection = Mat4.create();

  Mat4.lookAt(
    view,
    Vec3.create(0.0, 0.0, 3.0),
    Vec3.create(0., 0., 0.),
    Vec3.create(0., 1., 0.),
  );

  Mat4.perspective(projection, 1.5708, aspectRatio, 0.1, 100.);

  let camera: Revenge.Scene.Camera.t = {view, projection};

  let geometry = Revenge.Geometry.Cube.create();

  Reglfw.Glfw.glfwMakeContextCurrent(w.glfwWindow);

  let imgPromise = Image.load(getExecutingDirectory() ++ "UVCheckerMap02-512.png");
  let _ = Lwt.bind(imgPromise, (v) => {
    

      let texture = Texture.ofImage(v);
  /* let solidMaterial = Revenge.Scene.Material.SolidColor.create(); */
  let textureMaterial = Revenge.Scene.Material.BasicTexture.create(texture);
  /* let _ = Scene.draw(s, */
  /*                       <AmbientLight color={Colors.yellow}> */
  /*                       <Transform transform={Mat4.create()} > */
  /*                           <Mesh geometry material /> */
  /*                       </Transform> */
  /*                       <Mesh geometry material /> */
  /*                       </AmbientLight>, */
  /*                    camera) */

  /* Create a UI 'container' */
  /* let ui = UI.create(w); */

  /* Set up some styles */
  /* let textHeaderStyle = Style.make(~backgroundColor=Colors.black, ~color=Colors.white, ~fontFamily="Lato-Regular.ttf", ~fontSize=24, ()); */

  Window.setShouldRenderCallback(w, () => true);

  let someTransform = Mat4.create();
  Mat4.fromTranslation(someTransform, Vec3.create(0., 3., 0.));

  /* Set up our render function */
  Window.setRenderCallback(
    w,
    () => {
      let time = Reglfw.Glfw.glfwGetTime();

      let someTransform = Mat4.create();
      Mat4.fromTranslation(
        someTransform,
        Vec3.create(0., sin(time) *. 3., 0.),
      );

      /* Reglfw.Glfw.glClearColor(1.0, 0., 0., 0.); */
      Gl.glClearDepth(1.0);

      Gl.glEnable(GL_DEPTH_TEST);
      /* Gl.glEnable(GL_BLEND); */

      /* Gl.glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); */
      Gl.glDepthFunc(GL_LEQUAL);

      let _ =
        Scene.draw(
          s,
          <AmbientLight color=Colors.yellow>
            <Transform transform=someTransform>
              <Mesh geometry material=textureMaterial />
            </Transform>
            <Mesh geometry material=textureMaterial />
          </AmbientLight>,
          camera,
        );
      ();
    },
  );
  Lwt.return();
  });
};

/* Let's get this party started! */
App.start(init);

/* open Revery; */
open Revery.Core;
/* open Revery.UI; */
open Reglm;

open Revenge;
/* open Revenge.Scene; */
open Revenge.Scene.Primitives;

/* The 'main' function for our app */
let init = app => {

  let s = Scene.create();
  /* Scene.React3d.test(); */

  /* Create a window! */
  let w = App.createWindow(app, "test");

  let view = Mat4.create();
  let projection = Mat4.create();

  Mat4.lookAt(view,
              Vec3.create(0.0, 0.0, 3.0),
              Vec3.create(0., 0., 0.),
              Vec3.create(0., 1., 0.));

  Mat4.perspective(projection, 1.5708, 1.0, 0.1, 100.);

  let camera: Revenge.Scene.Camera.t = {
    view: view,
    projection: projection,
  }

  let geometry = Revenge.Geometry.Cube.create();
  let material = Revenge.Scene.Material.SolidColor.create();

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

  /* Set up our render function */
  Window.setRenderCallback(w, () => {

      /* Reglfw.Glfw.glClearColor(1.0, 0., 0., 0.); */

      let _ = Scene.draw(s,
                        <AmbientLight color={Colors.yellow}>
                        <Transform transform={Mat4.create()} >
                            <Mesh geometry material />
                        </Transform>
                        <Mesh geometry material />
                        </AmbientLight>,
                     camera)
  });
};

/* Let's get this party started! */
App.start(init);

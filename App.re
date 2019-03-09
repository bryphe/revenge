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

  let camera: Revenge.Scene.Camera.t = {
    position: Vec3.create(0., 0., 0.),
    view: Mat4.create(),
    projection: Mat4.create(),
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

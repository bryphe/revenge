open Revery;
/* open Revery.Core; */
/* open Revery.UI; */

open Revenge;

/* The 'main' function for our app */
let init = app => {

  Scene.test();
  Scene.React3d.test();

  /* Create a window! */
  let _ = App.createWindow(app, "test");

  /* Create a UI 'container' */
  /* let ui = UI.create(w); */

  /* Set up some styles */
  /* let textHeaderStyle = Style.make(~backgroundColor=Colors.black, ~color=Colors.white, ~fontFamily="Lato-Regular.ttf", ~fontSize=24, ()); */

  /* Set up our render function */
  /* Window.setRenderCallback(w, () => { */

  /*   /1* This is where we render the UI - if you've used React or ReasonReact, it should look familiar *1/ */
  /*   UI.render(ui, */
  /*       <view style=(Style.make(~position=LayoutTypes.Absolute, ~bottom=10, ~top=10, ~left=10, ~right=10, ~backgroundColor=Colors.black, ()))> */
  /*           <text style=(textHeaderStyle)>"Hello World!"</text> */
  /*       </view>); */
  /* }); */
};

/* Let's get this party started! */
App.start(init);
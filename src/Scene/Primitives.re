module Camera = {
  let component = React3d.nativeComponent("scene");

  let make = (~camera: Camera.t, children) =>
    component(hooks =>
      (
        hooks,
        {
          make: () => Drawable.create(Camera(camera)),
          configureInstance: (~isFirstRender as _, node: Drawable.t) => {
            {...node, inner: Camera(camera)};
          },
          children,
        },
      )
    );

  let createElement = (~camera: Camera.t, ~children, ()) => {
    make(~camera, React3d.listToElement(children));
  };
};

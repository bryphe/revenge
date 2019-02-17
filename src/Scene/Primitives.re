module Camera = {
  let component = React3d.nativeComponent("camera");

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

module Mesh = {
  let component = React3d.nativeComponent("mesh");

  let make = (~geometry: Geometry.t, ~material: Material.t, children) =>
    component(hooks =>
      (
        hooks,
        {
          make: () => Drawable.create(Mesh(geometry, material)),
          configureInstance: (~isFirstRender as _, node: Drawable.t) => {
            {...node, inner: Mesh(geometry, material)};
          },
          children,
        },
      )
    );

  let createElement = (~geometry: Geometry.t, ~material: Material.t, ~children, ()) => {
    make(~geometry, ~material, React3d.listToElement(children));
  };
};

open Revery.Core;

module Camera = {
  let component = React3d.nativeComponent("Camera");

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
  let component = React3d.nativeComponent("Mesh");

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

module AmbientLight = {
  let component = React3d.nativeComponent("AmbientLight");

  let make = (~color: Color.t, children) =>
    component(hooks =>
      (
        hooks,
        {
          make: () => Drawable.create(AmbientLight(color)),
          configureInstance: (~isFirstRender as _, node: Drawable.t) => {
            {...node, inner: AmbientLight(color)};
          },
          children,
        },
      )
    );

  let createElement = (~color: Color.t, ~children, ()) => {
    make(~color, React3d.listToElement(children));
  };
};

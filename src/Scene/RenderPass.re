module Color = Revery.Color;

module AmbientLightPass = {
  type t = {
    color: Color.t,
    camera: Camera.t,
  };

  let create = (~color, ~camera, ()) => {color, camera};
};

type t =
  | AmbientLight(AmbientLightPass.t);

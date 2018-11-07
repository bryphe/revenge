open Reglm;

type t;

let perspective: (~fov: float=?, ~aspectRatio: float=?, ~near: float=?, ~far: float=?, Vec3.t, Vec3.t, Vec3.t) => t;

open Reglm;

type t = {
    viewMatrix: Mat4.t,
    projectionMatrix: Mat4.t
};

let perspective = () => {
    let ret: t = {
        viewMatrix: Mat4.create(),
        projectionMatrix: Mat4.create(),
    };
    ret;
};

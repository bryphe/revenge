open Reglm;

type t = {
    viewMatrix: Mat4.t,
    projectionMatrix: Mat4.t
};

let perspective = (~fov=0.785, ~aspectRatio=1.0, ~near=0.1, ~far=100., position, target, up) => {
    let view = Mat4.create();
    let projection = Mat4.create();

    Mat4.lookAt(view, position, target, up);
    Mat4.perspective(projection, fov, aspectRatio, near, far);

    let ret: t = {
        viewMatrix: view,
        projectionMatrix: projection,
    };
    ret;
};

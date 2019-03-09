
open Revery.Math;

open Drawable;

let defaultCamera = Mat4.create();
Mat4.lookAt(defaultCamera, 
            Vec3.create(0., 0., 3.), 
            Vec3.create(0., 0., 0.),
            Vec3.create(0., 1., 0.)
);

module RenderPass {

    type t = {
    | AmbientLight(Color.t)
    }
}

module Mesh {
    type t = {
        geometry: Geometry.t,
        material: Material.t,
    }
}

let t = {
    passes: list(RenderPass.t),
    meshes: list(Mesh.t), 
};

let collect: (Drawable.t, Camera.t) => t = (drawable, camera) => {


    let rec f = (camera: Mat4.t=defaultCamera, drawable: Drawable.t) => {
        switch (drawable.inner) {
        | SceneRoot => ()
        | Mesh(_) => prerr_endline("Mesh!")
        | AmbientLight(c) => prerr_endline("AmbientLight")
        | Transform(_) => prerr_endline("Transform")
        }

    };


    f(defaultCamera, drawawble)
};

let draw: (Drawable.t, Camera.t) => (drawable, camera) => {
    let passes = collect(drawable, camera);
}

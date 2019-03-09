
open Revery.Math;

module Colors = Revery.Core.Colors;

open Drawable;

let defaultCamera = Mat4.create();
Mat4.lookAt(defaultCamera, 
            Vec3.create(0., 0., 3.), 
            Vec3.create(0., 0., 0.),
            Vec3.create(0., 1., 0.)
);

module Mesh {
    type t = {
        geometry: Revery.Geometry.Geometry.t,
        material: Material.t,
    }
}


let collectMeshes: (Drawable.t) => list(Mesh.t) = (drawable) => {

    let rec f: Drawable.t => list(Mesh.t) = (drawable) => {
        open Mesh;

        let newItems: list(Mesh.t) = switch (drawable.inner) {
        | Mesh(geometry, material) => [{geometry, material}]
        | _ => []
        };

        List.fold_left((prev, curr) => {
            let meshes = f(curr);

            List.append(prev, meshes);
            
        }, newItems, drawable.children);
    };

    /* }; */

    f(drawable);
};

let draw: (Drawable.t, Camera.t) => unit = (drawable, _camera) => {
    let meshes = collectMeshes(drawable);
    /* let passes: list(RenderPass.t) = [RenderPass.AmbientColor(Colors.Yellow)]; */


    let pass = RenderPass.AmbientLight(Colors.white);

    let renderMesh = (pass: RenderPass.t, mesh: Mesh.t) => {
       mesh.material.draw(pass, mesh.geometry);
    }

    List.iter(renderMesh(pass), meshes);


    print_endline ("Meshes: " ++ string_of_int(List.length(meshes)));
};


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
        transform: Mat4.t,
    }
}


let collectMeshes: (Drawable.t, Mat4.t) => list(Mesh.t) = (drawable, world) => {

    let rec f: (Drawable.t, Mat4.t) => list(Mesh.t) = (drawable, world) => {
        open Mesh;

        let (world, newItems) = switch (drawable.inner) {
        | Transform(m) => {
            let  newTransform = Mat4.create();
            Mat4.multiply(newTransform, m, world);
            (newTransform, [])
        }
        | Mesh(geometry, material, xform) => {
            let transform = Mat4.create();
            Mat4.multiply(transform, xform, world);
            (transform, [{geometry, material, transform}])
        }
        | _ => (world, [])
        };

        List.fold_left((prev, curr) => {
            let meshes = f(curr, world);

            List.append(prev, meshes);
            
        }, newItems, drawable.children);
    };

    /* }; */

    f(drawable, world);
};

let draw: (Drawable.t, Camera.t) => unit = (drawable, camera) => {
    let meshes = collectMeshes(drawable, Mat4.create());
    /* let passes: list(RenderPass.t) = [RenderPass.AmbientColor(Colors.Yellow)]; */

    let pass = RenderPass.AmbientLight(RenderPass.AmbientLightPass.create(~color=Colors.yellow, ~camera=camera, ()));

    let renderMesh = (pass: RenderPass.t, mesh: Mesh.t) => {
       mesh.material.draw(pass, mesh.geometry, mesh.transform);
    }

    List.iter(renderMesh(pass), meshes);

    print_endline ("Meshes: " ++ string_of_int(List.length(meshes)));
};

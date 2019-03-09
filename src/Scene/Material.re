
/* open Revery; */
/* open Revery.Shaders; */
/* open Revery.Shaders.Shader; */

type t = {
    draw: (RenderPass.t, Geometry.t) => unit,
};

module SolidColor = {
    let create: unit => t = () => {

        let draw = (_renderPass: RenderPass.t, _geometry: Geometry.t) => {
            print_endline ("SolidColor: drawing!");
        };

        let ret = {
            draw: draw,
        };

        ret;
    };
};


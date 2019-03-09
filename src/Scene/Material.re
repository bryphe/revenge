
/* open Revery; */
/* open Revery.Shaders; */
/* open Revery.Shaders.Shader; */

type t = {
    draw: (RenderPass.t, Geometry.t) => unit,
};

module SolidColor = {
    let create: unit => t = () => {

        let draw = (_renderPass: RenderPass.t, geometry: Geometry.t) => {
            let shader = Revenge_Shaders.SolidColorShader.create();
            print_endline ("SolidColor: drawing!");
            Geometry.draw(geometry, shader);
        };

        let ret = {
            draw: draw,
        };

        ret;
    };
};


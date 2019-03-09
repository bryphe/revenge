open Revery;
open Revery.Math;
/* open Revery.Shaders; */
/* open Revery.Shaders.Shader; */

type t = {draw: (RenderPass.t, Geometry.t, Mat4.t) => unit};

module CompiledShader = Revery.Shaders.CompiledShader;

module SolidColor = {
  let create: unit => t =
    () => {
      let draw =
          (renderPass: RenderPass.t, geometry: Geometry.t, transform: Mat4.t) => {
        switch (renderPass) {
        | AmbientLight(pass) =>
          let shader = Revenge_Shaders.SolidColorShader.create();

          CompiledShader.use(shader);
          CompiledShader.setUniformMatrix4fv(shader, "uWorld", transform);

          CompiledShader.setUniformMatrix4fv(
            shader,
            "uView",
            pass.camera.view,
          );

          CompiledShader.setUniformMatrix4fv(
            shader,
            "uProjection",
            pass.camera.projection,
          );

          CompiledShader.setUniform4fv(
            shader,
            "uColor",
            Color.toVec4(pass.color),
          );

          /* print_endline("SolidColor: drawing!"); */
          Geometry.draw(geometry, shader);
        /* | _ => (); */
        };
      };

      let ret = {draw: draw};

      ret;
    };
};

module BasicTexture = {
  let create: Texture.t => t =
    texture => {
      let draw =
          (renderPass: RenderPass.t, geometry: Geometry.t, transform: Mat4.t) => {
        switch (renderPass) {
        | AmbientLight(pass) =>
          let shader = Revenge_Shaders.BasicTextureShader.create();

          CompiledShader.use(shader);
          CompiledShader.setUniformMatrix4fv(shader, "uWorld", transform);

          CompiledShader.setUniformMatrix4fv(
            shader,
            "uView",
            pass.camera.view,
          );

          CompiledShader.setUniformMatrix4fv(
            shader,
            "uProjection",
            pass.camera.projection,
          );
          Texture.bind(texture);

          /* print_endline("Texture: drawing!"); */
          Geometry.draw(geometry, shader);
        /* | _ => (); */
        };
      };

      let ret = {draw: draw};

      ret;
    };
};

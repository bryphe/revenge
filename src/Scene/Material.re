
/* open Revery; */
open Revery.Shaders;
open Revery.Shaders.Shader;

type t = {
    begin: (RenderPass.t) => unit;
    end: (RenderPass.t) => unit;
};

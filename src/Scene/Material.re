
/* open Revery; */
open Revery.Shaders;
open Revery.Shaders.Shader;

type t = {
    shader: CompiledShader.t,
};

let attribute: list(ShaderAttribute.t) = [
  {dataType: ShaderDataType.Vector2, name: "aPosition", channel: Position},
];

let uniform: list(ShaderUniform.t) = [
  {dataType: ShaderDataType.Vector4, name: "uColor", usage: VertexShader},
  {dataType: ShaderDataType.Mat4, name: "uWorld", usage: VertexShader},
  {dataType: ShaderDataType.Mat4, name: "uProjection", usage: VertexShader},
];

let varying: list(ShaderVarying.t) = [
  {
    dataType: ShaderDataType.Vector4,
    name: "vColor",
    precision: ShaderPrecision.Low,
  },
];

let vsShader = {|
   vec4 pos = vec4(aPosition.x, aPosition.y, 1.0, 1.0);
   gl_Position = uProjection * uWorld * pos;
   vColor = uColor;
|};

let fsShader = {|
    gl_FragColor = vColor;
|};

let _create = () => {
  let shader =
    Shader.create(
      ~attributes=attribute,
      ~uniforms=uniform,
      ~varying,
      ~vertexShader=vsShader,
      ~fragmentShader=fsShader,
    );
  Shader.compile(shader);
};

let create = () => {
    let ret: t = {
        shader: _create(),
    };
    ret;
};

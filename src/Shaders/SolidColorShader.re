
/* open Revery; */
open Revery.Shaders;
open Revery.Shaders.Shader;

type t = {
    shader: CompiledShader.t,
};

let attribute: list(ShaderAttribute.t) = [
  {dataType: ShaderDataType.Vector4, name: "aPosition", channel: Position},
];

let uniform: list(ShaderUniform.t) = [
  {dataType: ShaderDataType.Vector4, name: "uColor", usage: VertexShader},
  {dataType: ShaderDataType.Mat4, name: "uWorld", usage: VertexShader},
  {dataType: ShaderDataType.Mat4, name: "uView", usage: VertexShader},
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
   gl_Position = uProjection * uView * uWorld * aPosition;
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

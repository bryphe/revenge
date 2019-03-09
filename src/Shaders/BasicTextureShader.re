/* open Revery; */
open Revery.Shaders;
open Revery.Shaders.Shader;

type t = CompiledShader.t;

let attribute: list(ShaderAttribute.t) = [
  {dataType: ShaderDataType.Vector4, name: "aPosition", channel: Position},
  {
    dataType: ShaderDataType.Vector2,
    name: "aTexCoord",
    channel: TextureCoordinate,
  },
];

let uniform: list(ShaderUniform.t) = [
  {dataType: ShaderDataType.Mat4, name: "uWorld", usage: VertexShader},
  {dataType: ShaderDataType.Mat4, name: "uView", usage: VertexShader},
  {dataType: ShaderDataType.Mat4, name: "uProjection", usage: VertexShader},
  {
    dataType: ShaderDataType.Sampler2D,
    name: "uTexture",
    usage: FragmentShader,
  },
];

let varying: list(ShaderVarying.t) = [
  {
    dataType: ShaderDataType.Vector2,
    name: "vTexCoord",
    precision: ShaderPrecision.Low,
  },
];

let vsShader = {|
   gl_Position = uProjection * uView * uWorld * vec4(aPosition.xyz, 1.0);
   vTexCoord = aTexCoord;
|};

let fsShader = {|
    gl_FragColor = texture2D(uTexture, vTexCoord);
/* gl_FragColor = vec4(1.0,0.0,0.0,1.0); */
/* gl_FragColor = vec4(vTexCoord.x, vTexCoord.y, 0.0, 1.0); */
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

let create = () => _create();


type renderPass =
| AmbientLight;

type drawable = {
    draw: (renderPass) => unit,
    children: list(drawable),
}

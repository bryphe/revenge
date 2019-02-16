
type renderPass =
| AmbientLight;

type drawable = {
    id: int,
    draw: (renderPass) => unit,
    children: list(drawable),
}

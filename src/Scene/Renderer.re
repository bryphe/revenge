open Drawable;

let rec draw = (drawable: Drawable.t) => {
    switch (drawable.inner) {
    | SceneRoot => ()
    | Camera(_) => prerr_endline("Camera!")
    | Mesh(_) => prerr_endline("Mesh!")
    | AmbientLight(_) => prerr_endline("AmbientLight")
    }

    List.iter(draw, drawable.children);
};

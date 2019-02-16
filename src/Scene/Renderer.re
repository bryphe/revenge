open Drawable;

let rec draw = (drawable: Drawable.t) => {
    switch (drawable.inner) {
    | Camera(_) => prerr_endline("Camera!")
    | _ => ();
    }

    List.iter(draw, drawable.children);
};

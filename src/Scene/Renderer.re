

let render = (drawable: Drawable.t) => {
    switch (drawable) {
    | Camera(_) => prerr_endline("Camera!")
    | _ => ();
    }

    List.iter(render, drawable.children);
};

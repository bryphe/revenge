
open Types;

type hostElement = drawable;
type node = drawable;

let insertNode = (~parent: node, ~child: node, ~position as _) => {
    ...parent,
    children: List.concat([child], parent.children),
};

let deleteNode = (~parent: node, ~child: node, ~position as _) => {
    ...parent,
    children: List.filter(c => c.id !== child.id, parent.children),
};

let moveNode = (~parent, ~child as _, ~from as _, ~to_ as _) => {
    parent;
};

let markAsStale = () => {
    /* No-op - we render every frame, anyway */
};

let beginChanges = () => ();
let commitChanges = () => ();

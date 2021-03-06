type hostElement = Drawable.t;
type node = Drawable.t;

let insertNode = (~parent: node, ~child: node, ~position as _) => {
  ...parent,
  children: List.append([child], parent.children),
};

let deleteNode = (~parent: node, ~child: node) => {
  ...parent,
  children:
    List.filter((c: Drawable.t) => c.id != child.id, parent.children),
};

let moveNode = (~parent, ~child as _, ~from as _, ~to_ as _) => {
  parent;
};

let markAsStale = () => ();

let beginChanges = () => ();
let commitChanges = () => ();

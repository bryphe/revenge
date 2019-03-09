type state = {
  rendered: React3d.RenderedElement.t,
  previousElement: React3d.syntheticElement,
};

type t = {
  node: Drawable.t,
  state: option(state),
};

let create = () => {node: Drawable.create(SceneRoot), state: None};

let draw: (t, React3d.syntheticElement, Camera.t) => t =
  ({node, state}, element, camera) => {
    let (newNode, newRendered) =
      switch (state) {
      | None =>
        let updates = React3d.RenderedElement.render(node, element);
        let newNode = React3d.RenderedElement.executeHostViewUpdates(updates);
        let newRendered =
          updates |> React3d.RenderedElement.executePendingEffects;
        (newNode, newRendered);
      | Some(s) =>
        let nextElement =
          React3d.RenderedElement.update(
            ~previousElement=s.previousElement,
            ~renderedElement=s.rendered,
            element,
          )
          |> React3d.RenderedElement.flushPendingUpdates;

        let newNode =
          React3d.RenderedElement.executeHostViewUpdates(nextElement);

        let newRendered =
          nextElement |> React3d.RenderedElement.executePendingEffects;
        (newNode, newRendered);
      /* TODO: Finish up rendering logic here, and test out drawing! */
      };

    Renderer.draw(newNode, camera);

    let ret: t = {
      node: newNode,
      state: Some({rendered: newRendered, previousElement: element}),
    };
    ret;
  };

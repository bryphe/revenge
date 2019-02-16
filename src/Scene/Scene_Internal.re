
type state = {
    rendered: React3d.RenderedElement.t,
    previousElement: React3d.syntheticElement
};

type t = {
    node: Drawable.t,
    state: option(state)
};

let create = () => {
    node: Drawawble.create(SceneRoot),
    state: None,
};

let draw: (t, React.syntheticElement) => t =
    ({node, state}, element) => {
     let (newNode, newRendered) =
         switch(state) {
          | None => 
            let updates = React3d.RenderedElement.render(node, element);
            let newNode = React3d.REnderedElement.executeHostViewUpdates(updates);
            let newRendered = updates |> React3d.RenderedElement.executePendingEffects;
            (newNode, newRendered)
         | Some(s) =>
            let nextElement = React3d.RenderedElement.update(~previousElement=s.previousElement, ~renderedElement=s.rendered, element);
            /* TODO: Finish up rendering logic here, and test out drawing! */
         }
    };

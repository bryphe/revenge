open Revery.Core;

type t('a) = {
    currentState: 'a,
    render: renderFunction('a),
    update: updateFunction('a),
    elapsedTime: float,
    window: Window.t,
}
and renderFunction('a) = (t('a), 'a) => unit
and updateFunction('a) = (t('a), 'a) => 'a;

type options = {
    title: string
};

let defaultOptions: options = {
    title: "My Game"
};

let getElapsedTime = (_game: t('a)) => 0.;

let getDimensions = (game) => {
    Window.getSize(game.window);
};

let getAspectRatio = (game) => {
    let d = getDimensions(game);
    float_of_int(d.width) /. float_of_int(d.height);
};

let start = (~update, ~render, ~options=defaultOptions, initialState) => {
    let init = app => {
        let _update = update;
        let _render = render;
        print_endline ("hello: " ++ options.title);

        let window = App.createWindow(app, options.title);

        let _game: t('a) = {
            currentState: initialState,
            render,
            update,
            elapsedTime: 0.,
            window
        };

        Window.setRenderCallback(window, () => {
            print_endline ("testing");
        });
    }

    App.start(init);
};

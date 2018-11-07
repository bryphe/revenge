
type t('a) = {
    init: initFunction('a),
    render: renderFunction('a),
    update: updateFunction('a),
    elapsedTime: float
}
and initFunction('a) = t('a) => 'a
and renderFunction('a) = (t('a), 'a) => unit
and updateFunction('a) = (t('a), 'a) => 'a;

type startOptions = {
    title: string
};

let getElapsedTime = (_game: t('a)) => 0.;

let start = (~init, ~update, ~render, startOptions) => {
    let _init = init;
    let _update = update;
    let _render = render;
    print_endline ("hello: " ++ startOptions.title);
};

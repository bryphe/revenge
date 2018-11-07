
type t('a) = {
    init: initFunction('a),
    render: renderFunction('a),
    update: updateFunction('a),
    elapsedTime: float
}
and initFunction('a) = t('a) => 'a
and renderFunction('a) = (t('a), 'a) => unit
and updateFunction('a) = (t('a), 'a) => 'a;

let getElapsedTime = (_game: t('a)) => 0.;

let start = (~name: string, ~_init, ~_update, ~_render, ()) => {
    print_endline ("hello: " ++ name);
};

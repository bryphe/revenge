type t('a);

type initFunction('a) = t('a) => 'a;
type renderFunction('a) = (t('a), 'a) => unit;
type updateFunction('a) = (t('a), 'a) => 'a;

let getElapsedTime: t('a) => float;

let start: (~name: string, ~init: initFunction('a), ~update: updateFunction('a), ~render: renderFunction('a), unit) => unit;

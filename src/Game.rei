type t('a);

type initFunction('a) = t('a) => 'a;
type renderFunction('a) = (t('a), 'a) => unit;
type updateFunction('a) = (t('a), 'a) => 'a;

type startOptions = {
    title: string
};

let getElapsedTime: t('a) => float;

let start: (~init: initFunction('a), ~update: updateFunction('a), ~render: renderFunction('a), startOptions) => unit;

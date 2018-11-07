type t('a);

type renderFunction('a) = (t('a), 'a) => unit;
type updateFunction('a) = (t('a), 'a) => 'a;

type options = {
    title: string
};

let getElapsedTime: t('a) => float;

let start: (~update: updateFunction('a), ~render: renderFunction('a), ~options: options, 'a) => unit;

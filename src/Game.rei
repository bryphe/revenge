open Revery.Core;

type t('a);

type renderFunction('a) = (t('a), 'a) => unit;
type updateFunction('a) = (t('a), 'a) => 'a;

type options = {
    title: string
};

let defaultOptions: options;

let getElapsedTime: t('a) => float;

let getDimensions: t('a) => Window.windowSize;
let getAspectRatio: t('a) => float;

let start: (~update: updateFunction('a), ~render: renderFunction('a), ~options: options=?, 'a) => unit;

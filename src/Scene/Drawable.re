type innerDrawable =
  | Camera(Camera.t);

type t = {
id: int,
children: list(t),
inner: innerDrawable,
};

let _currentId = ref(0);

let create = (inner) => {
let id = _currentId^;
_currentId := _currentId^ + 1;

let ret: t = {inner, id, children: []};
ret;
};

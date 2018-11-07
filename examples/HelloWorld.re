open Revenge;

let scene = Revenge.Scene.create();

let init = _game => {
  let initialState = 0.;
  initialState
};

let render = (_game, _state) => {
    let camera = Graphics.Camera.perspective();

    Scene.render(scene, camera
/*
        <group>
            <ambientLight />
            <plane />
            <box />
            <pointLight />
        </group>
*/
    );
};

let update = (game, _state) => {
    Game.getElapsedTime(game);
};

Game.start(~init, ~render, ~update, {
    title: "My Game"
});

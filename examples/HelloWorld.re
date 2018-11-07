open Revenge;

let scene = Revenge.Scene.create();

let initialState = 0.;

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

Game.start(~render, ~update, initialState);

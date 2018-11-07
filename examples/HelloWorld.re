open Revenge;

let scene = Revenge.Scene.create();

let init = game => {
  let initialState = 0.;
  initialState
};

let render = (game, state) => {
    let camera = Graphics.Camera.perspective();

    Graphics.Scene.render(scene, camera, () => {
        <group>
            <ambientLight />
            <plane />
            <box />
            <pointLight />
        </group>
    });
};

let update = (game, state) => {
    Game.getElapsedTime(game);
};

Game.start(~name="My Game", init, render, update);

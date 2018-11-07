open Reglm;
open Revenge;

let scene = Revenge.Scene.create();

let initialState = 0.;

let render = (game, _state) => {

    let aspectRatio = Game.getAspectRatio(game);
    let camera = Graphics.Camera.perspective(~aspectRatio, 
    Vec3.create(0., 2., 8.),
    Vec3.zero(),
    Vec3.create(0., 1., 0.)
    );

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

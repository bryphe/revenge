open Reglfw;
open Reglfw.Glfw;

type t = {
    texture: Glfw.texture,
}

let ofImage = (img: Image.t) => {
    let texture = glCreateTexture();
    glBindTexture(GL_TEXTURE_2D, texture);

      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  let pixels = Image.getPixels(img);
  let dimensions = Image.getDimensions(img);

print_endline(
    "- width: "
    ++ string_of_int(dimensions.width)
    ++ " - height: "
    ++ string_of_int(dimensions.height),
  );
  
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, GL_RGBA, GL_UNSIGNED_BYTE, pixels);

  let ret: t = {
    texture: texture
  }

  ret;
}

let bind = (tex: t) => {
    glBindTexture(GL_TEXTURE_2D, tex.texture);
};

# Cub3D


Welcome to Cub3d!

Cub3d is a 42 project that aims to create a simple raycasting engine. It simulates a 3D environment using 2D graphics, inspired by the classic game Wolfenstein 3D. The project utilizes the MiniLibX library to create a graphical display and handles various elements such as textures, sprites, and collision detection.

## Features

The Cub3d project includes the following features:

- Raycasting engine to render a 3D-like environment.
- Textured walls and floor.
- Support for multiple wall textures.
- Sprite rendering and collision detection.
- Player movement and rotation.
- Basic error handling and map validation.

## Bonus Features

In addition to the core functionalities, the Cub3d project also implements the following bonus features:

- Wall collisions: The player cannot pass through walls or objects in the environment.
- Minimap system: A 2D top-down view of the map, displaying the player's position and orientation.
- Doors: Doors that can open and close, allowing access to different areas of the map.
- Animated sprites: Sprites with animations, adding movement and life to the game world.
- Mouse rotation: Rotate the point of view with the mouse, providing a more immersive experience.

. Run the Cub3d executable with a valid map file:
   ```
   ./cub3D path/to/map.cub
   ```

   Replace `path/to/map.cub` with the path to your own map file.

5. Explore the 3D environment using the arrow keys for movement and rotation. Use the mouse to rotate the point of view.

6. Press `ESC` or close the window to exit the program.

## Map Configuration

The Cub3d map is defined in a `.cub` file according to the following rules:

- The map must have a `.cub` extension.
- The file must include the following elements:
  - North texture: `NO <path_to_texture>`
  - South texture: `SO <path_to_texture>`
  - West texture: `WE <path_to_texture>`
  - East texture: `EA <path_to_texture>`
  - Sprite texture: `S <path_to_texture>`
  - Floor color: `F <R,G,B>` 
  - Ceiling color: `C <R,G,B>`
  - Map layout: consisting of 0s (empty space), 1s (walls) D(Door) , N/S/E/W (player start position and orientation)
- The map must be surrounded by walls (1s).

## Controls

- `W`/`A`/`S`/`D`: Move forward/left/backward/right.
- `←`/`→`: Rotate the camera left/right.
- Mouse movement: Rotate the point of view.
- `ESC`: Exit the program.

# cub3d Project Readme

## Overview
cub3d is a graphic design project aimed at improving skills in areas such as windows, colors, events, and shape filling while utilizing C programming language and basic algorithms. The project serves as a playground to explore practical applications of mathematics without requiring an in-depth understanding of specific mathematical concepts. It involves using the miniLibX library to create a 3D maze rendering program.

## Features
- Smooth window management including switching windows and minimizing.
- Displaying different wall textures based on the wall's facing direction.
- Ability to set floor and ceiling colors independently.
- Controlling the viewpoint within the maze using arrow keys (left and right) for looking around and WASD keys for movement.
- Clean program exit on pressing ESC or closing the window.
- Parsing scene description file (.cub) to render the maze with specified textures, colors, and player start position.

## Constraints
- Utilization of miniLibX library for graphic rendering.
- Scene description file (.cub) as the first argument with specific formatting rules.
- Map composed of characters: 0 for an empty space, 1 for a wall, and N/S/E/W for player's start position and orientation.
- Map must be surrounded by walls.
- Specific order and formatting for elements in the scene description file.
- Proper error handling for misconfigurations in the file.

## Getting Started
1. Ensure miniLibX library is available on your system or include it from its sources.
2. Compile the cub3d program.
3. Run the program with a valid scene description file as the first argument.

## Example Scene Description
```
NO ./path_to_the_north_texture  
SO ./path_to_the_south_texture  
WE ./path_to_the_west_texture  
EA ./path_to_the_east_texture  
F 220,100,0  
C 225,30,0  
1111111111111111111111111  
1000000000110000000000001  
1011000001110000000000001  
1001000000000000000000001  
111111111011000001110000000000001  
100000000011000001110111111111111  
11110111111111011100000010001  
11110111111111011101010010001  
11000000110101011100000010001  
10000000000000001100000010001  
10000000000000001101010010001  
11000001110101011111011110N0111  
11110111 1110101 101111010001  
11111111 1111111 111111111111
```

## Error Handling
The program exits properly and returns "Error\n" followed by an explicit error message in case of any misconfiguration encountered in the scene description file.

## Contributors
- [Akram GUEDIRI](https://github.com/akramguediri)
- [Oreste Tuyishimire](https://github.com/otuyishi)

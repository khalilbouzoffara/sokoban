# Sokoban
## Web Development Project Using c++ & SFML


***Sokoban*** is a [puzzle video game](https://en.wikipedia.org/wiki/Puzzle_video_game) genre in which the player pushes crates or boxes around in a [warehouse](https://en.wikipedia.org/wiki/Warehouse), trying to get them to storage locations.

As a gamer, I enjoyed creating my first game ever while also learning about the intricacies of object oriented programming and general-purpose programming language C++!
The Application contains:
- The option to create the desired level.
- The option to to choose from the pre-made levels.
- Présentation de l’équipe de développement.
- A page to understand the rules of the game/see the buttons.
- A simple attractive interface.
- The code is written with extensibility in mind.

## Classes

### MainMenu
 It represents the Main Menu of the game:
### LvlMenu
 The page to choose the level you wanna play
### Cell
 This class lets us create the smallest unit in the game which contains:
- Blocks(mur) = '#'
- Rabi3(Player) = 'J'
- Empty Box = '.'
- Destination = 'd'
- Box = 'b'
- Box in Destination = 'B'
### Help
This class shows the buttons of the game.
### Game
This class uses all the other classes to create an instance of the game as an object.
### Player
This class lets us know the coordinates of the player in the map and thus be able to manipulate his movement.
### Level
All levels are written in a .txt file using the notations presented in class Cell. This class lets us choose the appropriate level and show the corresponding map of it.
### Help
This page shows the rules of the game.


## Technology used

Sokoban uses a number of open source projects to work properly:

- C++ - The Programming Language of the game.
- SFML - The library needed for the graphical user interface of the game.
- Codeblocks - the IDE Used in the development of the game.
- Git - Version control system used throughout the development of the game.
## Future Work
- Add More avatars the player can choose from
- Add More Levels
- Add an in-game currency as an entertaining way for the player to unlock more levels/avatars

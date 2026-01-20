# Dungeon-Escape

Dungeon Escape game

## Game report:

The game is made by dividing the classes into multiple header files:
- Dungeon.hpp
- Player.hpp
- Enemy.hpp
- Room.hpp

The code to run the game is in the main.cpp file which makes a dungeon object and uses its method to run the game.

There are 20 rooms in total which are divided into treasure, challenge and enemy rooms.
The player has to go through all of them using command terminal. The rooms are connected with each other through a linked list.

At the same time a stack is used track the movement and path of the player.

The queue is also used to keep track of multiple enemies in a room and allow the player to fight all of them.

A dynamic array is used to tracker player’s inventory.

The game is structured with enemies that have scaling but at the same time the player can also get buffs(armor, healing potions and hp/atk boost). The player has to them beat enemies and access rooms to gain items, get stronger and beat the final boss.

The game also has simple graphics, which are just array of strings to display the current room.

The process of making the game was overall easy, however mapping the linked list of each room and assigning each room a content type with features (e.g treasure ,enemies or challenge) was time draining. Moreover dealing with memory allocation was difficult and required attentiveness to prevent memory leaks.

The code is overall fairly optimized although it could have been better. Using enum types and switch case instead of using if statements would have been more efficient for the assignments of room. At the same time, using more classes like a different class for handling items and a different class for armor would have allowed for versatility in expanding the game.

## User Manual:

Overall, playing the game is simple. Using the map all the player needs to do is get all the buffs as soon as possible. (like healing potions, sword, hp boost, armor etc). Then he can go fight the main boss and win to gain a key, which can be used to escape the dungeon.

The game is simple on the terminal, showing all prompts to assist the user.

The difficult of the game is overall easy if you stick with the strategy of getting the player as strong as possible quickly.

To play the game the main.cpp file is to be run.

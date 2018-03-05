Tic Tac Toe in C++ with embedded Lua AI
by Noah Deibert
CSCI400
3/4/2018

To compile: Assuming you have Lua and some C compiler like MinGW installed, simply 
change Makefile and edit path to lib and include directories, and make. This program is 
using Lua version 5.1. Using another version may require using different libraries and 
additional changes to the Makefile.

To run: Run as compiled exe with lua script as argument. ex: "./TicTacToe.exe mediumAI.lua"

While this program is mostly C++, it shows the usefulness of embedding Lua. As is typical 
with many video games, users can create their own lua scripts and have them run inside another 
program. This version of Tic Tac Toe allows you to create your own AI that can get the game board 
as a string and do its own calculations and methods, finally returning to C++ with a position on 
the game board to move. When creating your own AI, you should be sure to make the AI properly, as 
a bad AI may continuously choose an invalid option, creating an infinite loop.

BMI Calculadora in Lua
by Han Nguyen
CSCI400
3/4/2018

To compile: Nothing, just install Lua.
To run: Run in terminal with Lua. ex: "lua BMICalculadora.lua"

This program explores some of the basics of programming with simple standard input and output, 
along with some math calculations and some if/then/else statements.
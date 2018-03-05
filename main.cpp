
// Noah Deibert

extern "C" {
    #include "include/lua.h"
    #include "include/lauxlib.h"
    #include "include/lualib.h"
}
#include "stdio.h"
#include <iostream>
#include <string>

// Lua state and filename
lua_State * L;
std::string filename;

// other globals
std::string board = "123456789";
int whoseTurn = 1; // human
bool isGameRunning = true;
int winner = 0;
int numTurns = 0;
int cpuChoice = -1;
bool isLuaSeeded = false;

// Lua functions to get board, check for random seed, and move cpu
int getBoard(lua_State * L) {
    lua_pushstring(L, board.c_str());
    return 1;
}

int isSeeded(lua_State * L) {
    lua_pushboolean(L, isLuaSeeded);
    return 1;
}

int seed(lua_State * L) {
    isLuaSeeded = true;
    return 1;
}
int cpuMove(lua_State * L) {
    cpuChoice = lua_tonumber(L, 1);
    return 1;
}

// Initialize Lua
void initializeLua() {
    L = luaL_newstate();
    luaL_openlibs(L);
    lua_register(L, "getBoard", getBoard);
    lua_register(L, "isSeeded", isSeeded);
    lua_register(L, "seed", seed);
    lua_register(L, "cpuMove", cpuMove);
}

// Run the lua script
void doLuaScript(const char * luaFile) {
    int s = luaL_loadfile(L, luaFile);
    if (!s) {
        s = lua_pcall(L, 0, LUA_MULTRET, 0);
    }
    if (s) {
        printf("Error: %s \n", lua_tostring(L, -1));
        lua_pop(L, 1);
    }
    //lua_close(L);
}

// Other tic tac toe functions
void printBoard();
bool isValid(int position);
void playGame();
void doTurn();
void swapTurns();
void doMove(int position);
void checkEndConditions();
void announceWinner();
void winGame();
void tieGame();

// Main
// Init Lua, run game, close Lua
int main(int argc, char ** argv) {
    
    filename = argv[1];
    initializeLua();
    //doLuaScript(filename.c_str());

    playGame();
    lua_close(L);
    system("pause");
    return 0;

}

// Other tic tac toe functions
void playGame() {
    while (isGameRunning) {
        doTurn();
        swapTurns();
    }
    announceWinner();
}

void winGame() {
    winner = whoseTurn;
    isGameRunning = false;
}

void tieGame() {
    isGameRunning = false;
    winner = 0;
}

void checkEndConditions() {
    char c = 'X';
    if (whoseTurn == 2) { c = 'O'; }

    // going across
    if (c == board.at(0) && c == board.at(1) && c == board.at(2)) { winGame(); }
    if (c == board.at(3) && c == board.at(4) && c == board.at(5)) { winGame(); }
    if (c == board.at(6) && c == board.at(7) && c == board.at(8)) { winGame(); }
    // going vertical
    if (c == board.at(0) && c == board.at(3) && c == board.at(6)) { winGame(); }
    if (c == board.at(1) && c == board.at(4) && c == board.at(7)) { winGame(); }
    if (c == board.at(2) && c == board.at(5) && c == board.at(8)) { winGame(); }
    // going diagonal
    if (c == board.at(0) && c == board.at(4) && c == board.at(8)) { winGame(); }
    if (c == board.at(2) && c == board.at(4) && c == board.at(6)) { winGame(); }

    if (numTurns >= 9) {
        tieGame();
    }
}

void doTurn() {
    if (whoseTurn == 1) { // humans turn
        int position = -1;
        printBoard();
        while (!isValid(position)) {
            std::cout << "Human's turn! Enter a position (1-9) of an available space: ";
            std::string input;
            std::getline(std::cin, input);
            position = std::atoi(input.c_str());
        }
        doMove(position - 1);
    } else if (whoseTurn == 2) { // cpus turn
        cpuChoice = -1;
        while (!isValid(cpuChoice)) {
            doLuaScript(filename.c_str());
        }
        doMove(cpuChoice - 1);
    }

    numTurns++;
    checkEndConditions();
}

void doMove(int position) {
    char newChar = '!';
    if (whoseTurn == 1) { newChar = 'X'; }
    else if (whoseTurn == 2) { newChar = 'O'; }
    board.at(position) = newChar;
}


void swapTurns() {
    if (whoseTurn == 1) { // humans turn
        whoseTurn = 2;
    } else if (whoseTurn == 2) { // cpus turn
        whoseTurn = 1;
    }
}


void printBoard() {
    std::cout << "+---+---+---+\n";
    std::cout << "| " + board.substr(0, 1) + " | " + board.substr(1, 1) + " | " + board.substr(2, 1) + " |\n";
    std::cout << "+---+---+---+\n";
    std::cout << "| " + board.substr(3, 1) + " | " + board.substr(4, 1) + " | " + board.substr(5, 1) + " |\n";
    std::cout << "+---+---+---+\n";
    std::cout << "| " + board.substr(6, 1) + " | " + board.substr(7, 1) + " | " + board.substr(8, 1) + " |\n";
    std::cout << "+---+---+---+\n";
}

bool isValid(int position) {
    if (position < 1 || position > board.length()) {
        return false;
    }
    if (board.at(position - 1) == 'X' || board.at(position - 1) == 'O') {
        if (whoseTurn == 1) { std::cout << "INVALID MOVE\n"; }
        return false;
    }
    return true;
}

void announceWinner() {
    switch (winner) {
        case 1:
            std::cout << "******************\n";
            std::cout << "* HUMAN HAS WON! *\n";
            std::cout << "******************\n";
            break;
        case 2:
            std::cout << "******************\n";
            std::cout << "*  CPU HAS WON!  *\n";
            std::cout << "******************\n";
            break;
        default:
            std::cout << "*****************\n";
            std::cout << "*  IT'S A TIE!  *\n";
            std::cout << "*****************\n";
            break;
    }
    printBoard();
}
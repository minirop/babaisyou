#pragma once

#include <Gamebuino-Meta.h>

#define EMPTY  0
#define W_BABA 1
#define W_FLAG 2
#define W_ROCK 3
#define W_IS   4
#define W_WIN  5
#define W_PUSH 6
#define W_WALL 7
#define BABA   8
#define FLAG   9
#define ROCK   10
#define WALL   11
#define W_STOP 12
#define W_YOU  13
#define W_GOOP 14
#define GOOP   15
#define W_SINK 16
#define W_LAVA 17
#define LAVA   18
#define W_KILL 19
#define TILE_COUNT 20

#define IS_YOU 1
#define IS_WIN 2
#define IS_STOP 4
#define IS_PUSH 8
#define IS_SINK 16
#define IS_KILL 32

#define SCREEN_WIDTH 160
#define TILE_SIZE 12

extern uint8_t CURRENT_SCREEN;
#define MENU_SCREEN 0
#define GAME_SCREEN 1
#define VICTORY_SCREEN 2

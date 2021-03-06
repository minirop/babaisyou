#pragma once

#include <Gamebuino-Meta.h>

enum {
  EMPTY,
  W_BABA,
  W_FLAG,
  W_ROCK,
  W_IS,
  W_WIN,
  W_PUSH,
  W_WALL,
  BABA,
  FLAG,
  ROCK,
  WALL,
  W_STOP,
  W_YOU,
  W_GOOP,
  GOOP,
  W_SINK,
  W_LAVA,
  LAVA,
  W_KILL,
  W_LOVE,
  LOVE,
  W_SWAP,
  W_EMPTY,
  TILE_COUNT
};

#define IS_YOU 1
#define IS_WIN 2
#define IS_STOP 4
#define IS_PUSH 8
#define IS_SINK 16
#define IS_KILL 32
#define IS_SWAP 64

#define SCREEN_WIDTH 160
#define TILE_SIZE 12

#define ROW_SIZE (16*160*2)
#define ROWS_COUNT (128/16)

extern uint8_t CURRENT_SCREEN;
#define MENU_SCREEN 0
#define GAME_SCREEN 1
#define LEVEL_SELECT_SCREEN 2
#define EDITOR_SCREEN 3

#define GAME_SLICES 10
#define MAP_WIDTH 13
#define MAP_FULL_SIZE (MAP_WIDTH * GAME_SLICES)

void gotoScreen(uint8_t screen);

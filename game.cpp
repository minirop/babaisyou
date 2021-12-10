#include "game.h"
#include "defines.h"
#include "tileset.h"
#include "draw.h"

constexpr uint8_t slices = 10;
constexpr uint8_t map_width = 13;
constexpr uint8_t MAP_FULL_SIZE = map_width * slices;

#include "levels.h"

uint8_t underlevel[MAP_FULL_SIZE];

uint8_t level[MAP_FULL_SIZE] = {};
uint8_t current_level = 0;

uint8_t rules[W_YOU + 1];
void updateRules();
bool isSubject(uint8_t tile);
bool isStatus(uint8_t tile);
uint8_t getStatus(uint8_t tile);
void updateGame();

void moveDown();
void moveUp();
void moveLeft();
void moveRight();
uint8_t getSubject(uint8_t tile);
bool isPush(uint8_t tile);
bool isStop(uint8_t tile);
bool isYou(uint8_t tile);
bool isWin(uint8_t tile);
void moveImpl(uint8_t i, int8_t delta, uint8_t min, uint8_t max);
void convertTile(uint8_t from, uint8_t to);

void initLevel(uint8_t id)
{
  for (uint8_t i = 0; i < MAP_FULL_SIZE; i++)
  {
    level[i] = levels[id][i];
  }
}

void updateGame()
{
  if (gb.buttons.pressed(BUTTON_DOWN))
  {
    moveDown();
  }
  else if (gb.buttons.pressed(BUTTON_UP))
  {
    moveUp();
  }
  else if (gb.buttons.pressed(BUTTON_LEFT))
  {
    moveLeft();
  }
  else if (gb.buttons.pressed(BUTTON_RIGHT))
  {
    moveRight();
  }
  else if (gb.buttons.pressed(BUTTON_B))
  {
    startGame(current_level);
    return;
  }
  else
  {
    return;
  }
  
  updateRules();

  for (int i = 0; i < MAP_FULL_SIZE; i++)
  {
    if (isYou(level[i]) && isWin(underlevel[i]))
    {
      current_level++;
      if (current_level == level_count)
      {
        CURRENT_SCREEN = MENU_SCREEN;
      }
      else
      {
        startGame(current_level);
      }
    }
  }
}

void initRules()
{
  rules[EMPTY]  = 0;
  rules[W_BABA] = IS_PUSH;
  rules[W_FLAG] = IS_PUSH;
  rules[W_ROCK] = IS_PUSH;
  rules[W_IS]   = IS_PUSH;
  rules[W_WIN]  = IS_PUSH;
  rules[W_PUSH] = IS_PUSH;
  rules[W_WALL] = IS_PUSH;
  rules[BABA]   = 0;
  rules[FLAG]   = 0;
  rules[ROCK]   = 0;
  rules[WALL]   = 0;
  rules[W_STOP] = IS_PUSH;
  rules[W_YOU]  = IS_PUSH;

  for (uint8_t i = 0; i < MAP_FULL_SIZE; i++)
  {
    underlevel[i] = EMPTY;
  }
}

void updateRules()
{
  rules[BABA] = 0;
  rules[FLAG] = 0;
  rules[ROCK] = 0;
  rules[WALL] = 0;

  for (int i = 0; i < MAP_FULL_SIZE; i++)
  {
    if (level[i] == W_IS)
    {
      uint8_t x = i % map_width;
      uint8_t y = i / map_width;

      if (x > 0 && x < map_width - 1)
      {
        uint8_t subject = level[i - 1];
        uint8_t status = level[i + 1];
        if (isSubject(subject))
        {
          if (isStatus(status))
          {
            rules[ getSubject(subject) ] |= getStatus(status);
          }
          else if (isSubject(status))
          {
            convertTile(getSubject(subject), getSubject(status));
          }
        }
      }

      if (y > 0 && y < slices - 1)
      {
        uint8_t subject = level[i - map_width];
        uint8_t status = level[i + map_width];
        if (isSubject(subject))
        {
          if (isStatus(status))
          {
            rules[ getSubject(subject) ] |= getStatus(status);
          }
          else if (isSubject(status))
          {
            convertTile(getSubject(subject), getSubject(status));
          }
        }
      }
    }
  }
}

bool isSubject(uint8_t tile)
{
  switch (tile)
  {
    case W_BABA:
    case W_FLAG:
    case W_ROCK:
    case W_WALL:
      return true;
  }
  return false;
}

bool isStatus(uint8_t tile)
{
  switch (tile)
  {
    case W_PUSH:
    case W_STOP:
    case W_WIN:
    case W_YOU:
      return true;
  }
  return false;
}

uint8_t getStatus(uint8_t tile)
{
  switch (tile)
  {
    case W_PUSH: return IS_PUSH;
    case W_STOP: return IS_STOP;
    case W_WIN:  return IS_WIN;
    case W_YOU:  return IS_YOU;
  }

  return 0;
}

uint8_t getSubject(uint8_t tile)
{
  switch (tile)
  {
    case W_BABA: return BABA;
    case W_WALL: return WALL;
    case W_ROCK: return ROCK;
    case W_FLAG: return FLAG;
  }

  return 0;
}

void moveDown()
{
  for (int8_t i = map_width * (slices - 1); i >= 0; i--)
  {
    if (isYou(level[i]))
    {
      moveImpl(i, map_width, 0, MAP_FULL_SIZE);
    }
  }
}

void moveUp()
{
  for (uint8_t i = map_width; i < MAP_FULL_SIZE; i++)
  {
    if (isYou(level[i]))
    {
      moveImpl(i, -map_width, 0, MAP_FULL_SIZE);
    }
  }
}

void moveLeft()
{
  for (uint8_t i = 0; i < MAP_FULL_SIZE; i++)
  {
    if (isYou(level[i]) && (i % map_width) > 0)
    {
      uint8_t row_start = (i / map_width) * map_width;
      moveImpl(i, -1, row_start, row_start + map_width);
    }
  }
}

void moveRight()
{
  for (uint8_t k = 0; k < MAP_FULL_SIZE; k++)
  {
    uint8_t i = MAP_FULL_SIZE - k - 1;
    if (isYou(level[i]) && (i % map_width) < map_width - 1)
    {
      uint8_t row_start = (i / map_width) * map_width;
      moveImpl(i, 1, row_start, row_start + map_width);
    }
  }
}

void moveImpl(uint8_t i, int8_t delta, uint8_t min, uint8_t max)
{
  uint8_t firstEmpty = 0xff;
  for (uint8_t yy = i + delta; yy >= min && yy < max; yy += delta)
  {
    if (isStop(level[yy]))
    {
      break;
    }

    if (!isPush(level[yy]) && !isYou(level[yy]))
    {
      firstEmpty = yy;
      break;
    }
  }

  if (firstEmpty < 0xff)
  {
    for (uint8_t c = firstEmpty; c != i; c -= delta)
    {
      if (!isPush(level[c]) && !isYou(level[c]))
      {
        underlevel[c] = level[c];
      }
      level[c] = level[c - delta];
      level[c - delta] = underlevel[c - delta];
      underlevel[c - delta] = EMPTY;
    }
  }
}

bool isPush(uint8_t tile)
{
  return (rules[tile] & IS_PUSH);
}

bool isStop(uint8_t tile)
{
  return (rules[tile] & IS_STOP);
}

bool isYou(uint8_t tile)
{
  return (rules[tile] & IS_YOU);
}

bool isWin(uint8_t tile)
{
  return (rules[tile] & IS_WIN);
}

#define SLICE_HEIGHT 12

void startGame(uint8_t id)
{
  current_level = id;
  initLevel(id);

  initRules();
  updateRules();
}

void gameTick()
{
  updateGame();

  for (uint8_t sliceIndex = 0; sliceIndex < slices; sliceIndex++)
  {
    uint16_t * buffer = sliceIndex % 2 == 0 ? buffer1 : buffer2;
    
    for (int16_t s = 0; s < map_width;s++)
    {
      const uint16_t * sprBegin = &tileset[ level[sliceIndex * map_width + s] * TILE_SIZE * TILE_SIZE ];
      for (int y = 0; y < TILE_SIZE; y++)
      {
        memcpy(&buffer[SCREEN_WIDTH * y + s * TILE_SIZE], sprBegin + y * TILE_SIZE, TILE_SIZE*2);
      }
    }
    
    if (sliceIndex != 0) waitForPreviousDraw();
    
    drawScreenSlice(sliceIndex * SLICE_HEIGHT, SLICE_HEIGHT, buffer);
  }

  uint16_t * buffer_black = slices % 2 == 0 ? buffer1 : buffer2;
  memset(buffer_black, 0x00, SCREEN_WIDTH * 16);
  waitForPreviousDraw();

  drawScreenSlice(120, 8, buffer_black);
  waitForPreviousDraw();
}

void convertTile(uint8_t from, uint8_t to)
{
  for (uint8_t k = 0; k < MAP_FULL_SIZE; k++)
  {
    if (level[k] == from)
    {
      level[k] = to;
    }
  }
}
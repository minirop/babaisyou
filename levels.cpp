#include "levels.h"
#include "defines.h"

const uint8_t level1[MAP_FULL_SIZE] = {
EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, 
EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, 
EMPTY, EMPTY, W_FLAG,W_IS,  W_WIN, EMPTY, EMPTY, EMPTY, W_WALL,W_IS,  W_STOP,EMPTY, EMPTY, 
EMPTY, EMPTY, WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  EMPTY, EMPTY, 
EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, ROCK,  EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, 
EMPTY, EMPTY, BABA,  EMPTY, EMPTY, EMPTY, ROCK,  EMPTY, EMPTY, EMPTY, FLAG,  EMPTY, EMPTY, 
EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, ROCK,  EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, 
EMPTY, EMPTY, WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  EMPTY, EMPTY, 
EMPTY, EMPTY, W_BABA,W_IS,  W_YOU, EMPTY, EMPTY, EMPTY, W_ROCK,W_IS,  W_PUSH,EMPTY, EMPTY, 
EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, 
};

const uint8_t level2[MAP_FULL_SIZE] = {
EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  
EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, WALL,  EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, WALL,  
EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, WALL,  EMPTY, W_IS,  EMPTY, EMPTY, EMPTY, EMPTY, WALL,  
WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  EMPTY, EMPTY, EMPTY, EMPTY, W_WIN, EMPTY, WALL,  
WALL,  EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, WALL,  
WALL,  EMPTY, W_FLAG,EMPTY, EMPTY, EMPTY, FLAG,  EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, WALL,  
WALL,  EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BABA,  EMPTY, EMPTY, WALL,  
WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  
EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, 
EMPTY, EMPTY, W_BABA,W_IS,  W_YOU, EMPTY, EMPTY, EMPTY, W_WALL,W_IS,  W_STOP,EMPTY, EMPTY, 
};

const uint8_t level3[MAP_FULL_SIZE] = {
EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, 
EMPTY, W_BABA,EMPTY, EMPTY, EMPTY, EMPTY, W_FLAG,WALL,  WALL,  WALL,  WALL,  WALL,  EMPTY, 
EMPTY, W_IS,  EMPTY, EMPTY, EMPTY, EMPTY, W_IS,  WALL,  EMPTY, EMPTY, EMPTY, WALL,  EMPTY, 
EMPTY, W_YOU, EMPTY, EMPTY, EMPTY, EMPTY, W_WIN, WALL,  EMPTY, FLAG,  EMPTY, WALL,  EMPTY, 
EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, WALL,  EMPTY, EMPTY, EMPTY, WALL,  EMPTY, 
EMPTY, WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  EMPTY, 
EMPTY, WALL,  EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, WALL,  EMPTY, 
EMPTY, WALL,  EMPTY, W_WALL,W_IS,  W_STOP,EMPTY, EMPTY, BABA,  EMPTY, EMPTY, WALL,  EMPTY, 
EMPTY, WALL,  EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, WALL,  EMPTY, 
EMPTY, WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  EMPTY, 
};

const uint8_t level4[MAP_FULL_SIZE] = {
W_BABA,WALL,  EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, WALL,  W_GOOP,
W_IS,  WALL,  EMPTY, EMPTY, EMPTY, W_ROCK,W_IS,  W_PUSH,EMPTY, EMPTY, EMPTY, WALL,  W_IS,  
W_YOU, WALL,  EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, WALL,  W_SINK,
EMPTY, WALL,  EMPTY, BABA,  EMPTY, EMPTY, EMPTY, EMPTY, ROCK,  ROCK,  EMPTY, WALL,  EMPTY, 
EMPTY, WALL,  EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, WALL,  EMPTY, 
EMPTY, WALL,  WALL,  WALL,  WALL,  GOOP,  GOOP,  GOOP,  WALL,  WALL,  WALL,  WALL,  EMPTY, 
EMPTY, WALL,  EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, WALL,  EMPTY, 
W_WALL,WALL,  GOOP,  GOOP,  GOOP,  EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, WALL,  EMPTY, 
W_IS,  WALL,  GOOP,  GOOP,  GOOP,  EMPTY, EMPTY, W_FLAG,W_IS,  W_WIN, EMPTY, WALL,  EMPTY, 
W_STOP,WALL,  FLAG,  GOOP,  GOOP,  EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, WALL,  EMPTY, 
};

const uint8_t level5[MAP_FULL_SIZE] = {
EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, 
W_BABA,EMPTY, EMPTY, ROCK,  EMPTY, EMPTY, EMPTY, ROCK,  EMPTY, EMPTY, EMPTY, EMPTY, W_WALL,
W_IS,  EMPTY, W_ROCK,W_IS,  W_PUSH,EMPTY, EMPTY, EMPTY, LAVA,  LAVA,  LAVA,  EMPTY, W_IS,  
W_YOU, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, LAVA,  FLAG,  LAVA,  EMPTY, W_STOP,
EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, LAVA,  LAVA,  LAVA,  EMPTY, EMPTY, 
EMPTY, WALL,  WALL,  WALL,  WALL,  WALL,  EMPTY, EMPTY, EMPTY, ROCK,  EMPTY, EMPTY, EMPTY, 
EMPTY, WALL,  EMPTY, BABA,  EMPTY, ROCK,  EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, W_FLAG,
EMPTY, WALL,  WALL,  WALL,  WALL,  WALL,  EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, W_IS,  
EMPTY, EMPTY, EMPTY, EMPTY, ROCK,  EMPTY, EMPTY, EMPTY, EMPTY, ROCK,  EMPTY, EMPTY, W_WIN, 
EMPTY, W_LAVA,W_IS,  W_KILL,EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, 
};

const uint8_t level6[MAP_FULL_SIZE] = {
W_LAVA,W_IS,  W_KILL,ROCK,  EMPTY, WALL,  LAVA,  WALL,  WALL,  WALL,  WALL,  WALL,  EMPTY, 
W_ROCK,W_IS,  W_STOP,ROCK,  EMPTY, WALL,  LAVA,  EMPTY, EMPTY, EMPTY, EMPTY, WALL,  EMPTY, 
W_FLAG,W_IS,  W_WIN, ROCK,  EMPTY, WALL,  LAVA,  EMPTY, EMPTY, FLAG,  EMPTY, WALL,  EMPTY, 
ROCK,  ROCK,  ROCK,  ROCK,  EMPTY, WALL,  LAVA,  EMPTY, EMPTY, EMPTY, EMPTY, WALL,  EMPTY, 
EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, WALL,  LAVA,  EMPTY, WALL,  WALL,  WALL,  WALL,  EMPTY, 
EMPTY, WALL,  WALL,  WALL,  WALL,  WALL,  LAVA,  LAVA,  LAVA,  LAVA,  LAVA,  LAVA,  LAVA,  
EMPTY, WALL,  BABA,  EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, WALL,  EMPTY, EMPTY, EMPTY, EMPTY, 
EMPTY, WALL,  WALL,  WALL,  WALL,  W_WALL,W_IS,  W_STOP,WALL,  EMPTY, EMPTY, EMPTY, EMPTY, 
EMPTY, W_BABA,W_IS,  W_YOU, WALL,  EMPTY, EMPTY, EMPTY, WALL,  EMPTY, EMPTY, EMPTY, EMPTY, 
EMPTY, EMPTY, EMPTY, EMPTY, WALL,  WALL,  WALL,  WALL,  WALL,  EMPTY, EMPTY, EMPTY, EMPTY, 
};

const uint8_t level7[MAP_FULL_SIZE] = {
EMPTY, EMPTY, EMPTY, EMPTY, W_WALL,W_IS,  W_STOP,EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, 
EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, 
EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, 
EMPTY, EMPTY, WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  EMPTY, EMPTY, 
EMPTY, EMPTY, WALL,  EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, WALL,  EMPTY, EMPTY, 
EMPTY, EMPTY, WALL,  W_BABA,W_IS,  W_YOU, EMPTY, EMPTY, W_WIN, EMPTY, WALL,  EMPTY, EMPTY, 
EMPTY, EMPTY, WALL,  EMPTY, EMPTY, EMPTY, EMPTY, W_FLAG,EMPTY, EMPTY, WALL,  EMPTY, EMPTY, 
EMPTY, EMPTY, WALL,  BABA,  EMPTY, EMPTY, FLAG,  EMPTY, EMPTY, EMPTY, WALL,  EMPTY, EMPTY, 
EMPTY, EMPTY, WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  EMPTY, EMPTY, 
EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY,
};

const uint8_t level8[MAP_FULL_SIZE] = {
EMPTY, EMPTY, WALL,  BABA,  EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, WALL,  EMPTY, EMPTY, 
EMPTY, EMPTY, WALL,  LAVA,  LAVA,  LAVA,  EMPTY, EMPTY, W_WALL,EMPTY, WALL,  EMPTY, EMPTY, 
EMPTY, EMPTY, WALL,  EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, W_IS,  EMPTY, WALL,  EMPTY, EMPTY, 
EMPTY, EMPTY, WALL,  EMPTY, W_LAVA,W_IS,  W_STOP,EMPTY, W_KILL,EMPTY, WALL,  EMPTY, EMPTY, 
EMPTY, EMPTY, WALL,  EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, WALL,  EMPTY, EMPTY, 
EMPTY, EMPTY, WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  EMPTY, EMPTY, 
EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, 
EMPTY, EMPTY, EMPTY, W_FLAG,W_IS,  W_WIN, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, 
EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, 
EMPTY, EMPTY, W_WALL,W_IS,  W_STOP,EMPTY, EMPTY, EMPTY, W_BABA,W_IS,  W_YOU, EMPTY, EMPTY, 
};

const uint8_t level9[MAP_FULL_SIZE] = {
EMPTY, EMPTY, W_WALL,W_IS,  W_STOP,EMPTY, EMPTY, EMPTY, EMPTY, W_BABA,W_IS,  W_YOU, EMPTY, 
EMPTY, WALL,  WALL,  WALL,  EMPTY, EMPTY, WALL,  WALL,  WALL,  WALL,  WALL,  EMPTY, EMPTY, 
EMPTY, WALL,  BABA,  WALL,  EMPTY, EMPTY, WALL,  W_LOVE,EMPTY, W_WIN, WALL,  EMPTY, EMPTY, 
EMPTY, WALL,  EMPTY, WALL,  EMPTY, EMPTY, WALL,  W_LOVE,W_IS,  W_SWAP,WALL,  EMPTY, EMPTY, 
EMPTY, WALL,  EMPTY, WALL,  EMPTY, EMPTY, WALL,  WALL,  EMPTY, WALL,  WALL,  EMPTY, EMPTY, 
EMPTY, WALL,  LOVE,  WALL,  WALL,  WALL,  WALL,  WALL,  EMPTY, WALL,  WALL,  EMPTY, EMPTY, 
EMPTY, WALL,  EMPTY, ROCK,  EMPTY, EMPTY, EMPTY, LOVE,  EMPTY, EMPTY, WALL,  EMPTY, EMPTY, 
EMPTY, WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  EMPTY, EMPTY, 
EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, 
EMPTY, EMPTY, EMPTY, W_ROCK,W_IS,  W_PUSH,EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY,
};

const uint8_t level10[MAP_FULL_SIZE] = {
EMPTY, EMPTY, ROCK,  EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, W_FLAG,W_IS,  W_WIN, EMPTY, EMPTY, 
W_WALL,EMPTY, ROCK,  W_LAVA,W_IS,  W_STOP,EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, LAVA,  
W_IS,  EMPTY, ROCK,  EMPTY, W_LOVE,W_IS,  W_YOU, EMPTY, WALL,  LOVE,  EMPTY, EMPTY, LAVA,  
W_STOP,EMPTY, ROCK,  EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, LAVA,  LAVA,  
EMPTY, EMPTY, ROCK,  ROCK,  ROCK,  ROCK,  ROCK,  ROCK,  ROCK,  ROCK,  ROCK,  ROCK,  ROCK,  
EMPTY, EMPTY, W_BABA,W_IS,  W_YOU, EMPTY, ROCK,  EMPTY, W_ROCK,W_IS,  W_STOP,EMPTY, ROCK,  
BABA,  EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, ROCK,  ROCK,  ROCK,  ROCK,  ROCK,  ROCK,  ROCK,  
EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, ROCK,  LAVA,  EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, 
EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, LAVA,  ROCK,  EMPTY, EMPTY, EMPTY, FLAG,  EMPTY, EMPTY, 
EMPTY, EMPTY, EMPTY, LAVA,  LAVA,  LAVA,  ROCK,  EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, 
};

const uint8_t level11[MAP_FULL_SIZE] = {
WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  
WALL,  W_LAVA,W_LAVA,W_LAVA,WALL,  BABA,  EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, GOOP,  GOOP,  
WALL,  W_IS,  W_IS,  W_IS,  WALL,  EMPTY, WALL,  W_EMPTY,EMPTY, ROCK,  ROCK,  GOOP,  WALL,  
WALL,  EMPTY, W_STOP,W_KILL,EMPTY, EMPTY, EMPTY, W_PUSH,EMPTY, LAVA,  LAVA,  GOOP,  WALL,  
WALL,  EMPTY, WALL,  WALL,  WALL,  EMPTY, EMPTY, EMPTY, EMPTY, LAVA,  GOOP,  GOOP,  WALL,  
WALL,  EMPTY, WALL,  W_ROCK,W_IS,  EMPTY, GOOP,  GOOP,  GOOP,  GOOP,  GOOP,  GOOP,  WALL,  
WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  GOOP,  WALL,  WALL,  WALL,  EMPTY, WALL,  WALL,  
WALL,  W_WALL,W_IS,  W_STOP,WALL,  W_BABA,GOOP,  EMPTY, FLAG,  EMPTY, EMPTY, EMPTY, WALL,  
WALL,  W_FLAG,W_IS,  W_WIN, WALL,  W_IS,  GOOP,  EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, WALL,  
WALL,  W_GOOP,W_IS,  W_SINK,WALL,  W_YOU, GOOP,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  
};

const uint8_t level12[MAP_FULL_SIZE] = {
FLAG,  EMPTY, EMPTY, W_FLAG,W_BABA,W_WALL,EMPTY, EMPTY, EMPTY, EMPTY, W_ROCK,W_IS,  W_STOP,
ROCK,  ROCK,  EMPTY, W_IS,  W_IS,  W_IS,  LAVA,  LAVA,  BABA,  EMPTY, EMPTY, EMPTY, EMPTY, 
EMPTY, EMPTY, WALL,  W_WIN, W_YOU, W_STOP,WALL,  ROCK,  ROCK,  ROCK,  ROCK,  ROCK,  EMPTY, 
W_LAVA,EMPTY, WALL,  WALL,  WALL,  WALL,  WALL,  EMPTY, EMPTY, W_LOVE,EMPTY, ROCK,  EMPTY, 
EMPTY, EMPTY, WALL,  W_WALL,W_IS,  W_STOP,WALL,  FLAG,  EMPTY, EMPTY, EMPTY, ROCK,  EMPTY, 
EMPTY, EMPTY, W_PUSH,EMPTY, W_IS,  ROCK,  ROCK,  EMPTY, EMPTY, EMPTY, EMPTY, ROCK,  EMPTY, 
EMPTY, EMPTY, ROCK,  EMPTY, EMPTY, EMPTY, ROCK,  W_LAVA,W_IS,  W_KILL,EMPTY, ROCK,  EMPTY, 
EMPTY, EMPTY, ROCK,  ROCK,  ROCK,  ROCK,  ROCK,  ROCK,  ROCK,  ROCK,  ROCK,  ROCK,  EMPTY, 
EMPTY, EMPTY, EMPTY, EMPTY, W_IS,  EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, 
EMPTY, EMPTY, W_LOVE,EMPTY, EMPTY, EMPTY, EMPTY, W_LOVE,W_IS,  W_PUSH,EMPTY, EMPTY, W_LAVA,
};

const uint8_t level13[] = {
W_ROCK,W_IS,  W_PUSH,EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, W_PUSH,W_LAVA,W_IS,  W_SINK,
LAVA,  LAVA,  EMPTY, EMPTY, W_LOVE,W_IS,  W_KILL,LOVE,  EMPTY, EMPTY, EMPTY, LAVA,  LAVA,  
LAVA,  LAVA,  LAVA,  LAVA,  EMPTY, BABA,  EMPTY, EMPTY, EMPTY, LAVA,  LAVA,  LAVA,  LAVA,  
W_LAVA,LAVA,  LAVA,  LAVA,  LOVE,  LOVE,  LOVE,  LOVE,  LOVE,  LAVA,  LAVA,  LAVA,  W_BABA,
W_IS,  EMPTY, LAVA,  LAVA,  LAVA,  LAVA,  LAVA,  LAVA,  LAVA,  LAVA,  EMPTY, EMPTY, W_IS,  
W_KILL,EMPTY, LAVA,  LAVA,  LAVA,  LAVA,  LAVA,  LAVA,  LAVA,  LAVA,  LAVA,  EMPTY, W_YOU, 
LAVA,  LAVA,  LAVA,  LAVA,  LAVA,  LAVA,  LAVA,  LAVA,  LAVA,  LAVA,  LAVA,  LAVA,  LAVA,  
LAVA,  FLAG,  LAVA,  LAVA,  EMPTY, LAVA,  LOVE,  LAVA,  EMPTY, LAVA,  LAVA,  EMPTY, W_FLAG,
LAVA,  LAVA,  LAVA,  LOVE,  LOVE,  LAVA,  LAVA,  LOVE,  LOVE,  LOVE,  LAVA,  LAVA,  W_IS,  
LAVA,  LAVA,  LAVA,  LOVE,  LAVA,  LOVE,  LAVA,  EMPTY, EMPTY, EMPTY, LAVA,  LAVA,  W_WIN, 
};

const uint8_t level14[] = {
EMPTY, EMPTY, WALL,  EMPTY, W_BABA,EMPTY, LAVA,  EMPTY, W_LOVE,EMPTY, WALL,  EMPTY, EMPTY, 
BABA,  EMPTY, WALL,  EMPTY, W_IS,  EMPTY, LAVA,  EMPTY, W_IS,  EMPTY, WALL,  EMPTY, LOVE,  
EMPTY, EMPTY, WALL,  EMPTY, W_YOU, EMPTY, LAVA,  EMPTY, W_YOU, EMPTY, WALL,  EMPTY, EMPTY, 
EMPTY, WALL,  WALL,  EMPTY, EMPTY, EMPTY, LAVA,  EMPTY, EMPTY, EMPTY, WALL,  WALL,  EMPTY, 
EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, LAVA,  EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, 
EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, LAVA,  EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, 
EMPTY, EMPTY, W_ROCK,EMPTY, EMPTY, EMPTY, LAVA,  EMPTY, EMPTY, EMPTY, W_WIN, EMPTY, EMPTY, 
EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, LAVA,  EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, 
EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, LAVA,  EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, 
W_WALL,W_IS,  W_STOP,EMPTY, EMPTY, EMPTY, LAVA,  EMPTY, EMPTY, EMPTY, W_LAVA,W_IS,  W_SINK,
};

const uint8_t level15[] = {
BABA,  EMPTY, EMPTY, EMPTY, EMPTY, GOOP,  GOOP,  GOOP,  EMPTY, WALL,  EMPTY, EMPTY, W_LAVA,
EMPTY, EMPTY, EMPTY, EMPTY, WALL,  GOOP,  GOOP,  W_IS,  EMPTY, EMPTY, EMPTY, EMPTY, W_IS,
LAVA,  LAVA,  LAVA,  WALL,  WALL,  EMPTY, W_GOOP,EMPTY, W_IS,  WALL,  EMPTY, EMPTY, W_KILL,
W_BABA,W_IS,  W_YOU, WALL,  WALL,  EMPTY, ROCK,  EMPTY, EMPTY, WALL,  W_ROCK,EMPTY, EMPTY,
W_GOOP,W_IS,  W_SINK,WALL,  WALL,  EMPTY, BABA,  W_PUSH,EMPTY, WALL,  EMPTY, EMPTY, EMPTY,
W_WALL,W_IS,  W_STOP,WALL,  WALL,  EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY,
LAVA,  LAVA,  WALL,  EMPTY, GOOP,  GOOP,  GOOP,  GOOP,  GOOP,  GOOP,  GOOP,  GOOP,  GOOP,
EMPTY, EMPTY, EMPTY, EMPTY, WALL,  GOOP,  GOOP,  GOOP,  GOOP,  GOOP,  GOOP,  GOOP,  GOOP,
EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, GOOP,  GOOP,  GOOP,  EMPTY, FLAG,  EMPTY, EMPTY, EMPTY,
BABA,  EMPTY, EMPTY, EMPTY, GOOP,  GOOP,  W_FLAG,EMPTY, EMPTY, W_IS,  W_WIN, EMPTY, WALL,
};

const uint8_t level16[] = {
EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, WALL,  EMPTY, EMPTY, EMPTY, LAVA,  LAVA,  LAVA,  W_FLAG,
EMPTY, W_BABA,W_IS,  W_YOU, BABA,  WALL,  EMPTY, EMPTY, EMPTY, LAVA,  LAVA,  LAVA,  W_IS,
EMPTY, EMPTY, EMPTY, EMPTY, WALL,  WALL,  EMPTY, EMPTY, LAVA,  LAVA,  LAVA,  EMPTY, W_WIN,
WALL,  WALL,  WALL,  EMPTY, EMPTY, ROCK,  EMPTY, EMPTY, LAVA,  LAVA,  LAVA,  EMPTY, EMPTY,
WALL,  W_ROCK,WALL,  WALL,  WALL,  WALL,  EMPTY, EMPTY, LAVA,  LAVA,  LAVA,  EMPTY, EMPTY,
EMPTY, W_IS,  EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, LAVA,  LAVA,  LAVA,  EMPTY, EMPTY,
EMPTY, W_PUSH,EMPTY, EMPTY, W_LAVA,EMPTY, EMPTY, EMPTY, LAVA,  LAVA,  EMPTY, EMPTY, EMPTY,
EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, LAVA,  LAVA,  LAVA,  FLAG,  EMPTY, EMPTY,
WALL,  WALL,  WALL,  WALL,  WALL,  EMPTY, LAVA,  LAVA,  LAVA,  LAVA,  EMPTY, EMPTY, EMPTY,
WALL,  W_LAVA,W_IS,  W_KILL,WALL,  EMPTY, LAVA,  LAVA,  LAVA,  EMPTY, W_WALL,W_IS,  W_STOP,
};

const uint8_t level17[] = {
WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,
WALL,  EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, WALL,  EMPTY, EMPTY, EMPTY, WALL,
WALL,  EMPTY, EMPTY, W_BABA,W_IS,  W_YOU, EMPTY, EMPTY, WALL,  WALL,  WALL,  WALL,  WALL,
WALL,  EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, WALL,  EMPTY, EMPTY, WALL,  W_WALL,
WALL,  EMPTY, BABA,  EMPTY, WALL,  WALL,  WALL,  WALL,  WALL,  EMPTY, FLAG,  WALL,  W_IS,
WALL,  EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, WALL,  EMPTY, EMPTY, WALL,  W_STOP,
WALL,  EMPTY, EMPTY, W_FLAG,W_IS,  W_WIN, EMPTY, EMPTY, WALL,  WALL,  WALL,  WALL,  WALL,
WALL,  EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, WALL,  EMPTY, EMPTY, EMPTY, WALL,
WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,
EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY,
};

const uint8_t level18[] = {
EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY,
EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,
EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, WALL,  EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY,
EMPTY, W_FLAG,W_IS,  W_WIN, EMPTY, WALL,  BABA,  EMPTY, LAVA,  EMPTY, EMPTY, W_WALL,EMPTY,
EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, WALL,  LAVA,  LAVA,  LAVA,  EMPTY, EMPTY, W_IS,  EMPTY,
EMPTY, W_BABA,W_IS,  W_YOU, EMPTY, WALL,  EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, W_STOP,EMPTY,
EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, WALL,  EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY,
EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, WALL,  EMPTY, W_LAVA,W_IS,  W_KILL,EMPTY, EMPTY, EMPTY,
EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, WALL,  EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY,
W_WALL,W_IS,  W_KILL,EMPTY, EMPTY, WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,
};

const uint8_t level19[] = {
LAVA,  LAVA,  LAVA,  LAVA,  LAVA,  LAVA,  LAVA,  EMPTY, LAVA,  LAVA,  LAVA,  LAVA,  W_LAVA,
LAVA,  EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, LAVA,  LAVA,  EMPTY, EMPTY, LAVA,  W_IS,
LAVA,  EMPTY, W_GOOP,EMPTY, EMPTY, EMPTY, W_BABA,WALL,  WALL,  EMPTY, EMPTY, LAVA,  W_KILL,
EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, W_IS,  WALL,  EMPTY, EMPTY, LAVA,  LAVA,  LAVA,
EMPTY, EMPTY, EMPTY, EMPTY, BABA,  EMPTY, W_YOU, WALL,  EMPTY, ROCK,  LAVA,  GOOP,  EMPTY,
LAVA,  EMPTY, WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  W_FLAG,EMPTY, LAVA,  EMPTY, FLAG,
LAVA,  EMPTY, W_WALL,W_IS,  W_STOP,EMPTY, LAVA,  LAVA,  EMPTY, EMPTY, EMPTY, LAVA,  LAVA,
LAVA,  EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, LAVA,  LAVA,  EMPTY, W_IS,  EMPTY, W_ROCK,LAVA,
LAVA,  EMPTY, LAVA,  LAVA,  LAVA,  LAVA,  LAVA,  WALL,  W_WIN, EMPTY, EMPTY, W_IS,  LAVA,
LAVA,  EMPTY, LAVA,  LAVA,  EMPTY, EMPTY, LAVA,  LAVA,  LAVA,  EMPTY, EMPTY, W_YOU, LAVA,
};

const uint8_t level20[] = {
FLAG,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,
EMPTY, WALL,  EMPTY, EMPTY, EMPTY, ROCK,  WALL,  EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY,
EMPTY, WALL,  EMPTY, W_LAVA,EMPTY, EMPTY, WALL,  EMPTY, W_IS,  EMPTY, EMPTY, EMPTY, EMPTY,
EMPTY, EMPTY, WALL,  WALL,  WALL,  EMPTY, WALL,  EMPTY, EMPTY, LAVA,  LAVA,  LAVA,  W_GOOP,
EMPTY, EMPTY, W_IS,  EMPTY, WALL,  EMPTY, WALL,  EMPTY, W_ROCK,LAVA,  W_LAVA,LAVA,  LAVA,
EMPTY, EMPTY, W_GOOP,EMPTY, WALL,  EMPTY, WALL,  EMPTY, EMPTY, LAVA,  W_IS,  LAVA,  W_GOOP,
W_WIN, EMPTY, EMPTY, EMPTY, WALL,  EMPTY, WALL,  EMPTY, EMPTY, LAVA,  W_KILL,LAVA,  W_IS,
EMPTY, EMPTY, WALL,  WALL,  EMPTY, EMPTY, EMPTY, WALL,  GOOP,  LAVA,  LAVA,  LAVA,  EMPTY,
EMPTY, EMPTY, EMPTY, W_FLAG,EMPTY, EMPTY, EMPTY, WALL,  WALL,  WALL,  W_BABA,W_IS,  W_YOU,
EMPTY, W_IS,  EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, WALL,  W_WALL,W_IS,  W_STOP,WALL,  BABA,
};

const uint8_t level21[] = {
W_GOOP,W_IS,  W_SINK,WALL,  WALL,  WALL,  FLAG,  WALL,  WALL,  WALL,  W_BABA,W_IS,  W_YOU,
W_WALL,W_IS,  W_STOP,WALL,  LAVA,  LAVA,  LAVA,  LAVA,  LAVA,  WALL,  W_FLAG,W_IS,  W_WIN,
WALL,  WALL,  WALL,  WALL,  LAVA,  LAVA,  LAVA,  LAVA,  LAVA,  WALL,  WALL,  WALL,  WALL,
LAVA,  LAVA,  LAVA,  LAVA,  LAVA,  LAVA,  LAVA,  LAVA,  LAVA,  LAVA,  LAVA,  LAVA,  LAVA,
EMPTY, LOVE,  EMPTY, W_FLAG,LAVA,  LAVA,  LAVA,  LAVA,  LAVA,  EMPTY, EMPTY, EMPTY, LOVE,
EMPTY, EMPTY, EMPTY, EMPTY, LAVA,  LAVA,  LAVA,  LAVA,  LAVA,  EMPTY, GOOP,  EMPTY, EMPTY,
EMPTY, W_GOOP,BABA,  ROCK,  EMPTY, LAVA,  W_IS,  LAVA,  EMPTY, W_ROCK,EMPTY, EMPTY, EMPTY,
EMPTY, EMPTY, GOOP,  EMPTY, EMPTY, EMPTY, LAVA,  EMPTY, EMPTY, LOVE,  EMPTY, ROCK,  EMPTY,
EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, GOOP,  GOOP,  EMPTY, EMPTY, EMPTY, EMPTY, EMPTY,
W_ROCK,W_IS,  W_PUSH,EMPTY, EMPTY, ROCK,  EMPTY, EMPTY, EMPTY, EMPTY, W_LAVA,W_IS,  W_SINK,
};

const uint8_t level22[] = {
};

const uint8_t level23[] = {
};

const uint8_t level24[] = {
};

const uint8_t level25[] = {
};

const uint8_t * levels[] = {
  level1, level2, level3, level4, level5, level6, level7, level8,
  level9, level10, level11, level12, level13, level14, level15,
  level16, level17, level18, level19, level20, level21, level22,
  level23, level24, level25
};

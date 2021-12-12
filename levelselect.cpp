#include "defines.h"
#include "draw.h"
#include "game.h"

uint8_t selected_level = 0;
void levelSelectInit()
{
  memset(buffer1, 0x00, ROW_SIZE);
  memset(buffer2, 0x00, ROW_SIZE);

  for (uint8_t row = 0; row < ROWS_COUNT - 1; row++)
  {
    drawScreenSlice(row * 16, 16, buffer1);
    waitForPreviousDraw();
  }

  drawText(30, 4, "B: BACK TO TITLE", buffer1);
  drawScreenSlice((ROWS_COUNT - 1) * 16, 16, buffer1);
  waitForPreviousDraw();

  selected_level = 0;
}

const char * names[] = {
  "LEVEL 1      LEVEL 2",
  "LEVEL 3      LEVEL 4",
  "LEVEL 5      LEVEL 6",
  "LEVEL 7      LEVEL 8",
};
void levelSelectTick()
{
  if (gb.buttons.pressed(BUTTON_B))
  {
    gotoScreen(MENU_SCREEN);
    return;
  }
  else if (gb.buttons.pressed(BUTTON_A))
  {
    startLevel(selected_level);
    return;
  }
  else if (gb.buttons.pressed(BUTTON_DOWN))
  {
    selected_level = (selected_level + 2) % 8;
  }
  else if (gb.buttons.pressed(BUTTON_UP))
  {
    if (selected_level < 2)
    {
      selected_level += 6;
    }
    else
    {
      selected_level = (selected_level - 2);
    }
  }
  else if (gb.buttons.pressed(BUTTON_LEFT) || gb.buttons.pressed(BUTTON_RIGHT))
  {
    if (selected_level % 2) selected_level--;
    else selected_level++;
  }

  for (uint8_t row = 0; row < 4; row++)
  {
    memset(buffer1, 0x00, ROW_SIZE);
    drawText(24, 4, names[row], buffer1);

    if (selected_level >> 1 == row)
    {
      uint8_t column = 12 + (selected_level % 2) * 78;
      drawText(column, 4, ">", buffer1);
    }

    drawScreenSlice(row * 16, 16, buffer1);
    waitForPreviousDraw();
  }
}

#include "defines.h"
#include "draw.h"
#include "game.h"
#include "levels.h"

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
  "LEVEL 1",
  "LEVEL 2",
  "LEVEL 3",
  "LEVEL 4",
  "LEVEL 5",
  "LEVEL 6",
  "LEVEL 7",
  "LEVEL 8",
  "LEVEL 9",
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
    if ((level_count % 2) == 0)
    {
      selected_level = (selected_level + 2) % level_count;
    }
    else
    {
      selected_level += 2;
      if (selected_level == level_count)
      {
        selected_level = 1;
      }
      else if (selected_level == level_count + 1)
      {
        selected_level = 0;
      }
    }
  }
  else if (gb.buttons.pressed(BUTTON_UP))
  {
    if (selected_level < 2)
    {
      selected_level = level_count - selected_level - 1;
    }
    else
    {
      selected_level = (selected_level - 2);
    }
  }
  else if (gb.buttons.pressed(BUTTON_LEFT) || gb.buttons.pressed(BUTTON_RIGHT))
  {
    // check last line in case of odd number of levels
    if (level_count % 2 == 0 || selected_level < level_count - 1)
    {
      if (selected_level % 2) selected_level--;
      else selected_level++;
    }
  }

  for (uint8_t row = 0; row < ((level_count + 1) / 2); row++)
  {
    memset(buffer1, 0x00, ROW_SIZE);
    drawText(24, 4, names[row * 2], buffer1);
    if (row * 2 + 1 < level_count)
    {
      drawText(102, 4, names[row * 2 + 1], buffer1);
    }

    if (selected_level >> 1 == row)
    {
      uint8_t column = 12 + (selected_level % 2) * 78;
      drawText(column, 4, ">", buffer1);
    }

    drawScreenSlice(row * 16, 16, buffer1);
    waitForPreviousDraw();
  }
}

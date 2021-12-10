#include <Gamebuino-Meta.h>
#include "game.h"
#include "title.h"
#include "defines.h"

uint8_t CURRENT_SCREEN = MENU_SCREEN;

void setup()
{
  gb.begin();
  gb.display.init(0, 0, ColorMode::rgb565);
  SerialUSB.begin(9600);

  menuInit();
}

void loop()
{
  gb.waitForUpdate();

  if (CURRENT_SCREEN == MENU_SCREEN)
  {
    menuTick();
  }
  else if (CURRENT_SCREEN == GAME_SCREEN)
  {
    gameTick();
  }
}

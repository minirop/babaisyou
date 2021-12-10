#include "defines.h"

namespace Gamebuino_Meta
{
  #define DMA_DESC_COUNT (3)
  extern volatile uint32_t dma_desc_free_count;

  static inline void wait_for_transfers_done()
  {
    while (dma_desc_free_count < DMA_DESC_COUNT);
  }

  static SPISettings tftSPISettings = SPISettings(24000000, MSBFIRST, SPI_MODE0);
  #undef DMA_DESC_COUNT
};

static bool drawPending = false;
uint16_t buffer1[SCREEN_WIDTH * 16];
uint16_t buffer2[SCREEN_WIDTH * 16];

void drawScreenSlice(int16_t y, int16_t h, uint16_t* buffer)
{
  int16_t x = 0;
  int16_t w = SCREEN_WIDTH;
  
  drawPending = true;
  gb.tft.setAddrWindow(x, y, x + w - 1, y + h - 1);
  SPI.beginTransaction(Gamebuino_Meta::tftSPISettings);
  gb.tft.dataMode();
  gb.tft.sendBuffer(buffer, w*h);
}

void waitForPreviousDraw()
{
  if (drawPending)
  {
    Gamebuino_Meta::wait_for_transfers_done();
    gb.tft.idleMode();
    SPI.endTransaction();
    drawPending = false;
  }
}

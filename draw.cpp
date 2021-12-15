#include "draw.h"

extern const uint16_t FONT[];

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

  drawRectangle(x, y, w, h, buffer);
}

void drawRectangle(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t* buffer)
{
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

void drawText(uint8_t x, uint8_t y, const char* text, uint16_t* buffer)
{
  for (uint8_t i = 0; i < strlen(text); i++)
  {
    uint8_t index = 0;

    auto c = text[i];
    if (c >= 'A' && c <= 'Z')
    {
      index = c - 'A';
    }
    else if (c >= '0' && c <= '9')
    {
      index = c - '0' + 26;
    }
    else if (c == '-')
    {
      index = 36;
    }
    else if (c == '.')
    {
      index = 37;
    }
    else if (c == ':')
    {
      index = 38;
    }
    else if (c == '>')
    {
      index = 39;
    }
    else
    {
      x += 6;
      continue;
    }

    for (uint8_t n = 0; n < 8; n++)
    {
      uint8_t px = 0;
      uint8_t py = n;

      uint16_t bpos = (x + px) + 160 * (py + y);
      uint16_t fpos = (n + 8*index) * 5;

      memcpy(&buffer[bpos], &FONT[fpos], 10);
    }

    x += 6;
  }
}


const uint16_t FONT[] = {
    // frame 1/40
    0x0000, 0xffff, 0xffff, 0xffff, 0x0000,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,

    // frame 2/40
    0xffff, 0xffff, 0xffff, 0xffff, 0x0000,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0xffff, 0xffff, 0xffff, 0x0000,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0xffff, 0xffff, 0xffff, 0x0000,

    // frame 3/40
    0x0000, 0xffff, 0xffff, 0xffff, 0x0000,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0x0000,
    0xffff, 0x0000, 0x0000, 0x0000, 0x0000,
    0xffff, 0x0000, 0x0000, 0x0000, 0x0000,
    0xffff, 0x0000, 0x0000, 0x0000, 0x0000,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0x0000, 0xffff, 0xffff, 0xffff, 0x0000,

    // frame 4/40
    0xffff, 0xffff, 0xffff, 0xffff, 0x0000,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0xffff, 0xffff, 0xffff, 0x0000,

    // frame 5/40
    0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0x0000,
    0xffff, 0x0000, 0x0000, 0x0000, 0x0000,
    0xffff, 0xffff, 0xffff, 0x0000, 0x0000,
    0xffff, 0x0000, 0x0000, 0x0000, 0x0000,
    0xffff, 0x0000, 0x0000, 0x0000, 0x0000,
    0xffff, 0x0000, 0x0000, 0x0000, 0x0000,
    0xffff, 0xffff, 0xffff, 0xffff, 0xffff,

    // frame 6/40
    0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0x0000,
    0xffff, 0x0000, 0x0000, 0x0000, 0x0000,
    0xffff, 0xffff, 0xffff, 0x0000, 0x0000,
    0xffff, 0x0000, 0x0000, 0x0000, 0x0000,
    0xffff, 0x0000, 0x0000, 0x0000, 0x0000,
    0xffff, 0x0000, 0x0000, 0x0000, 0x0000,
    0xffff, 0x0000, 0x0000, 0x0000, 0x0000,

    // frame 7/40
    0x0000, 0xffff, 0xffff, 0xffff, 0x0000,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0x0000,
    0xffff, 0x0000, 0x0000, 0xffff, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0x0000, 0xffff, 0xffff, 0xffff, 0x0000,

    // frame 8/40
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,

    // frame 9/40
    0x0000, 0xffff, 0xffff, 0xffff, 0x0000,
    0x0000, 0x0000, 0xffff, 0x0000, 0x0000,
    0x0000, 0x0000, 0xffff, 0x0000, 0x0000,
    0x0000, 0x0000, 0xffff, 0x0000, 0x0000,
    0x0000, 0x0000, 0xffff, 0x0000, 0x0000,
    0x0000, 0x0000, 0xffff, 0x0000, 0x0000,
    0x0000, 0x0000, 0xffff, 0x0000, 0x0000,
    0x0000, 0xffff, 0xffff, 0xffff, 0x0000,

    // frame 10/40
    0x0000, 0x0000, 0x0000, 0x0000, 0xffff,
    0x0000, 0x0000, 0x0000, 0x0000, 0xffff,
    0x0000, 0x0000, 0x0000, 0x0000, 0xffff,
    0x0000, 0x0000, 0x0000, 0x0000, 0xffff,
    0x0000, 0x0000, 0x0000, 0x0000, 0xffff,
    0x0000, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0x0000, 0xffff, 0xffff, 0xffff, 0x0000,

    // frame 11/40
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0x0000, 0x0000, 0xffff, 0x0000,
    0xffff, 0xffff, 0xffff, 0x0000, 0x0000,
    0xffff, 0x0000, 0x0000, 0xffff, 0x0000,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,

    // frame 12/40
    0xffff, 0x0000, 0x0000, 0x0000, 0x0000,
    0xffff, 0x0000, 0x0000, 0x0000, 0x0000,
    0xffff, 0x0000, 0x0000, 0x0000, 0x0000,
    0xffff, 0x0000, 0x0000, 0x0000, 0x0000,
    0xffff, 0x0000, 0x0000, 0x0000, 0x0000,
    0xffff, 0x0000, 0x0000, 0x0000, 0x0000,
    0xffff, 0x0000, 0x0000, 0x0000, 0x0000,
    0xffff, 0xffff, 0xffff, 0xffff, 0xffff,

    // frame 13/40
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0xffff, 0x0000, 0xffff, 0xffff,
    0xffff, 0x0000, 0xffff, 0x0000, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,

    // frame 14/40
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0xffff, 0x0000, 0x0000, 0xffff,
    0xffff, 0xffff, 0x0000, 0x0000, 0xffff,
    0xffff, 0x0000, 0xffff, 0x0000, 0xffff,
    0xffff, 0x0000, 0xffff, 0x0000, 0xffff,
    0xffff, 0x0000, 0x0000, 0xffff, 0xffff,
    0xffff, 0x0000, 0x0000, 0xffff, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,

    // frame 15/40
    0x0000, 0xffff, 0xffff, 0xffff, 0x0000,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0x0000, 0xffff, 0xffff, 0xffff, 0x0000,

    // frame 16/40
    0xffff, 0xffff, 0xffff, 0xffff, 0x0000,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0xffff, 0xffff, 0xffff, 0x0000,
    0xffff, 0x0000, 0x0000, 0x0000, 0x0000,
    0xffff, 0x0000, 0x0000, 0x0000, 0x0000,
    0xffff, 0x0000, 0x0000, 0x0000, 0x0000,
    0xffff, 0x0000, 0x0000, 0x0000, 0x0000,

    // frame 17/40
    0x0000, 0xffff, 0xffff, 0xffff, 0x0000,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0x0000, 0xffff, 0x0000, 0xffff,
    0xffff, 0x0000, 0x0000, 0xffff, 0x0000,
    0x0000, 0xffff, 0xffff, 0x0000, 0xffff,

    // frame 18/40
    0xffff, 0xffff, 0xffff, 0xffff, 0x0000,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0xffff, 0xffff, 0xffff, 0x0000,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,

    // frame 19/40
    0x0000, 0xffff, 0xffff, 0xffff, 0x0000,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0xffff, 0xffff, 0xffff, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0xffff,
    0x0000, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0x0000, 0xffff, 0xffff, 0xffff, 0x0000,

    // frame 20/40
    0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
    0x0000, 0x0000, 0xffff, 0x0000, 0x0000,
    0x0000, 0x0000, 0xffff, 0x0000, 0x0000,
    0x0000, 0x0000, 0xffff, 0x0000, 0x0000,
    0x0000, 0x0000, 0xffff, 0x0000, 0x0000,
    0x0000, 0x0000, 0xffff, 0x0000, 0x0000,
    0x0000, 0x0000, 0xffff, 0x0000, 0x0000,
    0x0000, 0x0000, 0xffff, 0x0000, 0x0000,

    // frame 21/40
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0x0000, 0xffff, 0xffff, 0xffff, 0x0000,

    // frame 22/40
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0x0000, 0xffff, 0x0000, 0xffff, 0x0000,
    0x0000, 0xffff, 0x0000, 0xffff, 0x0000,
    0x0000, 0x0000, 0xffff, 0x0000, 0x0000,
    0x0000, 0x0000, 0xffff, 0x0000, 0x0000,

    // frame 23/40
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0x0000, 0xffff, 0x0000, 0xffff,
    0xffff, 0xffff, 0x0000, 0xffff, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,

    // frame 24/40
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0x0000, 0xffff, 0x0000, 0xffff, 0x0000,
    0x0000, 0x0000, 0xffff, 0x0000, 0x0000,
    0x0000, 0x0000, 0xffff, 0x0000, 0x0000,
    0x0000, 0xffff, 0x0000, 0xffff, 0x0000,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,

    // frame 25/40
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0x0000, 0xffff, 0x0000, 0xffff, 0x0000,
    0x0000, 0xffff, 0x0000, 0xffff, 0x0000,
    0x0000, 0x0000, 0xffff, 0x0000, 0x0000,
    0x0000, 0x0000, 0xffff, 0x0000, 0x0000,
    0x0000, 0x0000, 0xffff, 0x0000, 0x0000,
    0x0000, 0x0000, 0xffff, 0x0000, 0x0000,

    // frame 26/40
    0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
    0x0000, 0x0000, 0x0000, 0x0000, 0xffff,
    0x0000, 0x0000, 0x0000, 0xffff, 0x0000,
    0x0000, 0x0000, 0xffff, 0x0000, 0x0000,
    0x0000, 0xffff, 0x0000, 0x0000, 0x0000,
    0xffff, 0x0000, 0x0000, 0x0000, 0x0000,
    0xffff, 0x0000, 0x0000, 0x0000, 0x0000,
    0xffff, 0xffff, 0xffff, 0xffff, 0xffff,

    // frame 27/40
    0x0000, 0xffff, 0xffff, 0xffff, 0x0000,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0x0000, 0x0000, 0xffff, 0xffff,
    0xffff, 0x0000, 0xffff, 0x0000, 0xffff,
    0xffff, 0x0000, 0xffff, 0x0000, 0xffff,
    0xffff, 0xffff, 0x0000, 0x0000, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0x0000, 0xffff, 0xffff, 0xffff, 0x0000,

    // frame 28/40
    0x0000, 0xffff, 0xffff, 0x0000, 0x0000,
    0x0000, 0x0000, 0xffff, 0x0000, 0x0000,
    0x0000, 0x0000, 0xffff, 0x0000, 0x0000,
    0x0000, 0x0000, 0xffff, 0x0000, 0x0000,
    0x0000, 0x0000, 0xffff, 0x0000, 0x0000,
    0x0000, 0x0000, 0xffff, 0x0000, 0x0000,
    0x0000, 0x0000, 0xffff, 0x0000, 0x0000,
    0x0000, 0xffff, 0xffff, 0xffff, 0x0000,

    // frame 29/40
    0x0000, 0xffff, 0xffff, 0xffff, 0x0000,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0x0000, 0x0000, 0x0000, 0x0000, 0xffff,
    0x0000, 0x0000, 0x0000, 0xffff, 0x0000,
    0x0000, 0x0000, 0xffff, 0x0000, 0x0000,
    0x0000, 0xffff, 0x0000, 0x0000, 0x0000,
    0xffff, 0x0000, 0x0000, 0x0000, 0x0000,
    0xffff, 0xffff, 0xffff, 0xffff, 0xffff,

    // frame 30/40
    0x0000, 0xffff, 0xffff, 0xffff, 0x0000,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0x0000, 0x0000, 0x0000, 0x0000, 0xffff,
    0x0000, 0x0000, 0x0000, 0xffff, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0xffff,
    0x0000, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0x0000, 0xffff, 0xffff, 0xffff, 0x0000,

    // frame 31/40
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0x0000, 0xffff, 0xffff, 0xffff, 0xffff,
    0x0000, 0x0000, 0x0000, 0x0000, 0xffff,
    0x0000, 0x0000, 0x0000, 0x0000, 0xffff,
    0x0000, 0x0000, 0x0000, 0x0000, 0xffff,
    0x0000, 0x0000, 0x0000, 0x0000, 0xffff,

    // frame 32/40
    0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0x0000,
    0xffff, 0x0000, 0x0000, 0x0000, 0x0000,
    0xffff, 0xffff, 0xffff, 0xffff, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0xffff,
    0x0000, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0x0000, 0xffff, 0xffff, 0xffff, 0x0000,

    // frame 33/40
    0x0000, 0xffff, 0xffff, 0xffff, 0x0000,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0x0000,
    0xffff, 0xffff, 0xffff, 0xffff, 0x0000,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0x0000, 0xffff, 0xffff, 0xffff, 0x0000,

    // frame 34/40
    0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
    0x0000, 0x0000, 0x0000, 0x0000, 0xffff,
    0x0000, 0x0000, 0x0000, 0x0000, 0xffff,
    0x0000, 0x0000, 0xffff, 0xffff, 0xffff,
    0x0000, 0x0000, 0x0000, 0x0000, 0xffff,
    0x0000, 0x0000, 0x0000, 0x0000, 0xffff,
    0x0000, 0x0000, 0x0000, 0x0000, 0xffff,
    0x0000, 0x0000, 0x0000, 0x0000, 0xffff,

    // frame 35/40
    0x0000, 0xffff, 0xffff, 0xffff, 0x0000,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0x0000, 0xffff, 0xffff, 0xffff, 0x0000,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0x0000, 0xffff, 0xffff, 0xffff, 0x0000,

    // frame 36/40
    0x0000, 0xffff, 0xffff, 0xffff, 0x0000,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0x0000, 0xffff, 0xffff, 0xffff, 0xffff,
    0x0000, 0x0000, 0x0000, 0x0000, 0xffff,
    0x0000, 0x0000, 0x0000, 0x0000, 0xffff,
    0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
    0x0000, 0xffff, 0xffff, 0xffff, 0x0000,

    // frame 37/40
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000,

    // frame 38/40
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0xffff, 0x0000, 0x0000,

    // frame 39/40
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0xffff, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0xffff, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000,

    // frame 40/40
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0xffff, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0xffff, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0xffff, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0xffff, 0x0000,
    0x0000, 0x0000, 0xffff, 0x0000, 0x0000,
    0x0000, 0xffff, 0x0000, 0x0000, 0x0000,
    0xffff, 0x0000, 0x0000, 0x0000, 0x0000
};
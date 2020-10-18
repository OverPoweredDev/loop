#include "Cursor.h"

Cursor::Cursor(TTF_Font *font) {
    TTF_SizeText(font, "_", &charWidth, &height);
}

void Cursor::fill(u32 *screen_pixels) {
    assert(screen_pixels);
    for (int row = this->y; row < this->y + this->height; row++) {
        for (int col = this->x; col < this->x + this->width; col++) {
            screen_pixels[(row * SCREEN_WIDTH) + col] = color;
        }
    }
}

//getters
int Cursor::getLineNumber() {
    return lineNumber;
}

int Cursor::getCharNumber() {
    return charNumber;
}
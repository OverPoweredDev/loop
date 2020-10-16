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

void Cursor::shiftLeft() {
    if (x > OFFSET_X) {
        this->x -= charWidth;
        this->charNumber -= 1;
    }
}

void Cursor::shiftRight() {
    if(charNumber < LINE_LIMIT && x < SCREEN_WIDTH) {
        this->x += charWidth;
        this->charNumber += 1;
    }
}

void Cursor::shiftUp() {
    this->y -= height;
    this->lineNumber -= 1;
}

void Cursor::shiftDown() {
    this->y += height;
    this->lineNumber += 1;
}

//getters
int Cursor::getLineNumber(){
    return lineNumber;
}

int Cursor::getCharNumber(){
    return charNumber;
}
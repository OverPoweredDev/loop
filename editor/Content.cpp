#include "Content.h"

Content::Content(Document *doc, Cursor *cur) {
    this->document = doc;
    this->cursor = cur;
}

void Content::shiftLeft() {
    if (cursor->x > OFFSET_X) {
        cursor->x -= cursor->charWidth;
        cursor->charNumber -= 1;
    }
}

void Content::shiftRight() {
    if (cursor->charNumber < LINE_LIMIT && cursor->x < SCREEN_WIDTH) {
        cursor->x += cursor->charWidth;
        cursor->charNumber += 1;
    }
}

void Content::shiftUp() {
    if (cursor->y > 0) {
        cursor->y -= cursor->height;
        cursor->lineNumber -= 1;
    }
}

void Content::shiftDown() {
    if (cursor->lineNumber < document->lineCount) {
        cursor->y += cursor->height;
        cursor->lineNumber += 1;
    }
}

void Content::shiftPos(int lineNum, int charNum) {
    if (charNum < LINE_LIMIT && lineNum < document->lineCount) {
        cursor->x = OFFSET_X + (cursor->charWidth * charNum);
        cursor->y = cursor->height * lineNum;
        cursor->lineNumber = lineNum;
        cursor->charNumber = charNum;
    }
}


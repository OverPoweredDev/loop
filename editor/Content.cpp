#include "Content.h"

//constructor
Content::Content(Document *doc, Cursor *cur) {
    this->document = doc;
    this->cursor = cur;
}

//renderDocument
void Content::renderDocument(TTF_Font *font, SDL_Color color, SDL_Renderer *renderer) {
    char *line;
    int height = TTF_FontHeight(font);
    for (int i = 0; i < document->getLineCount(); i++) {
        line = document->getLine(i);
        int texW = 0;
        int texH = 0;
        SDL_Surface *surface = TTF_RenderText_Solid(font, line, color);
        SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);

        SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
        SDL_Rect rect = {OFFSET_X, i * height, texW, texH};

        SDL_RenderCopy(renderer, texture, NULL, &rect);
    }
}

//shift Cursor
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


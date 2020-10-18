#ifndef LOOP_EDITORVIEW_H
#define LOOP_EDITORVIEW_H

#include "Utility.h"
#include "Document.h"
#include "Cursor.h"

class Content {
private:
    Document *document;
    Cursor *cursor;

public:
    Content(Document *doc, Cursor *cur);

    //rendering
    void renderDocument(TTF_Font *font, SDL_Color color, SDL_Renderer *renderer);

    //cursor shifting
    void shiftUp();
    void shiftDown();
    void shiftLeft();
    void shiftRight();
    void shiftPos(int lineNum, int charNum);

    //getters
    int getCharHeight();
    int getCharWidth();
};


#endif //LOOP_EDITORVIEW_H

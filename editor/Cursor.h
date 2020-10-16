#ifndef L00P_RECTANGLE_H
#define L00P_RECTANGLE_H

#include "Utility.h"

class Cursor {
private:
    int x = OFFSET_X;
    int y = 0;
    int width = 2;
    int height;
    int charWidth = 4;
    int charNumber = 0;
    int lineNumber = 0;
    u32 color = 30;

public:
    Cursor(TTF_Font *font);

    void fill(u32 *screen_pixels);

    void shiftUp();
    void shiftDown();
    void shiftLeft();
    void shiftRight();

    //getters
    int getLineNumber();
    int getCharNumber();
    int getLineHeight();
};


#endif //L00P_RECTANGLE_H

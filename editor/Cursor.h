#ifndef L00P_RECTANGLE_H
#define L00P_RECTANGLE_H

#include "Utility.h"
#include "Document.h"

class Cursor {
public:
    int x = OFFSET_X;
    int y = 0;
    int width = 2;
    int height;
    int charWidth = 4;
    int charNumber = 0;
    int lineNumber = 0;
    u32 color = 30;

    Cursor(TTF_Font *font);
    void fill(u32 *screen_pixels);

    int getLineNumber();
    int getCharNumber();
};


#endif //L00P_RECTANGLE_H

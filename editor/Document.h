#ifndef LOOP_DOCUMENT_H
#define LOOP_DOCUMENT_H

#include <string>
#include <fstream>
#include <iostream>

#include "Buffer.h"

using namespace std;

class Document {
private:
    int length = 0;
    bool documentHasChanged;
    Buffer text;

public:
    //actual editing
    void init(string filename);
    void saveFile(string filename);
    void insertText(string text, int position);

    //test functions
    void printToConsole(void);

    //getters
    bool hasChanged(void);
    int getLength(void);
    int getBufferPos(void);
};

#endif //LOOP_DOCUMENT_H
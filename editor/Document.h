#ifndef L00P_DOCUMENT_H
#define L00P_DOCUMENT_H

#include <fstream>
#include "Utility.h"

using namespace std;

class Document {
public:
    char **lineBuffer;
    bool documentHasChanged;
    int lineCount = 0;

    //file handling
    void init(std::string filename);
    void saveFile(std::string filename);

    //test functions
    void printToConsole();

    //editing
    void createLine(int lineNum, int numLines);
    void shiftLineDown(int lineNum);
    void insertPos(int lineNum, int charNum, char c);
    void deletePos(int lineNum, int charNum);

    //getters
    char** getLineBuffer();
    char* getLine(int i);
    bool hasChanged();
    int getLineCount();
};


#endif //L00P_DOCUMENT_H

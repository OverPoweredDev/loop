#include "Document.h"

using namespace std;

//basic file handling
void Document::init(string filename) {
    ifstream inFile(filename);
    int numLine = 0, numChar = 0;
    string line;

    while (getline(inFile, line))
        lineCount++;

    lineCount = 20;

    lineBuffer = (char **) malloc(lineCount * sizeof(char *));

    for (int i = 0; i < lineCount; i++) {
        lineBuffer[i] = (char *) malloc(LINE_LIMIT * sizeof(char));
        memset(lineBuffer[i], ' ', LINE_LIMIT * sizeof(char));
    }

    //reset cursor
    inFile.clear();
    inFile.seekg(0, ios::beg);

    while (getline(inFile, line)) {
        for (char c: line)
            insertPos(numLine, numChar++, c);
        numChar = 0;
        numLine++;
    }

    this->documentHasChanged = false;
    inFile.close();
}

void Document::saveFile(string filename) {
    ofstream outputFile(filename);

    //Error in Saving File
    if (!outputFile.is_open()) {
        cerr << "Error saving file: " << filename << endl;
        return;
    }

    //Actual File Saving
    for (int i = 0; i < lineCount; i++) {
        outputFile << this->lineBuffer[i];
        outputFile << '\n';
    }
    this->documentHasChanged = false;
    outputFile.close();
}


//testing
void Document::printToConsole() {
    for (int i = 0; i < lineCount; i++)
        cout << lineBuffer[i] << endl;
}


//editing
void Document::createLine(int lineNum, int numLines) {
    int prevCount = lineCount;
    lineCount += numLines;
    realloc(lineBuffer, lineCount * sizeof(char *));

    //allocate memory for empty lines
    for (int i = prevCount; i < lineCount; i++) {
        lineBuffer[i] = (char *) malloc(LINE_LIMIT * sizeof(char));
        memset(lineBuffer[i], ' ', LINE_LIMIT * sizeof(char));
    }

    //shift any existing lines down
    for (int i = lineCount - 1; i < lineNum; i--) {
        shiftLineDown(i);
    }
}

void Document::shiftLineDown(int lineNum) {
    lineBuffer[lineNum + 1] = lineBuffer[lineNum];
    memset(lineBuffer[lineNum], ' ', LINE_LIMIT * sizeof(char));
}

void Document::insertPos(int lineNum, int charNum, char c) {
    if (isValid(c))
        for (int i = LINE_LIMIT; i >= charNum; i--)
            lineBuffer[lineNum][i + 1] = lineBuffer[lineNum][i];
    lineBuffer[lineNum][charNum] = c;
}

void Document::deletePos(int lineNum, int charNum) {
    for (int i = charNum + 1; i < LINE_LIMIT; i++)
        lineBuffer[lineNum][i - 1] = lineBuffer[lineNum][i];
    lineBuffer[lineNum][LINE_LIMIT] = ' ';
}


//getters
char **Document::getLineBuffer() {
    return lineBuffer;
}

char *Document::getLine(int i) {
    return lineBuffer[i];
}

int Document::getLineCount() {
    return lineCount;
}

bool Document::hasChanged() {
    return documentHasChanged;
}
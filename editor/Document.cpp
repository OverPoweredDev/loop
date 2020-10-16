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
        lineBuffer[i] = (char *) malloc(80 * sizeof(char));
        memset(lineBuffer[i], ' ', 80);
    }

    //reset cursor
    inFile.clear();
    inFile.seekg(0, ios::beg);

    while (getline(inFile, line)) {
        for (char c: line)
            lineBuffer[numLine][numChar++] = c;
        numChar = 0;
        numLine += 1;
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
void Document::insert(int lineNum, int charNum, char c) {
    lineBuffer[lineNum][charNum] = c;
}

void Document::deletePos(int lineNum, int charNum) {
    lineBuffer[lineNum][charNum] = ' ';
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
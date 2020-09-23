#include "Document.h"

using namespace std;

//basic file handling
void Document::init(string filename) {
    string line;
    ifstream inFile(filename);

    //Error in opening File
    if (!inFile.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    //Load Text File into Gap Buffer
    while (getline(inFile, line)) {
        line += "\n";
        text.insert(line, this->length);
        this->length += line.length();
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
    outputFile << this->text.buffer;
    this->documentHasChanged = false;
    outputFile.close();
}

void Document::insertText(string text, int position) {
    this->text.insert(text, position);
    this->documentHasChanged = true;
}


//test functions
void Document::printToConsole(){
    for (int i = 0; i < length; i++) {
        cout << text.buffer[i];
    }
}


//getters
bool Document::hasChanged() {
    return this->documentHasChanged;
}

int Document::getLength(){
    return this->length;
}

int Document::getBufferPos() {
    return this->text.gap_left;
}
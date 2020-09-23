//#include <SFML/Graphics.hpp>
//#include <SFML/Window.hpp>
//#include <SFML/System.hpp>
#include <fstream>
#include "editor/Buffer.h"
#include "editor/Document.h"
#include <string>
#include <iostream>

using namespace std;

int main() {

    Document doc;
    doc.init("input.txt");
    doc.printToConsole();
    doc.insertText("insertion", 20);
    cout << doc.getBufferPos();
    doc.saveFile("output.txt");


//    Buffer b;
//    std::fstream fs;
//    fs.open("input.txt", std::fstream::in | std::fstream::out);
//
//    for (int i = 0; i < 10; i++) {
//        b.buffer[i] = '_';
//    }
//
//    for (int i = 0; i < b.size; i++) {
//        cout << b.buffer[i] << " ";
//    }
//
//    cout << endl;
//
//    string input = "OPbest";
//    int position = 0;
//
//    b.insert(input, position);
//
//    cout << endl;
//    cout << "Inserting a string to buffer" << input << endl;
//    cout << "Output: ";
//    for (int i = 0; i < b.size; i++) {
//        cout << b.buffer[i] << " ";
//    }
//
//    input = " da ";
//    position = 2;
//
//    b.insert(input, position);
//
//    cout << "Output: ";
//    for (int i = 0; i < b.size; i++) {
//        fs << b.buffer[i];
//    }
//
//    fs.close();

    return 0;
}
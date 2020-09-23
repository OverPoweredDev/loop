#ifndef LOOP_BUFFER_H
#define LOOP_BUFFER_H

#include <string>
#include <iostream>

class Buffer {
public:
    char buffer[10000];
    int gap_size = 10;
    int gap_left = 0;
    int gap_right = gap_size - gap_left - 1;
    int size = 50;

    void grow(int k, int position);
    void left(int position);
    void right(int position);
    void moveCursor(int position);
    void insert(std::string input, int position);
    void delete_pos(int pos1, int pos2);
};

#endif //LOOP_BUFFER_H

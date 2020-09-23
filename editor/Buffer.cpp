#include "Buffer.h"
#include <string>

using namespace std;

void Buffer::grow(int k, int position) {

    char a[size];
    for (int i = position; i < size; i++)
        a[i - position] = buffer[i];
    for (int i = 0; i < k; i++)
        buffer[i + position] = ' ';
    for (int i = 0; i < position + k; i++)
        buffer[position + k + i] = a[i];
    size += k;
    gap_right += k;
}

void Buffer::left(int position) {
    while (position < gap_left) {
        gap_left--;
        gap_right--;
        buffer[gap_right + 1] = buffer[gap_left];
        buffer[gap_left] = ' ';
    }
}

void Buffer::right(int position) {
    while (position > gap_left) {
        gap_left++;
        gap_right++;
        buffer[gap_left - 1] = buffer[gap_right];
        buffer[gap_right] = ' ';
    }
}

void Buffer::moveCursor(int position) {
    if (position < gap_left)
        left(position);
    else
        right(position);
}

void Buffer::insert(string input, int position) {
    int len = input.length();
    int i = 0;

    if (position != gap_left) {
        moveCursor(position);
    }

    while (i < len) {
        if (gap_right == gap_left) {
            int k = 10;
            grow(k, position);
        }

        buffer[gap_left] = input[i];
        gap_left++;
        i++;
        position++;
    }
}

void Buffer::delete_pos(int pos1, int pos2) {
    if(pos1 > pos2){
        cout << "Enter Correct Position" << endl;
        return;
    }
    
    if (position + 1 != gap_left) {
        moveCursor(position + 1);
    }

    gap_left --;
    buffer[gap_left] = ' ';
}
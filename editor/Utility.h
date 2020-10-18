#ifndef L00P_UTILITY_H
#define L00P_UTILITY_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include <iostream>
#include <cassert>

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 576
#define COMMON_COLOR_MAX 255
#define OFFSET_X 40
#define LINE_LIMIT 80
#define SDLK_ENTER 13

typedef uint32_t u32;

static bool isValid(char c) {
    if ((c >= '!' && c <= '~') || c == ' ')
        return true;
    return false;
}

#endif //L00P_UTILITY_H

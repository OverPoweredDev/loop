#include "editor/Utility.h"
#include "editor/Document.h"
#include "editor/Cursor.h"

using namespace std;

bool isValid(char c) {
    if (c >= '!' && c <= '~')
        return true;
    else
        return false;
}

void printLines(Document doc, TTF_Font *font, SDL_Color color, SDL_Renderer *renderer) {
    char *line;
    int height = TTF_FontHeight(font);
    for (int i = 0; i < doc.getLineCount(); i++) {
        line = doc.getLine(i);
        int texW = 0;
        int texH = 0;
        SDL_Surface *surface = TTF_RenderText_Solid(font, line, color);
        SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);

        SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
        SDL_Rect rect = {OFFSET_X, i * height, texW, texH};

        SDL_RenderCopy(renderer, texture, NULL, &rect);
    }
}

int main(int argc, char *argv[]) {
/*==========< SDL Init >==============================================================================================*/

    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow("loop",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          SCREEN_WIDTH,
                                          SCREEN_HEIGHT,
                                          0);
    assert(window);

    SDL_Renderer *renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_SOFTWARE);
    assert(renderer);

    SDL_Texture *screen = SDL_CreateTexture(renderer,
                                            SDL_PIXELFORMAT_RGB888,
                                            SDL_TEXTUREACCESS_STREAMING,
                                            SCREEN_WIDTH,
                                            SCREEN_HEIGHT);

    u32 *screenPixels = (u32 *) calloc(SCREEN_WIDTH * SCREEN_HEIGHT, sizeof(u32));
    assert(screenPixels);

    TTF_Init();
    char fontPath[] = "fonts/JetBrainsMono-Regular.ttf";
    int fontSize = 20;
    TTF_Font *font = TTF_OpenFont(fontPath, fontSize);
    SDL_Color color = {40, 0, 0};



/*============< Main >================================================================================================*/

    Cursor cursor(font);

    Document document;
    document.init("input.txt");
    document.printToConsole();

/*======< Create SDL Window>==========================================================================================*/

    bool done = false;
    int frameNum = 0;
    char ascii;
    while (!done) {
        SDL_Event event;

        while (SDL_PollEvent(&event)) {

            SDL_UpdateTexture(screen, NULL, screenPixels, SCREEN_WIDTH * sizeof(u32));
            SDL_RenderClear(renderer);
            memset(screenPixels, 240, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(u32));

            if (event.type == SDL_QUIT) {
                done = true;
                break;
            }

            if (event.type == SDL_KEYDOWN) {
                SDL_Keycode code = event.key.keysym.sym;

                switch (code) {
                    case SDLK_ESCAPE:
                        done = true;
                        document.saveFile("output.txt");
                        break;
                    case SDLK_UP:
                        cursor.shiftUp();
                        break;
                    case SDLK_DOWN:
                        cursor.shiftDown();
                        break;
                    case SDLK_LEFT:
                        cursor.shiftLeft();
                        break;
                    case SDLK_RIGHT:
                        cursor.shiftRight();
                        break;
                    case SDLK_BACKSPACE:
                        cursor.shiftLeft();
                        document.deletePos(cursor.getLineNumber(), cursor.getCharNumber());
                        break;
                    case SDLK_TAB:
                        for (int i = 0; i < 4; i++)
                            cursor.shiftRight();
                    case SDLK_DELETE:
                        cursor.shiftLeft();
                        document.deletePos(cursor.getLineNumber(), cursor.getCharNumber()+1);
                        break;
                    default:
                        ascii = (char) code;
                        cursor.shiftRight();
                        if (isValid(ascii))
                            document.insert(cursor.getLineNumber(), cursor.getCharNumber() - 1, ascii);
                        break;
                }
            }

            cursor.fill(screenPixels);
            SDL_RenderCopy(renderer, screen, NULL, NULL);
            printLines(document, font, color, renderer);
            SDL_RenderPresent(renderer);

            SDL_Delay(10);
        }

    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_Quit();

    document.printToConsole();

    return EXIT_SUCCESS;
}
#include "editor/Utility.h"
#include "editor/Document.h"
#include "editor/Content.h"
#include "editor/Cursor.h"

using namespace std;



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

    Content content(&document, &cursor);

/*======< Create SDL Window>==========================================================================================*/

    bool done = false;
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
                int currLine = cursor.getLineNumber();
                int currChar = cursor.getCharNumber();

                switch (code) {
                    case SDLK_ESCAPE:
                        done = true;
                        document.saveFile("output.txt");
                        break;
                    case SDLK_ENTER:
                        content.shiftDown();
                        break;
                    case SDLK_UP:
                        content.shiftUp();
                        break;
                    case SDLK_DOWN:
                        content.shiftDown();
                        break;
                    case SDLK_LEFT:
                        content.shiftLeft();
                        break;
                    case SDLK_RIGHT:
                        content.shiftRight();
                        break;
                    case SDLK_DELETE:
                        document.deletePos(currLine, currChar);
                        break;
                    case SDLK_BACKSPACE:
                        document.deletePos(currLine, currChar-1);
                        content.shiftLeft();
                        break;
                    case SDLK_TAB:
                        for (int i = 0; i < 4; i++)
                            content.shiftRight();
                    default:
                        ascii = (char) code;
                        content.shiftRight();
                        if (isValid(ascii))
                            document.insertPos(currLine, cursor.getCharNumber() - 1, ascii);
                        break;
                }
            }

            cursor.fill(screenPixels);
            SDL_RenderCopy(renderer, screen, NULL, NULL);
            content.renderDocument(font, color, renderer);
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
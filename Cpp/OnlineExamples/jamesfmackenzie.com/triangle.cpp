#include <SDL.h>
#include <emscripten.h>
#include <stdlib.h>

SDL_Window *window;
SDL_Renderer *renderer;
SDL_Surface *surface;

// draw ... Draw a series of lines to the screen to create a triangle.
void draw(SDL_Renderer *Renderer) {
    //Set the draw color...
    // SDL_SetRenderDrawColor(Renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    //Clear the screen.
    // SDL_RenderClear(Renderer);

    //Setting the actual draw color.
    SDL_SetRenderDrawColor(Renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

    //Drawing the lines we want. (-1, 0), (0, 1), (1, 0)
    SDL_RenderDrawLine(Renderer, 0, 480, 320, 0);
    SDL_RenderDrawLine(Renderer, 640, 480, 320, 0);
    SDL_RenderDrawLine(Renderer, 0, 480, 640, 480);

    //Update the Renderer.
    SDL_RenderPresent(Renderer);
}

void drawRandomPixels() {
    if (SDL_MUSTLOCK(surface)) SDL_LockSurface(surface);

    uint8_t *pixels = ((uint8_t *)surface->pixels);

    for (int i = 0; i < 1048576; i++) {
        char randomByte = rand() % 255;
        pixels[i] = randomByte;
    }

    if (SDL_MUSTLOCK(surface)) SDL_UnlockSurface(surface);

    SDL_Texture *screenTexture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, screenTexture, NULL, NULL);
    SDL_RenderPresent(renderer);

    SDL_DestroyTexture(screenTexture);

    //Drawing!
    draw(renderer);
}

int main(int argc, char *argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(512, 512, 0, &window, &renderer);
    surface = SDL_CreateRGBSurface(0, 512, 512, 32, 0, 0, 0, 0);

    emscripten_set_main_loop(drawRandomPixels, 0, 1);
}
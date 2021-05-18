#include <SDL.h>
#include <emscripten.h>
#include <string.h>

#include <iostream>

/*
 *
 *	Hello World in SDL2.
 *
 */

/* Global Constants */
const int SECOND = 1000;

// init ... The init function, it calls the SDL init function.
int init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        return -1;
    }

    return 0;
}

// draw ... Draw a series of lines to the screen to create a triangle.
void draw(SDL_Renderer* Renderer) {
    //Set the draw color...
    SDL_SetRenderDrawColor(Renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    //Clear the screen.
    SDL_RenderClear(Renderer);

    //Setting the actual draw color.
    SDL_SetRenderDrawColor(Renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

    //Drawing the lines we want. (-1, 0), (0, 1), (1, 0)
    SDL_RenderDrawLine(Renderer, 0, 480, 320, 0);
    SDL_RenderDrawLine(Renderer, 640, 480, 320, 0);
    SDL_RenderDrawLine(Renderer, 0, 480, 640, 480);

    //Update the Renderer.
    SDL_RenderPresent(Renderer);
}

// createWindowContext ... Creating the window for later use in rendering and stuff.
SDL_Window* createWindowContext(std::string title) {
    //Declaring the variable the return later.
    SDL_Window* Window = NULL;

    //Creating the window and passing that reference to the previously declared variable.
    Window = SDL_CreateWindow("Hello World!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_OPENGL);

    //Returning the newly creted Window context.
    return Window;
}

// createRenderContext ... Creating the rendering context so that I can render things to the Window.
SDL_Renderer* createRendererContext(SDL_Window* Window) {
    //Declaring the variable for the Renderer context.
    SDL_Renderer* Renderer = NULL;

    //Create the Renderer with the window.
    Renderer = SDL_CreateRenderer(Window, -1, 0);

    //Return the Renderer.
    return Renderer;
}

void mainLoop() {
    //Calling the SDL init stuff.
    init();

    //Creating the context for SDL2.
    SDL_Window* Window = createWindowContext("Hello World!");

    //Creating the rendering context.
    SDL_Renderer* Renderer = createRendererContext(Window);

    //Drawing!
    draw(Renderer);
}

// main ... The main function, right now it just calls the initialization of SDL.
int main(int argc, char* argv[]) {
    //Adding a delay.
    // SDL_Delay(4 * SECOND);

    //Just printing out hello world if everything is working properly.
    std::cout << "Hello World!" << std::endl;

    emscripten_set_main_loop(mainLoop, 0, 1);

    //Cleaning up everything.
    // SDL_Quit();
    return 0;
}
call emcc stacker.c -s USE_SDL=2 -s USE_SDL_IMAGE=2 -o stacker.html --preload-file Resources --use-preload-plugins
Rem call emcc stacker.c -s USE_SDL=2 -lSDL --preload-file Resources -s USE_SDL_IMAGE=2 -s ALLOW_MEMORY_GROWTH=1 --use-preload-plugins -s SDL2_IMAGE_FORMATS='["bmp","png"]' -s GL_UNSAFE_OPTS=0 -W -Wall -ggdb -O2 -o stacker.html
call emcc -c main.cpp -o main.o -s USE_SDL=2
call emcc main.o -o main.html -s USE_SDL=2
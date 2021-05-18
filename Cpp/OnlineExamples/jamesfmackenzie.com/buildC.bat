mkdir .\out\build\
cd .\out\build\
call emcc -c ..\..\main.c -o main.o -s USE_SDL=2
call emcc main.o -o main.html -s USE_SDL=2
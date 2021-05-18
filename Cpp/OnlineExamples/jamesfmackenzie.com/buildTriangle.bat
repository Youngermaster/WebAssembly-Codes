call emcc -c triangle.cpp -o triangle.o -s USE_SDL=2
call emcc triangle.o -o triangle.html -s USE_SDL=2
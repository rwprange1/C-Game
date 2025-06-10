g++ -c main.cpp -IC:\Users\richw\Downloads\CSStuff\C++\Libraries\SFML-3.0.0-windows-gcc-14.2.0-mingw-64-bit\SFML-3.0.0\include
g++ -c Game.cpp -IC:\Users\richw\Downloads\CSStuff\C++\Libraries\SFML-3.0.0-windows-gcc-14.2.0-mingw-64-bit\SFML-3.0.0\include

g++ main.o Game.o -o main -LC:\Users\richw\Downloads\CSStuff\C++\Libraries\SFML-3.0.0-windows-gcc-14.2.0-mingw-64-bit\SFML-3.0.0\lib -lsfml-graphics -lsfml-window -lsfml-system

.\main.exe

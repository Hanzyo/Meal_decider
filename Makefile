
output.exe: main.o Resturants.o Users.o
	g++ main.o Resturants.o Users.o -o output.exe

main.o: src/main.cpp
	g++ -c src/main.cpp

Resturants.o: lib/Resturants.cpp
	g++ -c lib/Resturants.cpp

Users.o: lib/Users.cpp
	g++ -c lib/Users.cpp

clean:
	rm *.o output

p: main.cpp
	g++ main.cpp -o p

main: mainfunc.cpp
	g++ -c mainfunc.cpp main.cpp -o main.exe
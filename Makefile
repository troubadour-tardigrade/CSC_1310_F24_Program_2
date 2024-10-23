p: main.cpp
	g++ main.cpp -o p

main.cpp: mainfunc.cpp
	g++ -c mainfunc.cpp -o main.cpp
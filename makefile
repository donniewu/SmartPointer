all:
	g++ 1.cpp -o a1 --std=c++11
	g++ 2.cpp -o a2 --std=c++11
	g++ 3.cpp -o a3 --std=c++11
	g++ 4.cpp -o a4 --std=c++11
	g++ 5.cpp -o a5 --std=c++11
	g++ 6.cpp -o a6 --std=c++11 -pthread
	g++ 7.cpp -o a7 --std=c++11 -pthread
	g++ 8.cpp -o a8 --std=c++11
	g++ 9.cpp -o a9 --std=c++11 -O3
	g++ 10.cpp -o a10 --std=c++11


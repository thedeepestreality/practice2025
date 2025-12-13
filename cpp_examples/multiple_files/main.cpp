#include <iostream>
#include "array_lib.h"

inline int dummy() {
	return 42;
}

//inline int dummy() {
//	return 42;
//}

int evenDummier();

void hidden();

extern int global_x;

int main() {
	//hidden(); // error
	std::cout << global_x << '\n';
	std::cout << dummy() << '\n';
	std::cout << evenDummier() << '\n';
	int rows = 3;
	int cols = 4;
	int** arr = ones(rows, cols);
	printArray(arr, rows, cols);
	deleteArray(arr, rows);
	return 0;
}
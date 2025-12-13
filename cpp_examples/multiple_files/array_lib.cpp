#include <iostream>
#include "array_lib.h"

int global_x = 42;

int** createArray(int rows, int cols) {
	int** arr = new int* [rows];
	for (int r = 0; r < rows; ++r)
		arr[r] = new int[cols];
	return arr;
}

void deleteArray(int** arr, int rows) {
	for (int r = 0; r < rows; ++r)
		delete[] arr[r];
	delete[] arr;
}

void printArray(int** arr, int rows, int cols) {
	for (int r = 0; r < rows; ++r) {
		for (int c = 0; c < cols; ++c)
			std::cout << arr[r][c] << ' ';
		std::cout << '\n';
	}
}

void fillArrayOnes(int** arr, int rows, int cols) {
	for (int r = 0; r < rows; ++r)
		for (int c = 0; c < cols; ++c)
			arr[r][c] = 1;
}

int** ones(int rows, int cols) {
	int** arr = createArray(rows, cols);
	fillArrayOnes(arr, rows, cols);
	return arr;
}

inline int dummy() {
	return 43;
}

int evenDummier() {
	return dummy();
}
//unavailable outside
static void hidden() {

}
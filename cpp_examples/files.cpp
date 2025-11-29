#include <iostream>
#include <fstream>

int** create2dArray(int rows, int cols) {
	int** arr = new int* [rows];
	for (int r = 0; r < rows; ++r)
		arr[r] = new int[cols];
	return arr;
}

void delete2dArray(int** arr, int rows) {
	for (int r = 0; r < rows; ++r)
		delete[] arr[r];
	delete[] arr;
}

void print2dArray(int** arr, int rows, int cols) {
	for (int r = 0; r < rows; ++r) {
		for (int c = 0; c < cols; ++c)
			std::cout << arr[r][c] << ' ';
		std::cout << '\n';
	}
}

void read2dArrayFromFile(std::ifstream& in, int** arr, int rows, int cols) {
	for (int r = 0; r < rows; ++r)
		for (int c = 0; c < cols; ++c)
			in >> arr[r][c];
}

void square2dArray(int** arr, int rows, int cols) {
	for (int r = 0; r < rows; ++r) {
		for (int c = 0; c < cols; ++c)
			arr[r][c] *= arr[r][c];
	}
}

void print2dArrayToFile(std::ofstream& out, int** arr, int rows, int cols) {
	out << rows << ' ' << cols << '\n';
	for (int r = 0; r < rows; ++r) {
		for (int c = 0; c < cols; ++c)
			out << arr[r][c] << ' ';
		out << '\n';
	}
}

void output2dArray(
	int** arr, 
	int rows, 
	int cols, 
	std::ostream& out = std::cout
) {
	out << rows << ' ' << cols << '\n';
	for (int r = 0; r < rows; ++r) {
		for (int c = 0; c < cols; ++c)
			out << arr[r][c] << ' ';
		out << '\n';
	}
}

int main() {
	std::ifstream in("in.txt");
	if (!in) {
		std::cerr << "Failed to open input file\n";
		return 1;
	}
	int rows;
	int cols;
	in >> rows >> cols;

	int** arr = create2dArray(rows, cols);
	read2dArrayFromFile(in, arr, rows, cols);
	//print2dArray(arr, rows, cols);
	output2dArray(arr, rows, cols);
	square2dArray(arr, rows, cols);
	print2dArray(arr, rows, cols);

	std::ofstream out("out.txt");
	if (!out) {
		std::cerr << "Failed to open output file\n";
		return 2;
	}
	//print2dArrayToFile(out, arr, rows, cols);
	output2dArray(arr, rows, cols, out);
	delete2dArray(arr, rows);

	return 0;
}
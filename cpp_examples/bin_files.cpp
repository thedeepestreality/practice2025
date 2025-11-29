#include <iostream>
#include <fstream>

int main() {
	const int N = 5;
	int arr[N] = { 12345678, 87654321, 12348765, 43215678, 43218765 };
	// 1 text output
	std::ofstream out("out.txt");
	for (int i = 0; i < N; ++i)
		out << arr[i] << ' ';
	out.close();

	// 2 read text input
	int dest[N];
	std::ifstream in("out.txt");
	for (int i = 0; i < N; ++i)
		in >> dest[i];

	// 3 bin output
	std::ofstream out_bin("out_bin.txt", std::ios::binary);
	//// this would be still text output
	//for (int i = 0; i < N; ++i)
	//	out_bin << arr[i] << ' ';
	out_bin.write(reinterpret_cast<char*>(arr), N * sizeof(arr[0]));
	out_bin.close();

	// 4 bin input
	std::ifstream in_bin("out_bin.txt", std::ios::binary);
	int in_buf[N] = {};
	in_bin.read(reinterpret_cast<char*>(in_buf), N * sizeof(arr[0]));
	for (int i = 0; i < N; ++i) {
		std::cout << in_buf[i] << ' ';
		in_buf[i] = 0;
	}
	in_bin.close();
	std::cout << '\n';

	// how to get file size
	std::ifstream in_size("out_bin.txt", std::ios::binary);
	in_size.seekg(0, std::ios::end); // in_size[-1]
	int sz = in_size.tellg();
	in_size.seekg(0); //in_size.seekg(0, std::ios::beg);

	return 0;
}
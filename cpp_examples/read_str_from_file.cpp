#include <iostream>
#include <fstream>

int main() {
	char str[32] = {};
	std::ifstream in("in.txt");
	if (!in) {
		std::cerr << "Input file error\n";
		return 1;
	}
	// read until the first separator
	//in >> str;

	//// read 31 symbols or until newline
	//in.get(str, 31);
	//std::cout << str << '\n';
	//// explicit newline read
	//in.get();
	//in.get(str, 31);
	//std::cout << str << '\n';

	//// read 31 symbols or until newline
	//in.getline(str, 31);
	//std::cout << str << '\n';
	//in.getline(str, 31);
	//std::cout << str << '\n';

	//// read character by character
	//int count = 0;
	//while (!in.eof() && count < 31)
	//	str[count++] = in.get();

	// read any character
	in.read(str, 31);
	std::cout << strlen(str) << '\n';


	return 0;
}
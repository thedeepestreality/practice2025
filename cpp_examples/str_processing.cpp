#include <iostream>

int count_words(char str[]) {
	bool in_flag = false;
	int count = 0;
	while (*str) {
		if (!in_flag && *str != ' ') {
			in_flag = true;
			++count;
		}
		else if (in_flag && *str == ' ')
			in_flag = false;
		++str;
	}
	return count;
}

void reverse_substr(char str[], int n) {
	for (int idx = 0; idx < n / 2; ++idx)
		std::swap(str[idx], str[n - idx - 1]);
}

void reverse_letters(char str[]) {
	bool in_flag = false;
	char* start = str;
	int count = 0;
	while (*str) {
		if (!in_flag && *str != ' ') {
			in_flag = true;
			start = str;
		}
		else if (in_flag && *str == ' ') {
			in_flag = false;
			reverse_substr(start, count);
			count = 0;
		}
		if (in_flag)
			++count;
		++str;
	}
}

int main() {
	char str[] = " one two   three ";
	std::cout << str << '\n';
	std::cout << count_words(str) << '\n';
	reverse_letters(str);
	std::cout << str << '\n';
	return 0;
}
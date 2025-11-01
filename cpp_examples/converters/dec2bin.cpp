#include <iostream>

void reverse_array(char arr[], int n)
{
	for (int i = 0; i < n / 2; ++i)
	{
		char tmp = arr[n - i - 1];
		arr[n - i - 1] = arr[i];
		arr[i] = tmp;
	}
}

// decimal to binary converter
int main() {
	unsigned long long dec_num;
	std::cin >> dec_num;
	char bin_str[65] = {};
	int idx = 0;
	while (dec_num != 0) {
		bin_str[idx++] = (dec_num % 2) + '0';
		// example for base > 10
		//if (digit < 10)
		//	std::cout << digit + '0';
		//else
		//	std::cout << (digit - 10) + 'A';
		dec_num /= 2;
	}
	//for (int i = 0; i < idx; ++i)
	//	std::cout << bin_str[idx - i - 1];

	//reverse digits (more prod-like code)
	reverse_array(bin_str, idx);
	std::cout << bin_str;

	std::cout << '\n';
	return 0;
}
#include <iostream>

void reverse_array(int arr[], int sz) {
	for (int idx = 0; idx < sz / 2; ++idx)
		std::swap(arr[idx], arr[sz - idx - 1]);
}

void shift_array(int arr[], int sz, int shift) {
	shift %= sz;
	reverse_array(arr, sz);
	reverse_array(arr, shift);
	reverse_array(arr + shift, sz - shift);
}

void print_array(int arr[], int sz) {
	for (int idx = 0; idx < sz; ++idx)
		std::cout << arr[idx] << ' ';
	std::cout << '\n';
}

int main() {
	const int SZ = 8;
	int arr[SZ] = { 9, 4, 8, 3, 5, 7, 1, 2 };
	print_array(arr, SZ);
	shift_array(arr, SZ, 3);
	print_array(arr, SZ);
	return 0;
}
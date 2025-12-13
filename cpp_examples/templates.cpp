#include <iostream>
#include <cstdarg>

//int abs(int x) {
//	return x < 0 ? -x : x;
//}
//
//double abs(double x) {
//	return x < 0 ? -x : x;
//}

template <typename Type>
Type Abs(Type x) {
	static int hint = 0;
	++hint;
	std::cout << "abc " << hint << '\n';
	return x < 0 ? -x : x;
} 

template <typename Type1, typename Type2=int>
void dummy(Type1 x = 1.5) {
	//Type1 x = 0.0;
	Type1 y = 0.0;
	std::cout << x << '\n';
}

#define PI 3.1415
// VERY VERY BAD
#define ABS(x) ((x) < 0 ? -(x) : (x))

// c-style
int var_sum(int num, ...) {
	va_list args;
	va_start(args, num);
	int sum = 0;
	for (int idx = 0; idx < num; ++idx)
		sum += va_arg(args, int);
	va_end(args);
	return sum;
}

template <int arg1, int ... Args>
constexpr int Sum = arg1 + Sum<Args...>;

template <int arg1>
constexpr int Sum<arg1> = arg1;

template <typename Type>
Type SumTemp(Type head) {
	return head;
}

template <typename Type, typename... Args>
Type SumTemp(Type head, Args... tail) {
	return head + SumTemp(tail...);
}

int main() {
	std::cout << Abs(-1) << '\n';
	std::cout << Abs(-1.5) << '\n';
	dummy<int>();

	std::cout << ABS(-1) << '\n';

	std::cout << var_sum(3, 4, 5, 6) << '\n';

	std::cout << Sum<4, 5, 6> << '\n';

	std::cout << SumTemp(4.0, 5.0, 6.5) << '\n';
	return 0;
}
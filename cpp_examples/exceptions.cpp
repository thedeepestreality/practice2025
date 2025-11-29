#include <iostream>

int fooErrcode(double x) {
	if (x == 0.0)
		return 1;
	return 0;
}

void fooException(double x) {
	if (x == 0.0)
		throw 1;
	double y = x * 2;
}

int someActions(double x) {
	//...
	int res = fooErrcode(x);
	if (res != 0)
		return res;
}

//int weNeedToGoDeeper(double x) {
//	int res = someActions(x);
//	if (res != 0)
//		return res;
//}


void someActionsEx(double x) {
	//...
	fooException(x);
}

void weNeedToGoDeeperEx(double x) {
	someActionsEx(x);
}

int main() {
	double x;
	std::cin >> x;

	try {
		someActionsEx(x);
	}
	catch (int ex) {
		std::cerr << "Error\n";
		return 1;
	}

	//////int res = fooErrcode(x);
	//////if (res == 1) {
	//////	std::cerr << "Error\n";
	//////	return 1;
	//////}

	//////try {
	////	fooException(x);
	//////}
	//////catch (int ex) {
	//////	std::cerr << "Error\n";
	//////	return 1;
	//////}
	////// some normal code
	return 0;
}
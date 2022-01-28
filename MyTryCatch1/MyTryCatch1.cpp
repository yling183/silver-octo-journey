#include <iostream>
#include <stdexcept>
#include <exception>

#include "MyTryCatch1.h"

using namespace std;

double division(int a, int b) {
	if (b == 0) {
		throw "Division by zero condition!";
	}
	return a / b;
}

void try_catch(void) {
	int x = 50;
	int y = 0;
	double z = 0;

	try {
		z = division(x, y);
		cout << z << endl;
	}
	catch (const char* msg) {
		cerr << msg << endl;
	}
	return;
}
#include <iostream>
using namespace std;

namespace A {
	void func() {
		cout << "A_fun()" << endl;
	}
}

namespace B {
	void func() {
		cout << "B_fun()" << endl;
	}
}

// Ç¶Ì×µÄÃüÃû¿Õ¼ä
namespace C {
	void func() {
		cout << "C_fun()" << endl;
	}
	namespace C_1 {
		void func() {
			cout << "C_1_fun()" << endl;
		}
	}
}

void TestNameSpace_1(void) {
	A::func();
	B::func();

	using namespace A;
	func();
}

void TestNameSpace_2(void) {
	C::func();
	C::C_1::func();

	using namespace C::C_1;
	func();
}
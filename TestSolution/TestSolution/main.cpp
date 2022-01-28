#include <iostream>

#include "namespace.h"
#include "TempLate.h"
#include "DefineProcess.h"
#include "ClassApply.h"

using namespace std;

int main()
{
	TestNameSpace_1();
	cout << endl;
	TestNameSpace_2();
	cout << "---------------------------------" << endl;

	Test_TempLate_Func();
	cout << "---------------------------------" << endl;

	Test_TempLate_Class();
	cout << "---------------------------------" << endl;

	Test_Class();
	cout << "---------------------------------" << endl;

	Test_DefineProcess();
	cout << "---------------------------------" << endl;

	TestClassCopy();
	cout << "---------------------------------" << endl;

	Test_Derive();
	cout << "---------------------------------" << endl;

	Test_Time();
	cout << "---------------------------------" << endl;

	Test_Virtual();
	cout << "---------------------------------" << endl;

	Test_EXPLICIT();
	cout << "---------------------------------" << endl;

	system("pause");
	return 0;
}
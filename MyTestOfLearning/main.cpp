#include <iostream>

#include "Myfstream1.h"
#include "MyTryCatch1.h"
#include "MyNewDelete.h"

int main()
{
	try_catch();
	TestFstream();
	Test_NewDelete();
	Test_NewDelete_ARRAY();

	system("pause");
	return 0;
}
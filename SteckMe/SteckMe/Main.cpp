#define _CRT_SECURE_NO_WARNINGS
#include "Interface.h"
#include "VvodExc.h"

using namespace std;

int main()
{
	setlocale(0, "Rus");
	set_terminate(ITerminate);
	Interface obj;
	obj.Page1();
	return 0;
}
#include "HTextEditor.h"
#include "HConsole.h"
int main()
{
	TConsole a(30,10);
	a.SetInpLen(5);
	a.Input();
	TString d(a);
	cout << d;
	cin >> d;
	cout << d;
	return 0;
}
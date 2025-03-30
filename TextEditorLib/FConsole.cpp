#include "HConsole.h"
TConsole::TConsole()
{
	x = 0;
	y = 0;
	str = new char[1] { 0 };
	len = 1;
	inplen = 7;
}

TConsole::TConsole(unsigned x_, unsigned y_)
{
	if (x_ < 0 || y_ < 0)
		throw("x < 0 || y < 0");
	x = x_;
	y = y_;
	str = new char[1] { 0 };
	len = 1;
	inplen = 1;
}

TConsole::~TConsole()
{
}

unsigned TConsole::GetLen()
{
	return len;
}

char* TConsole::GetStr()
{
	return str;
}
unsigned TConsole::GetX()
{
	return x;
}
unsigned TConsole::GetY()
{
	return y;
}
void TConsole::SetX(unsigned x_)
{
	if (x_ < 0)
		throw("x < 0");
		x = x_;
}
void TConsole::SetY(unsigned y_)
{
	if (y_ < 0)
		throw("y < 0");
	y = y_;
}
unsigned TConsole::GetInpLen()
{
	return inplen;
}
void TConsole::SetInpLen(unsigned inplen_)
{
	if (inplen < 1)
		throw("inplen < 1");
	inplen = inplen_;
}
void TConsole::GoToXY(unsigned x_, unsigned y_)
{
	if (x < 0 || y < 0)
		throw("x < 0 || y < 0");
	for (int i = 0; i < y_; i++)
		cout << '\n';
	for (int i = 0; i < x_; i++)
		cout << ' ';
}


void TConsole::Input()
{
	int i = 0;
	str = new char[256];
	GoToXY(x, y);
	while (str[i - 1] != '\r')
	{
		if (i > inplen)
		{
			system("cls");
			GoToXY(x, y);
			i = 0;
		}
		str[i] = _getch();
		cout << str[i];
		++i;
	}
	str[i - 1] = '\0';
	len = strlen(str);
	system("cls");
}

ostream& operator << (ostream& out, TConsole& val)
{
	out << "x - " << val.x << endl << "y - " << val.y;
	return out;
}

istream& operator>>(istream& inp, TConsole& val)
{
	cout << "Enter x - ";
	inp >> val.x;
	cout << "Enter y - ";
	inp >> val.y;
	if (val.x < 0 || val.y < 0)
		throw("x < 0 || y < 0");
	return inp;
}

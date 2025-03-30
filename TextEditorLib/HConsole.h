#pragma once
#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;
class TConsole
{
public:
	TConsole();
	TConsole(unsigned x_, unsigned y_);
	~TConsole();
	unsigned GetLen();
	char* GetStr();
	unsigned GetX();
	unsigned GetY();
	void SetX(unsigned x_);
	void SetY(unsigned y_);
	unsigned GetInpLen();
	void SetInpLen(unsigned inplen_);
	void GoToXY(unsigned x_, unsigned y_);
	void Input();
	friend ostream& operator << (ostream& out, TConsole& val);
	friend istream& operator >> (istream& inp, TConsole& val);
protected:
	unsigned x, y, len, inplen;
	char* str;
};
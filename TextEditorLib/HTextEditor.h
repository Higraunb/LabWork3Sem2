#pragma once
#include <iostream>
#include <cstring>
#include "HConsole.h"
using namespace std;
class TString : public TConsole
{
public:
	TString();
	TString(const TString& val);
	TString(TConsole& val);
	TString(TString&& val);
	TString(const char* str_);
	TString(unsigned len_, char* str_);
	~TString();
	void SetLen(unsigned len_);
	void SetStr(char* str_);
	unsigned FirstEntry(char* val);
	unsigned* AllIndexEntry(char* val);
	unsigned AllEntry(char* val);
	char MostEntry();
	void SymbolAndQuantity();
	char** Split(char* val);
	char* LineWithoutRepetitions();
	bool operator != (TString& val);
	TString operator + (TString& val);
	TString operator * (unsigned len_);
	TString operator = (TString& val);
	bool operator == (TString& val);
	bool operator > (TString& val);
	bool operator < (TString& val);
	char& operator [] (unsigned num);
	friend istream& operator >> (istream& inp, TString& val);
	friend ostream& operator << (ostream& out, TString& val);
protected:
};


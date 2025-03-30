#include "HTextEditor.h"

TString::TString(unsigned len_, char* str_)
{
	if (len_ <= 0)
		throw "len_ <= 0";
	if (strlen(str_) != len_)
		throw "str_ != len_";
	len = len_;
	str = new char[len];
	for (int i = 0; i < len; i++)
		str[i] = str_[i];
}

TString::TString(TConsole& val)
{
	len = val.GetLen();
	if (val.GetStr() != nullptr)
	{
		str = new char[len + 1];
		for (int i = 0; i < len; i++)
			str[i] = val.GetStr()[i];
	}
	else
		throw "p.str == nullptr";
	str[len] = '\0';
}

TString::TString(TString&& val)
{
	len = val.len;
	str = val.str;
	val.str = nullptr;
	len = 0;
}

TString::TString(const char* str_)
{
	if ((str_ == nullptr) || (str_[0] == '\0'))
		throw "str_ = nullptr";
	len = strlen(str_);
	str = new char[len + 1];
	for (int i = 0; i < len; i++)
	{
		str[i] = str_[i];
	}
	str[len] = '\0';
}

TString::TString()
{
	/*str = new char[1]{ 0 };
	len = 1;*/
}

TString::TString(const TString& val)
{
	len = val.len;
	if (val.str != nullptr)
	{
		str = new char[len];
		for (int i = 0; i < len; i++)
			str[i] = val.str[i];
	}
	else
		throw "p.str == nullptr";
	str[len] = '\0';
}

TString::~TString()
{
	if (str != nullptr)
	{
		delete[] str;
	}
	str = nullptr;
}

void TString::SetLen(unsigned len_)
{
	if (len < 0)
		throw("len < 0");
	if (len_ == len)
		return;
	else
	{
		char* str_ = new char[len_ + 1];
		for (int i = 0; i < min(len, len_); i++)
			str_[i] = str[i];
		for (int i = min(len,len_); i < len_; i++)
			str_[i] = '0';
		delete[]str;
		str_[len_] = '\0';
		str = str_;
		len = len_;
 	}
}

void TString::SetStr(char* str_)
{
	if (str_ == nullptr)
		throw "str_ == nullptr";
	len = strlen(str_);
	str = new char[len + 1];
	for (int i = 0; i < len; i++)
		str[i] = str_[i];
	str[len] = '\0';
}

unsigned TString::FirstEntry(char* val)
{
	int j = 0, res = 0;
	for (int i = 0; i < len; i++)
	{
		if (str[i] == val[j])
		{
			j++;
			res = i;
			return res;
		}
		else
		{
			if (j != 0)
				return -1;
		}
	}
}

unsigned TString::AllEntry(char* val)
{
	int tmp = strlen(val);
	int count = 0;
	for (int i = 0; i < len - tmp + 1; ++i)
	{
		if (str[i] == val[0])
		{
			bool flag = true;
			for (int j = 1; j < tmp; ++j)
			{
				if (str[i + j] != val[j])
				{
					flag = false;
				}
			}
			if (flag == true)
			{
				count++;
				i += tmp - 1;
			}
		}
	}
	return count;
}

void TString::AllIndexEntry(char* val)
{
	unsigned* res = new unsigned[AllEntry(val)];
	int tmp = strlen(val);
	int count = 0;
	for (int i = 0; i < len - tmp + 1; ++i)
	{
		if (str[i] == val[0])
		{
			bool log = true;
			for (int j = 1; j < tmp; ++j)
			{
				if (str[i + j] != val[j])
				{
					log = false;
				}
			}
			if (log == true)
			{
				res[count] = i;
				cout << res[count] << endl;
				count++;
				i += tmp - 1;
			}
		}
	}
}
char TString::MostEntry()
{
	int counter = 0, max = 0;
	char res = ' ', tmp = 0;
	for(int i = 0; i < len ; i++)
	{
		for (int j = 0; j < len; j++)
		{
			if (str[i] == res)
			{
				break;
			}
			if ((str[j] == str[i]))
			{
				counter++;
				tmp = str[i];
			}
		}
		if (counter > max)
		{
			max = counter;
			res = tmp;
		}
		else if (counter == max)
			res = '0';
		counter = 0;
	}
	return res;
}

void TString::SymbolAndQuantity()
{
	int counter = 0, tmp = 0;
	char* arr = new char[len];
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < counter; j++)
		{
			if (arr[j] == str[i])
			{
				tmp++;
				break;
			}
		}
		if (tmp == 0)
		{
			arr[counter] = str[i];
			counter++;
		}
		tmp = 0;
	}
	for (int i = 0; i < counter; i++)
	{
		for (int j = 0; j < len; j++)
		{
			if (arr[i] == str[j])
				tmp++;
		}
		cout << arr[i] << " - " << tmp << endl;
		tmp = 0;
	}
}

char* TString::LineWithoutRepetitions()
{
	int counter = 0, tmp = 0;
	char* arr = new char[len];
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < counter; j++)
		{
			if (arr[j] == str[i])
			{
				tmp++;
				break;
			}
		}
		if (tmp == 0)
		{
			arr[counter] = str[i];
			counter++;
		}
		tmp = 0;
	}
	char* res = new char[counter + 1];
	for (int i = 0; i < counter; i++)
	{
		res[i] = arr[i];
	}
	res[counter] = '\0';
	return res;
}

bool TString::operator != (TString& val)
{
	if (len != val.len)
		return true;
	bool res = false;
	for (int i = 0; i < len; i++)
	{
		if (str[i] != val.str[i])
			res = true;
	}
	return res;
}

TString TString::operator + (TString& val)
{
	char* res = new char[len + val.len + 1];
	for (int i = 0; i < len; i++)
		res[i] = str[i];
	for (int i = 0; i < val.len; i++)
		res[i + len] = val.str[i];
	res[len + val.len] = '\0';
	return TString(res);
}

TString TString::operator*(unsigned len_)
{

	if (len_ < 0)
		throw("len_ < 0");
	char* res = new char[len * len_ + 1];
	if (len_ == 0)
	{
		res = nullptr;
		return TString(res);
	}
	else if (len_ > 1)
	{
		for (int i = 0; i < len_; i++)
		{
			for (int j = 0; j < len; j++)
				res[len * i + j] = str[j];
		}
		res[len_ * len] = '\0';
		return res;
	}
	else
	{
		for (int i = 0; i < len; i++)
		{
			res[i] = str[i];
		}
		res[len * len_] = '\0';
		return res;
	}
}

TString TString::operator=(TString& val)
{
	len = val.len;
	str = new char[len + 1];
	for (int i = 0; i < len; i++)
	{
		str[i] = val.str[i];
	}
	str[len] = '\0';
	return *this;
}

bool TString::operator==(TString& val)
{
	if (len == val.len)
	{
		for (int i = 0; i < len; i++)
		{
			if (str[i] != val.str[i])
				return false;
		}
		return true;
	}
	else
	{
		return false;
	}
}

bool TString::operator>(TString& val)
{
	return (len > val.len);
}

bool TString::operator<(TString& val)
{
	return (len < val.len);
}

char& TString::operator[](unsigned num)
{
	if (num < 0)
		throw("num < 0");
	return str[num];
}



ostream& operator << (ostream& out, TString& val)
{
	cout <<"Len - "<< val.len << endl <<"String - ";
	for (int i = 0; i < val.len; i++)
	{
		cout << val.str[i];
	}
	cout << endl;
	return out;
}

istream& operator >> (istream& inp, TString& val)
{
	char buf[256];
	cout << "Enter string - ";
	inp >> buf;
	val.SetStr(buf);
	return inp;
}
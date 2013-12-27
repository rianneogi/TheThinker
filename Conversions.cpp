#include "Conversions.h"
#include <iostream>
#include <sstream>
#include <string>


std::string Int2Str(int n)
{
	return static_cast<std::ostringstream*>( &(std::ostringstream() << n) )->str();
}

std::string Long2Str(unsigned long long n)
{
	if(n==0)
	{
		return "0";
	}
	std::string s = "";
	while(n!=0)
	{
		int a = n%10;
	    s = Int2Char(a) + s;
		n = n/10;
	}
	return s;
}

std::string Long2Str(unsigned long long n,int len)
{
	std::string s = "";
	int c = 0;
	while(c<len)
	{
		int a = n%10;
	    s = Int2Char(a) + s;
		n = n/10;
		c++;
	}
	return s;
}

int Str2Int(std::string s)
{
	return atoi(s.c_str());
}

unsigned long long Str2Long(std::string s)
{
	unsigned long long x = 0;
	unsigned long long i = 0;
	for(;i<s.length();i++)
	{
		x *= 10;
		x += Char2Int(s.at(i));
	}
	return x;
}

int Char2Int(char c)
{
	return (int(c)-48);
}

char Int2Char(int n)
{
	return (char(n)+48);
}
#include "fileops.h"
#include <string>
#include <deque>
#include <fstream>
#include <iostream>
#include "conversions.h"

using namespace std;

int filecount = 2;
int CHUNKSIZE = 100;

string filestrings[] = {"Files//Fibonacci//","Files//Factorial//","Files//powersof2//"};
string POSITIONSTRING = "positions.txt";
string NUMBERSTRING = "numbers.txt";
string COUNTSTRING = "count.txt";

string getLine(string filestring,unsigned long long line)
{
	//getting position
	string s = "0";
	unsigned long long x = line/100;
	unsigned long long y = line%100;
	string f = filestring + POSITIONSTRING;
	fstream file(f, ios::in | ios::out);
	if(!file.is_open())
		return "";
	for(int i = 0;i<=x;i++)
	{
		getline(file,s);
	}
	file.close();

	//getting number
	f = filestring + NUMBERSTRING;
	file.open(f, ios::in | ios::out);
	if(!file.is_open())
		return "";
	file.seekp(Str2Int(s));
	for(int i = 0;i<=y;i++)
	{
		getline(file,s);
	}
	file.close();
	return s;
}

deque<string> getLines(string filestring,unsigned long long beg,unsigned long count)
{
	//getting position
	string s;
	string f;
	deque<string> v;
	unsigned long long x = beg/100;
	unsigned long long y = beg%100;
	f = filestring + POSITIONSTRING;
	fstream file(f, ios::in | ios::out);
	if(!file.is_open())
		return v;
	for(int i = 0;i<x;i++)
	{
		getline(file,s);
	}
	file.close();

	//getting numbers
	f = filestring + NUMBERSTRING;
	file.open(f, ios::in | ios::out);
	file.seekg(Str2Int(s));
	for(int i = 0;i<y;i++)
	{
		getline(file,s);
	}
	v.push_back(s);
	for(unsigned long long i = 1;i<count;i++)
	{
		getline(file,s);
		v.push_back(s);
	}
	file.close();
	return v;
}

int printLines(string filestring,deque<string> v,unsigned long beg,unsigned long count)
{
	//getting count
	string f = filestring + COUNTSTRING;
	string s = "0";
	fstream file (f, ios::in | ios::out);
	if(!file.is_open())
		return -1;
	getline(file,s);
	int lines = Str2Int(s);
	file.close();
	//storing values
	f = filestring + NUMBERSTRING;
	file.open(f, ios::in | ios::out | ios::app);
	f = filestring + POSITIONSTRING;
	fstream file2(f,ios::in | ios::out | ios::app);
	if(!file.is_open() || !file2.is_open())
		return -2;
	for(unsigned long i = beg;i<beg+count;i++)
	{
		file << endl;
		if((i+lines-beg+1)%CHUNKSIZE == 1)
		{
			file2 << endl << file.tellp();
		}
		file << v.at(i);
	}
	file.close();
	file2.close();

	//setting count
	f = filestring + COUNTSTRING;
	file.open(f,ios::in | ios::out | ios::trunc);
	if(!file.is_open())
		return -3;
	file << (count+lines);
	file.close();
	return 0;
}

unsigned long long getCount(string filestring)
{
	string f = filestring + COUNTSTRING;
	fstream file(f,ios::in | ios::out);
	getline(file,f);
	file.close();
	return Str2Int(f);
}



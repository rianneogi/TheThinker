#pragma once

#include <string>
#include <deque>

using namespace std;

deque<string> getLines(string filestring,unsigned long long beg,unsigned long count);
string getLine(string filestring,unsigned long long line);
int printLines(string filestring,deque<string> v,unsigned long beg,unsigned long count);
unsigned long long getCount(string filestring);
#pragma once

#include <string>

std::string Int2Str(int n);
std::string Long2Str(unsigned long long n);
std::string Long2Str(unsigned long long n,int len); //makes a string of length len
int Str2Int(std::string s);
unsigned long long Str2Long(std::string s);
int Char2Int(char c);
char Int2Char(int n);
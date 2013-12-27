#pragma once

#include <vector>

std::vector<unsigned long long> getDigits(unsigned long long n);
bool haveSameDigits(unsigned long long a,unsigned long long b);

//generates a bool vector of size n, if vector.at(x) is true then x+1 is an abundant number else it is not
std::vector<bool> generateAbundantNumberSieve(unsigned long long n); 

//generates a bool vector of size n, if vector.at(x) is true then x+1 is an prime number else it is not
std::vector<bool> generatePrimeSieve(unsigned long long n);

//calculates factorial of n
unsigned long long factorial(unsigned long long n);

//calculates the digit factorial i.e. if n = 143 , digit factorial = 1! + 4! + 3! = 31 (sum of factorials of the digits)
unsigned long long calcDigitFactorial(std::string n);
unsigned long long calcDigitFactorial(unsigned long long n);

//calculates the sum of proper divisors of n
unsigned long long sumOfDivisors(unsigned long long n);

//calculates the number of ways you can divide n coins into groups such that each group contains a maximum of m coins
//uses recursion and dynamic programming so initialize partitions_arr before running
//make sure m<=n
unsigned long long partitions(unsigned long long n,unsigned long long m);

//calculates the number of ways you can divide n coins into groups such that each group contains a prime number of coins and a maximum of m coins
//uses recursion and dynamic programming so initialize partitions_arr before running
//make sure m<=n
unsigned long long primepartitions(unsigned long long n,unsigned long long m);
                                                                 
#include "MathFunctions.h"
#include "Conversions.h"
#include <iostream>
#include "stdlib.h"
#include <conio.h>

std::vector<unsigned long long> getDigits(unsigned long long n)
{
	std::string s = Long2Str(n);
	std::vector<unsigned long long> v(10);
	for(unsigned long long i = 0;i<s.length();i++)
	{
		v.at(Char2Int(s.at(i)))++;
	}
	return v;
}

bool haveSameDigits(unsigned long long a,unsigned long long b)
{
	std::vector<unsigned long long> v1 = getDigits(a);
	std::vector<unsigned long long> v2 = getDigits(b);
	for(int i = 0;i<10;i++)
	{
		if(v1.at(i)!=v2.at(i))
		{
			return false;
		}
	}
	return true;
}

std::vector<bool> generateAbundantNumberSieve(unsigned long long n)
{
	std::vector<bool> v(n);
	if(n<12)
	{
		return v;
	}
	for(unsigned long long i = 12;i<=n;i++)
	{
		if(v.at(i-1)==false)
		{
			unsigned long long sum = 1;
			for(unsigned long long j = 2;j<=sqrt(i);j++) //getting sum of factors
			{
				if(i%j==0)
				{
					sum += j;
					if(j!=i/j)
						sum += i/j;
				}
			}
			if(sum>i) //if sum>i then it is an abundant number
			{
				unsigned long long x = i;
				while(x<=n) //sieving
				{
					v.at(x-1) = true;
					x = x*2;
				}
			}
		}
	}
	return v;
}

std::vector<bool> generatePrimeSieve(unsigned long long n)
{
	std::vector<bool> v(n,true);
	std::vector<unsigned long long> v2;
	unsigned long long sqr = sqrt(n);
	if(n==0)
	{
		return v;
	}
	if(n>1)
	{
		v.at(0) = false;
	}
	if(n>1)
	{
		v2.push_back(2);
		for(unsigned long long j = 4;j<=n;j=j+2) //sieve multiples of 2
		{
			v.at(j-1) = false;
		}
	}
	if(n>2)
	{
		v2.push_back(3);
		for(unsigned long long j = 6;j<=n;j=j+3) //sieve multiples of 3
		{
			v.at(j-1) = false;
		}
	}
	for(unsigned long long i = 1;;i++)
	{
		unsigned long long x = 6*i - 1;
		if(x > sqr)
			break;
		if(v.at(x-1)==true)
		{
			int flag = 0;
			unsigned long long xsr = sqrt(x);
			for(unsigned long long j = 0;j<=v2.size();j++)
			{
				unsigned long long pr = v2.at(j);
				if(x%pr==0)
				{
					flag = 1;
				}
				if(pr>xsr)
				{
					break;
				}
			}
			if(flag==0) //x is prime
			{
				v2.push_back(x);
				for(unsigned long long j = x+x;j<=n;j=j+x) //sieve multiples of x
				{
					v.at(j-1) = false;
				}
			}
		}
		x = 6*i + 1;
		if(x > sqr)
			break;
		if(v.at(x-1)==true)
		{
			int flag = 0;
			unsigned long long xsr = sqrt(x);
			for(unsigned long long j = 0;j<=v2.size();j++)
			{
				unsigned long long pr = v2.at(j);
				if(x%pr==0)
				{
					flag = 1;
				}
				if(pr>xsr)
				{
					break;
				}
			}
			if(flag==0) //x is prime
			{
				v2.push_back(x);
				for(unsigned long long j = x+x;j<=n;j=j+x) //sieve multiples of x
				{
					v.at(j-1) = false;
				}
			}
		}
	}
	return v;
}

unsigned long long factorial(unsigned long long n)
{
	if(n==0)
		return 1;
	unsigned long long p = n;
	for(int i = n-1;i>1;i--)
	{
		p*=i;
	}
	return p;
}

unsigned long long calcDigitFactorial(std::string n)
{
	unsigned long long sum = 0;
	for(unsigned long long i = 0;i<n.length();i++)
	{
		sum += factorial(Char2Int(n.at(i)));
	}
	return sum;
}

unsigned long long calcDigitFactorial(unsigned long long n)
{
	return calcDigitFactorial(Long2Str(n));
}

unsigned long long sumOfDivisors(unsigned long long n)
{
	unsigned long long sum = 1;
	for(unsigned long long i = 2;i<=sqrt(n);i++)
	{
		if(n%i==0)
		{
			sum += i;
			if(i!=n/i)
			{
				sum += n/i;
			}
		}
	}
	return sum;
}

unsigned long long partitions_arr[12000][12000]; //stores values of partitions(n,m)

unsigned long long partitions(unsigned long long n,unsigned long long m)
{
	if(n==0)
		return 1;
	if(n==1)
		return 1;
	if(m==0)
		return 0;
	if(m==1)
		return 1;
	if(partitions_arr[n][m] != 0)
		return partitions_arr[n][m];
	unsigned long long s = 0;
	for(unsigned long long i = m;i>0;i--)
	{
		s = s + partitions(n-i,std::min(i,n-i));
		if(s>1000000)     //uncomment this if you want the value mod 1000000
			s = s%1000000;
	}
	partitions_arr[n][m] = s;
	return s;
}

unsigned long long primepartitions_arr[10000][10000]; //stores values of primepartitions(n,m)

unsigned long long primepartitions(unsigned long long n,unsigned long long m)
{
	if(n==0)
		return 1;
	if(n==1)
		return 0;
	/*if(n==2)
		return 1;
	if(n==3)
		return 1;*/
	if(m==0)
		return 0;
	if(m==1)
		return 0;
	if(primepartitions_arr[n][m] != 0)
		return primepartitions_arr[n][m];
	unsigned long long s = 0;
	for(unsigned long long i = m;i>1;i--)
	{
		int flag = 0;
		for(unsigned long long j = 2;j<=sqrt(i);j++)
		{
			if(i%j==0)
			{
				flag = 1;
				break;
			}
		}
		if(flag==0)
		{
			s = s + primepartitions(n-i,std::min(i,n-i));
			/*if(s>1000000)     //uncomment this if you want the value mod 1000000
				s = s%1000000;*/
		}
	}
	primepartitions_arr[n][m] = s;
	return s;
}
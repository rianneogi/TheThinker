#pragma once

#include <string>
#include <deque>
class Integer
{
public:
	std::deque<unsigned long long> digits;
	unsigned long long base;

	///Constructors/Destructors
	Integer();
	Integer(std::string s);
	Integer(std::string s,unsigned long long b);
	Integer(std::string s,unsigned long long b1,unsigned long long b2);
	Integer(unsigned long long n);
	Integer(unsigned long long n,unsigned long long b);
	Integer(unsigned long long n,unsigned long long b1,unsigned long long b2);
	Integer(std::deque<unsigned long long> v);
	Integer(std::deque<unsigned long long> v,unsigned long long b);
	Integer(Integer const& n);
	Integer(Integer const& n,unsigned long long b);
	~Integer();

	///Operators
	Integer operator=(Integer const& n); //O(n)
	bool operator==(Integer const& n) const; //O(n)
	bool operator<(Integer const& n) const; //O(n)
	bool operator>(Integer const& n) const; //O(n)
	bool operator<=(Integer const& n) const; //O(n)
	bool operator>=(Integer const& n) const;  //O(n)
	Integer operator++();
	Integer operator--();
	Integer& operator++(int n);
	Integer& operator--(int n);
	Integer operator+(Integer const& n) const; //O(n)
	Integer operator+(std::string n) const;
	Integer operator+(unsigned long long n) const;
	Integer operator-(Integer const& n) const; //O(n)
	Integer operator-(std::string n) const;
	Integer operator-(unsigned long long n) const;
	Integer operator*(Integer const& n) const; //O(n^2)
	Integer operator*(std::string n) const;
	Integer operator*(unsigned long long n) const;
	Integer operator/(Integer const& n) const; //O(n^3)
	Integer operator/(std::string n) const;
	Integer operator/(unsigned long long n) const;
	Integer operator%(Integer const& n) const; //O(n^3)
	Integer operator%(std::string n) const;
	Integer operator%(unsigned long long n) const;
	Integer operator+=(Integer const& n); //O(n)
	Integer operator+=(std::string n);
	Integer operator+=(unsigned long long n);
	Integer operator-=(Integer const& n); //O(n)
	Integer operator-=(std::string n);
	Integer operator-=(unsigned long long n);
	Integer operator*=(Integer const& n); //O(n^2)
	Integer operator*=(std::string n);
	Integer operator*=(unsigned long long n);
	Integer operator/=(Integer const& n); //O(n^3)
	Integer operator/=(std::string n);
	Integer operator/=(unsigned long long n);
	Integer operator%=(Integer const& n); //O(n^3)
	Integer operator%=(std::string n);
	Integer operator%=(unsigned long long n);
	Integer operator>>(Integer const& n) const;
	Integer operator<<(Integer const& n) const;
	Integer operator>>(unsigned long long n) const;
	Integer operator<<(unsigned long long n) const;
	
	///IO related
	std::string value() const; //O(n)
	std::string decimalValue() const; //O(n^5)
	std::string textValue() const; //O(n)

	///Basic Functions
	void changeBase(unsigned long long b);
	bool isPrime() const;
	bool isProbablePrime(unsigned long long k) const;
	bool isPandigital() const; //is 1-9 pandigital
	bool isPandigital2() const; //is 0-9 pandigital
	Integer modexp(Integer const& e,Integer const& n) const; //returns val^e mod n
	Integer half() const; //O(n)
	bool isEven() const; //O(1)
};

///Extra functions
Integer ConvertBase(Integer const& n,unsigned long long b);
Integer GCD(Integer const& a,Integer const& b);
Integer max(Integer const& a,Integer const& b);
Integer min(Integer const& a,Integer const& b);

///IO functions
std::string valueOf(Integer const& n);
Integer createFromText(std::string s,unsigned long long b);

//calculates the number of ways you can divide n coins into groups such that each group contains a maximum of m coins
//uses recursion and dynamic programming so initialize partitions_arr before running
//make sure m<=n
Integer partitionsBig(unsigned long long n,unsigned long long m);
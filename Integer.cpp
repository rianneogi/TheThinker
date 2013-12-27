#include "integer.h"
#include "conversions.h"
#include <string>
#include <deque>
#include <iostream>
#include <stack>

///Constructors/Destructors
Integer::Integer()
{
	digits = std::deque<unsigned long long>();
	digits.push_back(0);
	base = 10;
}

Integer::Integer(std::string s)
{
	digits = std::deque<unsigned long long>();
	for(unsigned long i = s.length();i!=0;i--)
	{
		digits.push_back(Char2Int(s.at(i-1)));	
	}
	base = 10;
}

Integer::Integer(std::string s,unsigned long long b)
{
	digits = std::deque<unsigned long long>();
	for(unsigned long i = s.length();i!=0;i--)
	{
		digits.push_back(Char2Int(s.at(i-1)));	
	}
	base = b;
}

Integer::Integer(std::string s,unsigned long long b1,unsigned long long b2)
{
	digits = std::deque<unsigned long long>();
	for(unsigned long i = s.length();i!=0;i--)
	{
		digits.push_back(Char2Int(s.at(i-1)));	
	}
	base = b1;
	changeBase(b2);
}

Integer::Integer(unsigned long long n)
{
	std::string s = Long2Str(n);
	digits = std::deque<unsigned long long>();
	for(unsigned long i = s.length();i!=0;i--)
	{
		digits.push_back(Char2Int(s.at(i-1)));	
	}
	base = 10;
}

Integer::Integer(unsigned long long n,unsigned long long b)
{
	std::string s = Int2Str(n);
	digits = std::deque<unsigned long long>();
	for(unsigned long i = s.length();i!=0;i--)
	{
		digits.push_back(Char2Int(s.at(i-1)));	
	}
	base = b;
}

Integer::Integer(unsigned long long n,unsigned long long b1,unsigned long long b2)
{
	std::string s = Int2Str(n);
	digits = std::deque<unsigned long long>();
	for(unsigned long i = s.length();i!=0;i--)
	{
		digits.push_back(Char2Int(s.at(i-1)));	
	}
	base = b1;
	changeBase(b2);
}

Integer::Integer(std::deque<unsigned long long> v)
{
	digits = v;
	base = 10;
}

Integer::Integer(std::deque<unsigned long long> v,unsigned long long b)
{
	digits = v;
	base = b;
}

Integer::Integer(Integer const& n)
{
	digits = std::deque<unsigned long long>();
	for(int i = 0;i<n.digits.size();i++)
	{
		digits.push_back(n.digits.at(i));	
	}
	base = n.base;
}

Integer::Integer(Integer const& n,unsigned long long b)
{
	digits = std::deque<unsigned long long>();
	for(int i = 0;i<n.digits.size();i++)
	{
		digits.push_back(n.digits.at(i));	
	}
	base = n.base;
	changeBase(b);
}

Integer::~Integer()
{
}

///Operators
Integer Integer::operator=(Integer const& n)
{
	digits.clear();
	for(int i = 0;i<n.digits.size();i++)
	{
		digits.push_back(n.digits.at(i));
	}
	base = n.base;
	return *this;
}

bool Integer::operator==(Integer const& n) const
{
	for(int i = 0;i<digits.size();i++)
	{
		if(digits.at(i)!=n.digits.at(i))
		{
			return false;
		}
	}
	return true;
}

bool Integer::operator<(Integer const& n) const
{
	unsigned long s1 = digits.size();
	unsigned long s2 = n.digits.size();
	if(s1 < s2)
	{
		return true;
	}
	else if(s1 > s2)
	{
		return false;
	}
	else
	{
		for(unsigned long long i = s1-1;i>=0;i--)
		{
			unsigned long long a1 = digits.at(i);
			unsigned long long a2 = n.digits.at(i);
			if(a1 < a2)
			{
				return true;
			}
			else if(a1 > a2)
			{
				return false;
			}
			if(i==0)
			{
				break;
			}
		}
	}
	return false;
}

bool Integer::operator>(Integer const& n) const
{
	unsigned long s1 = digits.size();
	unsigned long s2 = n.digits.size();
	if(s1 > s2)
	{
		return true;
	}
	else if(s1 < s2)
	{
		return false;
	}
	else
	{
		for(unsigned long long i = s1-1;i>=0;i--)
		{
			unsigned long long a1 = digits.at(i);
			unsigned long long a2 = n.digits.at(i);
			if(a1 > a2)
			{
				return true;
			}
			else if(a1 < a2)
			{
				return false;
			}
			if(i==0)
			{
				break;
			}
		}
	}
	return false;
}

bool Integer::operator<=(Integer const& n) const
{
	unsigned long s1 = digits.size();
	unsigned long s2 = n.digits.size();
	if(s1 < s2)
	{
		return true;
	}
	else if(s1 > s2)
	{
		return false;
	}
	else
	{
		for(unsigned long long i = s1-1;i>=0;i--)
		{
			unsigned long long a1 = digits.at(i);
			unsigned long long a2 = n.digits.at(i);
			if(a1 < a2)
			{
				return true;
			}
			else if(a1 > a2)
			{
				return false;
			}
			if(i==0)
			{
				break;
			}
		}
	}
	return true;
}

bool Integer::operator>=(Integer const& n) const
{
	unsigned long s1 = digits.size();
	unsigned long s2 = n.digits.size();
	if(s1 > s2)
	{
		return true;
	}
	else if(s1 < s2)
	{
		return false;
	}
	else
	{
		for(unsigned long long i = s1-1;i>=0;i--)
		{
			unsigned long long a1 = digits.at(i);
			unsigned long long a2 = n.digits.at(i);
			if(a1 > a2)
			{
				return true;
			}
			else if(a1 < a2)
			{
				return false;
			}
			if(i==0)
			{
				break;
			}
		}
	}
	return true;
}

Integer Integer::operator++()
{
	Integer one("1");
	Integer a = *this;
	*this = *this + one;
	return a;
}

Integer Integer::operator--()
{
	Integer one("1");
	Integer a = *this;
	*this = *this + one;
	return a;
}

Integer& Integer::operator++(int n)
{
	Integer one("1");
	*this = *this+one;
	return *this;
}
	
Integer& Integer::operator--(int n)
{
	Integer one("1");
	*this = *this-one;
	return (*this);
}

Integer Integer::operator+(Integer const& n) const
{
	std::deque<unsigned long long> ans = std::deque<unsigned long long>();
	unsigned long s1 = digits.size();
	unsigned long s2 = n.digits.size();
	unsigned long big = s1;
	unsigned long small = s2;
	std::deque<unsigned long long> bigone = this->digits;
	if(s2>s1)
	{
		big = s2;
		small = s1;
		bigone = n.digits;
	}
	unsigned long long carry = 0;
	unsigned long long sum = 0;
	for(unsigned long i = 0;i<=big;i++)
	{
		if(i<small)
		{
			unsigned long long a1 = digits.at(i);
			unsigned long long a2 = n.digits.at(i);
			sum = (a1+a2+carry)%base;
			carry = (a1+a2+carry)/base;
			ans.push_back(sum);
		}
		else if(i<big)
		{
			if(carry>0)
			{
				unsigned long long a = carry+bigone.at(i);
				ans.push_back(a%base);
				carry = a/base;
			}
			else
			{
				ans.push_back(bigone.at(i));
			}
		}
		else
		{
			if(carry!=0)
			    ans.push_back(carry);
		}
	}

	return Integer(ans,base);
}

Integer Integer::operator+(std::string n) const
{
	Integer a(n);
	return ((*this)+a);
}

Integer Integer::operator+(unsigned long long n) const
{
	Integer a(n);
	return ((*this)+a);
}

Integer Integer::operator-(Integer const& n) const
{
	if(*this<=n)
		return Integer("0",base);
	std::deque<unsigned long long> ans = std::deque<unsigned long long>();
	Integer x(*this);
	unsigned long len1 = x.digits.size();
	unsigned long len2 = n.digits.size();
	for(unsigned long i = 0;i<len1;i++)
	{
		if(i<len2)
		{
		    short a1 = x.digits.at(i);
			short a2 = n.digits.at(i);
			if(a1<a2)
			{
				a1 = base+a1;
				x.digits.at(i+1) = x.digits.at(i+1)-1;
			}
			ans.push_back(a1 - a2);
		}
		else
		{
			ans.push_back(x.digits.at(i));
		}
	}
	while(ans.at(ans.size()-1)==0 && ans.size()!=1)
	{
		ans.pop_back();
	}
	return Integer(ans,base);
}

Integer Integer::operator-(std::string n) const
{
	Integer a(n);
	return ((*this)-a);
}

Integer Integer::operator-(unsigned long long n) const
{
	Integer a(n);
	return ((*this)-a);
}

Integer Integer::operator*(Integer const& n) const
{
	if(digits.at(0)==0 && digits.size()<2)
		return Integer("0");
	if(n.digits.at(0)==0 && n.digits.size()<2)
		return Integer("0");
	if(digits.at(0)==1 && digits.size()<2)
		return n;
	std::deque<Integer> b;
	b.push_back(n);
	Integer z("0",base);
	int dir = 0;
    while(b.size()!=0)
	{
		Integer y = b.at(b.size()-1);
		if(y.digits.at(0)==0 && y.digits.size()<2)
		{
			dir = 1;
			b.pop_back();
			continue;
		}
		if(dir==0)
		{
			Integer o;
			if(base==2)
			{
				o = y>>1;
			}
			else
			{
				o = y.half();
			}
		    b.push_back(o);
		}
		else
		{
			if(y.isEven())
			{
				z = z+z;
			}
			else
			{
				z = *this+z+z;
			}
			b.pop_back();
		}
	}
	return z;
}

Integer Integer::operator*(std::string n) const
{
	Integer a(n);
	return ((*this)*a);
}

Integer Integer::operator*(unsigned long long n) const
{
	Integer a(n);
	return ((*this)*a);
}

Integer Integer::operator/(Integer const& n) const
{
	if(n.digits.at(0)==0 && n.digits.size()<2)
		return Integer("");
    std::deque<Integer> b;
	b.push_back(*this);
	int dir = 0;
	Integer q("0",base);
	Integer r("0",base);
	Integer one("1",base);
	while(b.size()!=0)
	{
		Integer x = b.at(b.size()-1);
		if(x.value()=="0")
		{
			dir = 1;
			b.pop_back();
			continue;
		}
		if(dir==0)
		{
			Integer o;
			if(base==2)
				o = x>>1;
			else
				o = x.half();
		    b.push_back(o);
		}
		else
		{
			q = q+q;
			r = r+r;
			if(x.isEven()==false)
			{
				r = r+one;
			}
			if(r>=n)
			{
				q = q+one;
				r = r-n;
			}
			b.pop_back();
		}
	}
	return q;
}

Integer Integer::operator/(std::string n) const
{
	Integer a(n);
	return ((*this)/a);
}

Integer Integer::operator/(unsigned long long n) const
{
	Integer a(n);
	return ((*this)/a);
}

Integer Integer::operator%(Integer const& n) const
{
	if(n.digits.at(0)==0 && n.digits.size()<2)
		return Integer("");
    std::deque<Integer> b;
	b.push_back(*this);
	int dir = 0;
	Integer r("0",base);
	Integer one("1",base);
	while(b.size()!=0)
	{
		Integer x = b.at(b.size()-1);
		if(x.value()=="0")
		{
			dir = 1;
			b.pop_back();
			continue;
		}
		if(dir==0)
		{
			Integer o;
			if(base==2)
				o = x>>1;
			else
				o = x.half();
		    b.push_back(o);
		}
		else
		{
			r = r+r;
			if(x.isEven()==false)
				r = r+one;
			if(r>=n)
			{
				r = r-n;
			}
			b.pop_back();
		}
	}
	return r;
}

Integer Integer::operator%(std::string n) const
{
	Integer a(n);
	return ((*this)%a);
}

Integer Integer::operator%(unsigned long long n) const
{
	Integer a(n);
	return ((*this)%a);
}

Integer Integer::operator>>(Integer const& n) const
{
	Integer a = *this;
	for(Integer i("0",n.base);i<n;++i)
	{
		if(a.digits.size()==1)
		{
			a.digits.at(0) = 0;
			break;
		}
		a.digits.pop_front();
	}
	return a;
}

Integer Integer::operator>>(unsigned long long n) const
{
	Integer a = *this;
	for(unsigned long long i = 0;i<n;i++)
	{
		if(a.digits.size()==1)
		{
			a.digits.at(0) = 0;
			break;
		}
		a.digits.pop_front();
	}
	return a;
}

Integer Integer::operator<<(Integer const& n) const
{
	Integer a = *this;
	for(Integer i("0",n.base);i<n;++i)
	{
		a.digits.push_front(1);
	}
	return a;
}

Integer Integer::operator<<(unsigned long long n) const
{
	Integer a = *this;
	for(unsigned long long i = 0;i<n;i++)
	{
		a.digits.push_front(0);
	}
	return a;
}

///IO related
std::string Integer::value() const
{
	std::string s = "";
	for(unsigned long i = digits.size();i;i--)
	{
		char c = char(digits.at(i-1));
	    s += char('0'+c);
	}
	return s;
}

std::string Integer::decimalValue() const
{
	Integer ans = *this;
	ans.changeBase(10);
	std::string s = "";
	for(unsigned long i = ans.digits.size();i;i--)
	{
		char c = char(ans.digits.at(i-1));
	    s += char('0'+c);
	}
	return s;
}

std::string Integer::textValue() const
{
	std::string s = "";
	for(unsigned long i = digits.size();i;i--)
	{
		s += Long2Str(digits.at(i-1));
		if(i!=1)
			s+="_";
	}
	return s;
}

Integer createFromText(std::string s,unsigned long long b)
{
	unsigned long long pos = 0;
	unsigned long long count = 0;
	Integer k ("0",b);
	for(unsigned long long i = 0;i<s.length();i++)
	{
		if(s.at(i)=='_')
		{
			std::string a = s.substr(pos,i-pos);
			if(count == 0)
			{
				k.digits.at(0) = Str2Long(a);
			}
			else
			{
				k.digits.push_front(Str2Long(a));
			}
			pos = i+1;
			count++;
		}
		else if(i == s.length()-1)
		{
			std::string a = s.substr(pos,i-pos+1);
			if(count == 0)
			{
				k.digits.at(0) = Str2Long(a);
			}
			else
			{
				k.digits.push_front(Str2Long(a));
			}
			//pos = i+1;
			//count++;
		}
	}
	return k;
}

///Basic functions
bool Integer::isEven() const
{
	if(digits.size()<1)
		return true;
	unsigned long long x = digits.at(0)%2;
	if(x==0)
		return true;
    return false;
}

bool Integer::isPandigital() const
{
	int c[9] = {0,0,0,0,0,0,0,0,0};
	for(int i = 0;i<digits.size();i++)
	{
		if(digits.at(i)!=0)
		{
		    c[digits.at(i)-1]++;
		}
	}
	for(int i = 0;i<9;i++)
	{
		if(c[i]==0)
			return false;
	}
	return true;
}

bool Integer::isPandigital2() const
{
	int c[10] = {0,0,0,0,0,0,0,0,0,0};
	for(int i = 0;i<digits.size();i++)
	{
		c[digits.at(i)]++;
	}
	for(int i = 0;i<10;i++)
	{
		if(c[i]==0)
			return false;
	}
	return true;
}

Integer Integer::half() const
{
	Integer a("0",base);
	a.digits.clear();
	int n = digits.size();
	for(unsigned long i = 0;i<n;i++)
	{
		if(i==0)
		{
		    a.digits.push_back(digits.at(i)/2);
		}
		else
		{
		    int c = digits.at(i);	
		    if(c%2==0)
			{
			    a.digits.push_back(c/2);
			}
			else
			{
				int prev = a.digits.at(i-1);
				a.digits.pop_back();
				a.digits.push_back(prev+(base/2));
				a.digits.push_back(c/2);
			}
		}
	}
	if(a.digits.at(n-1)==0 && a.digits.size()!=1)
		a.digits.pop_back();
	return a;
}

Integer max(Integer const& a,Integer const& b)
{
	if(a>b)
		return a;
	else
		return b;
}

Integer min(Integer const& a,Integer const& b)
{
	if(a<b)
		return a;
	else
		return b;
}

Integer Integer::modexp(Integer  const& e,Integer  const& n) const
{
	Integer one("1",base);
	if(valueOf(e)=="0")
	{
		return one;
	}
	std::deque<Integer> y;
	std::deque<Integer> z;
	y.push_back(e);
	int dir = 0;
	Integer r("0",base);
	while(y.size()!=0)
	{
		Integer x = y.at(y.size()-1);
		if(x.value()=="0")
		{
			dir = 1;
			y.pop_back();
			r = one;
			continue;
		}
		if(dir==0)
		{
			Integer o("1");
			if(base==2)
				o = x>>1;
			else
				o = x.half();
			y.push_back(o);
		}
		else
		{
			if(x.isEven())
			{
				r = (r*r)%n;
				y.pop_back();
			}
			else
			{
				r = ((r*r)*(*this))%n;
				y.pop_back();
			}
		}
	}
	return r;
}

Integer GCD(Integer const& a,Integer const& b)
{
	std::deque<Integer> x;
	std::deque<Integer> y;
	x.push_back(a);
	y.push_back(b);
	Integer r("0");
	while(x.size()!=0)
	{
		Integer n = x.at(x.size()-1);
		Integer m = y.at(y.size()-1);
		if(m.value()=="0")
		{
			r = n;
			break;
		}
		x.push_back(m);
		y.push_back(n%m);
	}
	return r;
}

Integer partitionsBig_arr[100][100];

Integer partitionsBig(unsigned long long n,unsigned long long m)
{
	if(n==0)
		return Integer("1");
	if(m==0)
		return Integer("0");
	if(m==1)
		return Integer("1");
	if(partitionsBig_arr[n][m].value() != "0")
		return partitionsBig_arr[n][m];
	if(n==1)
		return Integer("1");
	Integer s("0");
	for(unsigned long long i = m;i>0;i--)
	{
		partitionsBig_arr[n-i][i] = partitionsBig(n-i,std::min(i,n-i));
		s = s + partitionsBig_arr[n-i][i];
	}
	return s;
}

bool Integer::isProbablePrime(unsigned long long k) const
{
	Integer one("1",base);
	for(unsigned long long i = 0;i<k;i++)
	{
		Integer a(Int2Str(rand()),10);
		Integer x = (*this) - one;
		a = (a%x)+one;
		if(a.modexp(x,*this).value() != "1")
		{
			return false;
		}
	}
	return true;
}

void Integer::changeBase(unsigned long long b)
{
	if(base == b)
		return;
	*this = ConvertBase(*this,b);
	base = b;
}

Integer ConvertBase(Integer const& n,unsigned long long b)
{
	if(b==n.base)
	{
		Integer ans = n;
		return ans;
	}
	Integer a("0",10);
	Integer ans("0",b);
	std::string s = "";
	//converting to base 10
	Integer c("1",10);
	for(unsigned long long i = 0;i<n.digits.size();i++)
	{
		Integer d = c*(n.digits.at(i));
		a = a+d;
		c = c*(n.base);
	}
	if(b==10)
	{
		return a;
	}
	//converting from base 10 to base b
	for(unsigned long long i = 0;(a.digits.at(0)!=0)||(a.digits.size()>1);i++)
	{
		Integer y = a%b;
		unsigned long long x = Str2Long(y.value());
		if(i==0)
			ans.digits.at(0) = x;
		else
			ans.digits.push_back(x);
		a = a/b;
	}
	return ans;
}

std::string valueOf(Integer const& n)
{
	return n.value();
}
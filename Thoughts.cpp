#include <iostream>
#include <future>
#include <deque>
#include <string>
#include <atomic>
#include <fstream>
#include "Thoughts.h"

using namespace std;

const unsigned long MAXSIZE = 10000;

atomic_flag stop = ATOMIC_FLAG_INIT;

int ProjectEuler() //Problem 104
{
	fstream file("Files/Fibonacci/positions.txt",ios::in | ios::out);
	string s;
	string a;
	string b;
	for(int i = 0;i<550;i++)
	{
		getline(file,s);
	}
	file.close();
	file.open("Files/Fibonacci/numbers.txt",ios::in | ios::out);
	file.seekg(Str2Int(s));
	cout << "init done" << endl;
	for(int i = 0;true;i++)
	{
		getline(file,s);
		a = s.substr(0,9);
		b = s.substr(s.length()-9,s.length()-1);
		if(Integer(a).isPandigital() && Integer(b).isPandigital())
		{
			cout << "FOUND IT " << (55000+i) << endl;
			cout << s << endl;
			break;
		}
		if(i%500==0)
		{
			cout << (55000+i) << endl;
		}
	}
	return 0;
}

int getFibonacci()
{
	unsigned int n;
	try
	{
		cin >> n;
	}catch(exception e){cout << "Invalid number" << endl;return -3;}
	if(n<=0)
	{
		cout << "Integer too small" << endl;
		return 3;
	}
	if(getCount("Files/Fibonacci/")<n)
	{
		cout << "Integer too big" << endl;
		return 1;
	}
    string s = getLine("Files/Fibonacci/",n-1);
	if(s=="")
	{
		cout << "Error occured. Could not retrieve number." << endl;
		return -1;
	}
	cout << "The " << n << "th fibonacci number is: " << endl << s << endl;
	return 0;
}

int calcFibonacci()
{
	//load
	cout << "Getting data..." << endl;
	deque<string> data;
    unsigned long long x = getCount("Files/Fibonacci/");
	string s = getLine("Files/Fibonacci/",x-2);
	if(s=="")
	{
		cout << "Error! Calculation was not executed." << endl;
		return -2;
	}
	data.push_back(s);
	s = getLine("Files/Fibonacci/",x-1);
	if(s=="")
	{
		cout << "Error! Calculation was not executed." << endl;
		return -2;
	}
	data.push_back(s);
	//calculate
	unsigned long siz = 2;
	cout << "Calculating..." << endl;
    while(stop.test_and_set(memory_order_acquire))
    {
		Integer a(data.at(siz-2));
		Integer b(data.at(siz-1));
        Integer z = a+b;
		string z2 = z.value();
        data.push_back(z2);
		siz++;
    }
    
	//save
	cout << "Saving data..." << endl;
	int o = printLines("Files/Fibonacci/",data,2,data.size()-2);
	if(o==-3)
	{
		cout << "Big error!! You should reset all files to initial setup before continuing." << endl;
		return -5;
	}
	else if(o!=0)
	{
		cout << "Error! Calculated data might not have been saved." << endl;
		return -3;
	}
	cout << "Fibonacci process was successful. I found " << (data.size()-2) << " fibonacci numbers("
		<< (x+1) << "-" << (x+data.size()-2) << ")." << endl;
	stop.clear();
	return 0;
}

int getFibonacci2()
{
	unsigned int n;
	try
	{
		cin >> n;
	}catch(exception e){cout << "Invalid number" << endl;return -3;}
	if(n<=0)
	{
		cout << "Integer too small" << endl;
		return 3;
	}
	if(getCount("Files/Fibonacci2/")<n)
	{
		cout << "Integer too big" << endl;
		return 1;
	}
    string s = getLine("Files/Fibonacci2/",n-1);
	if(s=="")
	{
		cout << "Error occured. Could not retrieve number." << endl;
		return -1;
	}
	cout << "The " << n << "th fibonacci number is: " << endl << s << endl;
	Integer fib = ConvertBase(createFromText(s,2305843009213693952),10);
	cout << "Its decimal value is: " << endl << fib.value() << endl; 
	return 0;
}

int calcFibonacci2()
{
	//load
	cout << "Getting data..." << endl;
	deque<string> data;
    unsigned long long x = getCount("Files/Fibonacci2/");
	string s = getLine("Files/Fibonacci2/",x-2);
	if(s=="")
	{
		cout << "Error! Calculation was not executed." << endl;
		return -2;
	}
	data.push_back(s);
	s = getLine("Files/Fibonacci2/",x-1);
	if(s=="")
	{
		cout << "Error! Calculation was not executed." << endl;
		return -2;
	}
	data.push_back(s);
	//calculate
	unsigned long siz = 2;
	cout << "Calculating..." << endl;
    while(stop.test_and_set(memory_order_acquire))
    {
		Integer a = createFromText(data.at(siz-2),2305843009213693952); //base 2^61
		Integer b = createFromText(data.at(siz-1),2305843009213693952); //base 2^61
        Integer z = a+b;
		string z2 = z.textValue();
        data.push_back(z2);
		siz++;
    }
    
	//save
	cout << "Saving data..." << endl;
	int o = printLines("Files/Fibonacci2/",data,2,data.size()-2);
	if(o==-3)
	{
		cout << "Big error!! You should reset all files to initial setup before continuing." << endl;
		return -5;
	}
	else if(o!=0)
	{
		cout << "Error! Calculated data might not have been saved." << endl;
		return -3;
	}
	cout << "Fibonacci process was successful. I found " << (data.size()-2) << " fibonacci numbers("
		<< (x+1) << "-" << (x+data.size()-2) << ")." << endl;
	stop.clear();
	return 0;
}

int getFactorial()
{
	unsigned int n;
	try
	{
		cin >> n;
	}catch(exception e){cout << "Invalid number" << endl;return -3;}
	if(n<0)
	{
		cout << "Integer too small" << endl;
		return 3;
	}
	if(getCount("Files/Factorial/")<n)
	{
		cout << "Integer too big" << endl;
		return 1;
	}
    string s = getLine("Files/Factorial/",n);
	if(s=="")
	{
		cout << "Error occured. Could not retrieve number." << endl;
		return -1;
	}
	cout << "The factorial of " << n << " is: " << endl << s << endl;
	return 0;
}

int calcFactorial()
{
	//load
	cout << "Getting data..." << endl;
	deque<string> data;
    unsigned long long x = getCount("Files/Factorial/");
	string s = getLine("Files/Factorial/",x-1);
	if(s=="")
	{
		cout << "Error! Calculation was not executed." << endl;
		return -2;
	}
	data.push_back(s);

	//calculate
	Integer k(Int2Str(x));
	Integer one("1");
	cout << "Calculating..." << endl;
    while(stop.test_and_set(memory_order_acquire))
    {
		Integer a(data.at(data.size()-1));
        Integer z = a*k;
		string z2 = z.value();
        data.push_back(z2);
		k = k + one;
    }
    
	//save
	cout << "Saving data..." << endl;
	int o = printLines("Files/Factorial/",data,1,data.size()-1);
	if(o==-3)
	{
		cout << "Big error!! You should reset all files to initial setup before continuing." << endl;
		return -5;
	}
	else if(o!=0)
	{
		cout << "Error! Calculated data might not have been saved." << endl;
		return -3;
	}

	cout << "Factorial process was productive. I found the factorials of " << (data.size()-1) << " numbers("
		<< (x+1) << "-" << (x+data.size()-1) << ")." << endl;
	stop.clear();
	return 0;
}

int getPowersOf2()
{
	unsigned int n;
	try
	{
		cin >> n;
	}catch(exception e){cout << "Invalid number" << endl;return -3;}
	if(n<0)
	{
		cout << "Integer too small" << endl;
		return 3;
	}
	if(getCount("Files/PowersOf2/")<n)
	{
		cout << "Integer too big" << endl;
		return 1;
	}
    string s = getLine("Files/PowersOf2/",n);
	if(s=="")
	{
		cout << "Error occured. Could not retrieve number." << endl;
		return -1;
	}
	cout << "2 raised to " << n << " is: " << endl << s << endl;
	return 0;
}

int calcPowersOf2()
{
	//load
	cout << "Getting data..." << endl;
	deque<string> data;
    unsigned long long x = getCount("Files/PowersOf2/");
	string s = getLine("Files/PowersOf2/",x-1);
	if(s=="")
	{
		cout << "Error! Calculation was not executed." << endl;
		return -2;
	}
	data.push_back(s);

	//calculate
	cout << "Calculating..." << endl;
	bool rerun = false;
	Integer a(s);
	unsigned long count = 0;
    while(stop.test_and_set(memory_order_acquire))
    {
        a = a+a;
		string a2 = a.value();
        data.push_back(a2);
		count++;
		if(count>=MAXSIZE)
		{
			rerun = true;
			break;
		}
    }
    
	//save
	cout << "Saving data..." << endl;
	int o = printLines("Files/PowersOf2/",data,1,data.size()-1);
	if(o==-3)
	{
		cout << "Big error!! You should reset all files to initial setup before continuing." << endl;
		return -5;
	}
	else if(o!=0)
	{
		cout << "Error! Calculated data might not have been saved." << endl;
		return -3;
	}
	if(rerun)
	{
		return calcPowersOf2();
	}

	cout << "Powers of 2 process was productive. I found " << (data.size()-1) << " powers of 2("
		<< (x+1) << "-" << (x+data.size()-1) << ")." << endl;
	stop.clear();
	return 0;
}

int empty()
{
	return 0;
}



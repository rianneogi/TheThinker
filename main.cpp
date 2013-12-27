///TODO LIST
// Check if calculated fibonacci numbers are correct
// Find a way to add efficient Prime generation
///TODO LIST

///STATUS
// Currently working to update the existing algorithms(Fibonacci, Factorial etc.) to the new base-flexible format
// I want to add some prime generation algorithm
///STATUS

///HISTORY
// 16-04-2013 : const-corrected a bunch of Integer class functions
// 15-04-2013 : Made Integer::half() to be able to operate on Integers is bases other than 10
// 07-04-2013 : Added ConvertBase() and Integer::changeBase() functions
// 04-04-2013 : Basic arithmethic functions can now do operations on numbers in bases other than 10 
// 04-04-2013 : Added bitshifting and incrementing to class Integer
// 04-04-2013 : Added isProbablePrime to class Integer
// 04-04-2013 : Added GCD and modexp to class Interger
// 04-04-2013 : Added division and modulus to class Integer
// 02-12-2012 : Added Powers Of 2
// 02-12-2012 : Improved file system
// 01-12-2012 : Added Factorial
// 01-12-2012 : Added multiplication to class Integer
// 01-12-2012 : Added file system
// 01-12-2012 : Added Fibonacci
// 01-12-2012 : Added class Integer which can do addition and comparision checking of big ints
// 01-12-2012 : Added async system
// 01-12-2012 : TheThinker was first born
///HISTORY

///BUGS
// Improper base 2^62 to decimal conversion
// FIXED - Something wrong with either createFromText or high-base addition
// FIXED - Improved file system bugging
// FIXED - Factorial is not working properly
///BUGS

#include <iostream>
#include "Thoughts.h"
#include <conio.h>
#include "stdlib.h"

using namespace std;

void inputLoop()
{
	srand(time(0));
    std::future<int> the_answer = std::async(empty);
	string s;
	cout << "Hello." << endl;
	while(true)
	{
	    cin >> s;
		//THINK
		if(s=="think" || s=="Think" || s=="THINK")
		{
			string s2 = "";
			cin >> s2;
			if(s2=="fib" || s2=="fibonacci")
			{
				bool b = stop.test_and_set(memory_order_acquire);
			    stop.clear();
			    if(b)
			    {
			        int n = the_answer.get();
					if(n!=0)
						cout << "An error occured. Calculated data might not have been saved." << endl;
			    }
				stop.test_and_set(memory_order_acquire);
				the_answer = std::async(calcFibonacci);
			}
			else if(s2=="fib2" || s2=="fibonacci2")
			{
				bool b = stop.test_and_set(memory_order_acquire);
			    stop.clear();
			    if(b)
			    {
			        int n = the_answer.get();
					if(n!=0)
						cout << "An error occured. Calculated data might not have been saved." << endl;
			    }
				stop.test_and_set(memory_order_acquire);
				the_answer = std::async(calcFibonacci2);
			}
			else if(s2=="fact" || s2=="factorial" || s2=="factorials")
			{
				bool b = stop.test_and_set(memory_order_acquire);
				stop.clear();
				if(b)
				{
					int n = the_answer.get();
					if(n!=0)
					{
						//cout << "An error occured. Calculated data might not have been saved." << endl;
					}
				}
				stop.test_and_set(memory_order_acquire);
				the_answer = std::async(calcFactorial);
			}
			else if(s2=="powersof2" || s2=="PowersOf2" || s2=="powers of 2" || s2=="Powers Of 2")
			{
				bool b = stop.test_and_set(memory_order_acquire);
				stop.clear();
				if(b)
				{
					int n = the_answer.get();
					if(n!=0)
					{
						//cout << "An error occured. Calculated data might not have been saved." << endl;
					}
				}
				stop.test_and_set(memory_order_acquire);
				the_answer = std::async(calcPowersOf2);
			}
			else
			{
			    cout << "Invalid command. Type 'help think' for a list of commands" << endl;
			}
		}
		//END THINK

		//GET
		else if(s=="get" || s=="Get" || s=="GET")
		{
			string s2 = "";
			cin >> s2;
			if(s2=="Count" || s2=="count")
			{
				string s3 = "";
				cin >> s3;
				if(s3=="fib" || s3=="fibonacci")
				{
					cout << getCount("Files/Fibonacci/") << endl;
				}
				else if(s3=="fact" || s3=="factorial" || s3=="factorials")
				{
					cout << getCount("Files/Factorial/") << endl;
				}
				else if(s3=="powersof2" || s3=="PowersOf2" || s3=="powers of 2" || s3=="Powers Of 2")
				{
					cout << getCount("Files/PowersOf2/") << endl;
				}
			}
			else if(s2=="fib" || s2=="fibonacci")
			{
				getFibonacci();
			}
			else if(s2=="fib2" || s2=="fibonacci2")
			{
				getFibonacci2();
			}
			else if(s2=="fact" || s2=="factorial" || s2=="factorials")
			{
				getFactorial();
			}
			else if(s2=="powersof2" || s2=="PowersOf2" || s2=="powers of 2" || s2=="Powers Of 2")
			{
				getPowersOf2();
			}
			else
			{
				cout << "Invalid command. Type 'help get' for a list of commands" << endl;
			}
		}
		//END GET

		//CALC
		else if(s=="calc" || s=="Calc" || s=="CALC" || s=="calculate" || s=="Calculate" || s=="CALCULATE")
		{
			string s2 = "";
			cin >> s2;
			if(s2=="GCD" || s2=="gcd")
			{
				string s3 = "";
				string s4 = "";
				cin >> s3;
				cin >> s4;
				Integer a(s3,10);
				Integer b(s4,10);
				cout << GCD(a,b).value() << endl;
			}
			else if(s2=="isprobableprime" || s2=="ISPROBABLEPRIME" || s2=="isProbablePrime" || s2=="IsProbablePrime")
			{
				string s3 = "";
				string s4 = "";
				cin >> s3;
				cin >> s4;
				Integer a(s3,10);
				cout << a.isProbablePrime(Str2Int(s4)) << endl;
			}
			else if(s2=="convertbase" || s2=="ConvertBase" || s2=="CONVERTBASE" || s2=="convertBase")
			{
				string s3 = "";
				string s4 = "";
				string s5 = "";
				cin >> s3;
				cin >> s4;
				cin >> s5;
				Integer a(s3,Str2Long(s4));
				cout << ConvertBase(a,Str2Int(s5)).value() << endl;
			}
		}
		//END CALC

	    else if(s=="stop" || s=="Stop" || s=="STOP")
	    {
			bool b = stop.test_and_set(memory_order_acquire);
			stop.clear();
			if(b)
			{
				int n = the_answer.get();
				if(n!=0)
				{
					//cout << "An error occured. Calculated data might not have been saved." << endl;
				}
			}			
	    }
		else if(s=="exit" || s=="quit")
		{
			cout << "Bye." << endl;
			bool b = stop.test_and_set(memory_order_acquire);
			stop.clear();
			if(b)
			{
			    int n = the_answer.get();
			}
			break;
		}
		else if(s=="help")
		{
			cout << "List of commands:" << endl;
			cout << "think : Tells the Thinker to think." << endl;
			cout << "get : Asks the Thinker to get a certain value from the files." << endl;
			cout << "stop : Tell the Thinker to stop thinking." << endl;
			cout << "help : Displays a list of commands." << endl;
			cout << "help think : Displays a list of thinking commands." << endl;
			cout << "help get : Displays a list of getting commands." << endl;
		}
		else if(s=="help think")
		{
			cout << "List of thinking commands:" << endl;
			cout << "fact : Thinks about Factorials" << endl;
			cout << "fib : Thinks about Fibonacci Integers" << endl;
		}
		else if(s=="help get")
		{
			cout << "List of thinking commands:" << endl;
			cout << "fact : Gets a Factorial" << endl;
			cout << "fib : Gets a Fibonacci Integer" << endl;
		}
		else
		{
			cout << "Invalid command. Type 'help' for a list of commands" << endl;
		}
	}
}

int main()
{
	//ProjectEuler();
	cout << "start" << endl;
	getch();
	unsigned long long c = 0;
	std::vector<bool> v = generatePrimeSieve(7072);
	std::vector<unsigned long long> v2;
	std::vector<bool> b(50000000,false);
	for(int i = 0;i<7072;i++)
	{
		if(v.at(i)==true)
		{
			v2.push_back(i+1);
		}
	}
	for(int i = 0;i<v2.size();i++)
	{
		if(i%100==0)
			cout << i << endl;
		for(int j = 0;j<v2.size();j++)
		{
			unsigned long long jp = v2.at(j);
			if(jp > 368)
			{
				break;
			}
			for(int k = 0;k<v2.size();k++)
			{
				unsigned long long kp = v2.at(k);
				if(kp > 84)
				{
					break;
				}
				unsigned long long ip = v2.at(i);
				unsigned long long x = kp*kp*kp*kp + jp*jp*jp + ip*ip;
				if(x < 50000000)
				{
					if(b.at(x-1)==false)
					{
						b.at(x-1)=true;
						c++;
					}
				}
			}
		}
	}
	cout << c << endl;
	try
	{
        inputLoop();
	}
	catch(exception e)
	{
		cout << "Exception occured: " << e.what() << endl;
	}
	cout << "Press any key to continue..." << endl;
	getch();
    return 0;
}
// ConsoleApplication10.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include<sstream>
#include<iostream>
#include "string"

using namespace std;

static int k =0 , j=0;
static bool fail=false;
static float sum, n, a1, a2;
int main()
{
	string str;
	char op;
	getline(cin, str);		
	istringstream stream(str);
	stream >> sum;
	while (stream >> op)
	{
		stream >> n;
		if (op == '+' || op == '-')
		{
			if (k > 0 )
			{
				sum += 1.*a1;
				j++;
			}
			if (op == '+')
			{
				a1 = n;
				k++;
			}
			if (op == '-')
			{
				a1 = -1 * n;
				k++;
			}
		}
		if (op == '*' || op == '/')
		{
			if (k == 0 )
			{
				if(op=='*') sum *=1.* n;
				if (op == '/')
				{
					if(n!=0) sum /= 1.*n;
					else
					{
						cout << "fail" << endl;
						fail = true;
					}
				}
			a2 = sum;
			}
			else
			{
				if (op == '*')
				{
					a2 += 1.* a1*n;
				}
				if (op == '/')
				{
					if (n == 0)
					{
						cout << "fail";
						fail = true;
					}		
					else
					{
						a2 += 1.*a1 / n;
					}
				}
			}
			a1 = a2;
			a2 = 0;
		}
		if (op != '+' && op != '-' && op != '*' && op != '/')
		{
			fail = true;
			cout << "fail" << endl;
		}
	}
	if (k > j) sum += a1;
	if(!fail) cout << sum << endl;
	system("pause");
	return 0;
}

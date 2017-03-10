#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

// 
int process(string operation, vector<long> &stack)
{
	bool flag = true;
	if (operation == "DUP")
	{
		flag = false;
		if (stack.size() < 1)
			return -1;

		long a = stack.back();
		stack.push_back(a);
	}
	if (operation == "POP")
	{
		flag = false;
		if (stack.size() < 1)
			return -1;

		stack.pop_back();
	}
	if (operation == "+")
	{
		flag = false;
		if (stack.size() < 2)
			return -1;

		long a, b;
		a = stack.back();
		stack.pop_back();
		b = stack.back();
		stack.pop_back();

		long c = a + b;

		if (c < 0)
			return -1;

		stack.push_back(c);
	}
	if (operation == "-")
	{
		flag = false;
		if (stack.size() < 2)
			return -1;

		long a, b;
		a = stack.back();
		stack.pop_back();
		b = stack.back();
		stack.pop_back();

		long c = a - b;

		if (c > pow(2, 20) - 1)
			return -1;

		stack.push_back(c);
	}
	if (flag)
	{
		long x = stol(operation);
		if (x < 0 or x > pow(2, 20) - 1)
			return -1;
		stack.push_back(x);
	}

   return 1;
}


int solution(string &S)
{
	// write your code in C++14 (g++ 6.2.0)
    if (S.size() == 0)
    {
        cout << "" << endl;
		return -1;
    }
        
	vector<long> stack;
	string operation
	{ };

	for (auto &c : S)
	{
		if (c != ' ')
			operation += c;
		else
		{
			cout << operation << " ";
            process(operation, stack);
			operation = "";
		}
	}

	cout << operation << endl;
    process(operation, stack);

	if (stack.size() == 0)
		return -1;
	return stack.back();
}

int main()
{
	string input{"13 DUP 4 POP 5 DUP + DUP + -"};
	cout << solution(input) << endl;
    return 0;
}

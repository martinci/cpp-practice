#include <vector>
#include <iostream>
#include <string>
using namespace std;

int solution(int A, int B)
{
	string str_A
	{ to_string(A) }, str_B
	{ to_string(B) };
	int len_A = str_A.size(), len_B = str_B.size();

	if (len_A + len_B > 9)
		return -1;

	int idx_A = 0, idx_B = 0;
	string C;

	while (idx_A < len_A and idx_B < len_B)
	{
		C += str_A[idx_A];
		C += str_B[idx_B];
		idx_A++;
		idx_B++;
	}

	if (idx_A == len_A)
	{
		while (idx_B < len_B)
		{
			C += str_B[idx_B];
			idx_B++;
		}
	}
	else
	{
		while (idx_A < len_A)
		{
			C += str_A[idx_A];
			idx_A++;
		}
	}
	int temp
	{ stoi(C) };
	if (temp > 1e8)
		return -1;
	else
		return temp;
}

int main()
{
	cout << "Merge two integers: ";
    int a, b;
    cin >> a >> b;
    int temp = solution(a,b);
    if (temp == -1){
        cout << "Numbers are too big! Make sure that they merge to something < 1e8";
    }else{
        cout << temp << endl;
    }
	return 0;
}

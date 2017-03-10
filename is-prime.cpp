#include <iostream>
using namespace std;

bool is_prime(int n)
{
    if (n == 1)
        return false;
    if (n == 2)
        return true;
    if (n%2 == 0)
        return false;
    if (n < 9)
        return true;
    for (int i=3; i*i<=n;)
    {
        if (n%i == 0)
            return false;
        i += 2;
    }
    return true;
}

int main()
{
    cout << "Admire the primes less than 100!!" << endl;
    for (int i=0; i < 100; i++)
    {
        if (is_prime(i))
            cout << i << " ";
    }
        
}

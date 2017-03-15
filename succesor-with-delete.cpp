/* SUCCESSOR WITH DELETE (IN PROGRESS)
 * 
 * INPUT:
 *    - Set of N integers S = {0, 1, ..., N-1}.
 *    - A sequence of requests of the form:
 *        a) remove x from S
 *        b) find the succesor of x: the smallest y in S so that y >= x
 *
 * TO DO:
 *     - Design a data type so that all operations (except construction)
 *       take logarithmic time or better in the worst case.
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class MySet
{
public:
    int size;
    vector<int> set;
    MySet(int N)
    : size(N)
    {
        set.resize(N);
        for (int i=0; i <N; i++){
            set[i] = i;
        }
    }
    ~MySet(){}

    void MySet::remove()
    {
        return;
    }

    int MySet::succesor(int x)
    {
        int y=0;
        return y;
    }
};

ostream operator<< (ostream &os, MySet &S)
{
    for (int i=0; i < S.size; i++){
            os << S.set[i] << " ";
    }
    return os;
}

int main()
{
    int N=0;
    cin >> N;
    MySet S = MySet(N);
    string operation;
    int x=0;
    cin >> string >> x;

    switch(string){
        case "rm":
            S.remove(x);
            cout << "The set is now " << S << endl;
            break;
        case "sc":
            int y = S.succesor(x);
            cout << "The succesor of " << x << " is " << y << endl;
            break;
            
    }
    return 0;
}

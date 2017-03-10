#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, q;
    cin >> n >> q;

    vector<string> hrml_code(n);
    for(int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        hrml_code.push_back(s);
    }
    for(int i = 0; i < q; i++) {
        string query;
        getline(cin, query);
        // Process query
        string tag;
        int idx_start = 0, idx_end;
        int counter = 0;
        for(auto& c : query) {
            if(c == '~') {
                idx_end = counter;
                break;
            } else {
                if(c == '.') {
                    counter++;
                    idx_start = counter;
                }
            }
        }
        tag = query.substr(idx_start, idx_end - idx_start);
        cout << tag;
    }

    return 0;
}

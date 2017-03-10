/*
 * SOCIAL NETWORK CONNECTIVITY
 * 
 * INPUT:
 * - Social network containing n members. (n >=1)
 * - A log file containing m timestamps of members forming friendships. (m>=0)
 *
 * TO DO:
 * Design an algorithm to determine the earliest time at which all members are connected.
 * Assume that the log file is sorted by timestamp and that friendship is an equivalence relation.
 * The running time of your algorithm should be mlog⁡n or better and use extra space proportional to n.
 */
 
#include <iostream>
using namespace std;

class SocialNetwork
{
private:
    int n;
    
    int* id = new int[n];
    int* size = new int[n];

    int getRoot(int idx)
    {
        while(idx != id[idx]) {
            id[idx] = id[id[idx]];
            idx = id[idx];
        }
        return idx;
    }

    bool is_connected()
    {
        return size[getRoot(0)] == n;
    }

public:
    bool totally_connected;
    
    SocialNetwork(int n)
    {
        this->n = n;
        for(int i = 0; i < n; i++) {
            id[i] = i;
            size[i] = 1;
        }
        if(n == 1) {
            totally_connected = true;
        }else{
            totally_connected = false;
        }
    }
    

    void connect(int i, int j)
    {
        if(i == j)
            return;
        // We make sure the smallest tree gets linked to the larger one
        int root_i = getRoot(i);
        int root_j = getRoot(j);
        if(size[i] > size[j]) {
            id[j] = root_i;
            size[root_i] += size[root_j];
        } else {
            id[i] = root_j;
            size[root_j] += size[root_i];
        }
        totally_connected = is_connected();
    }
};

int main()
{
    int n, m;
    cin >> n >> m;

    SocialNetwork myNetwork(n);

    for(int i = 0; i < m; i++) {
        int time, a, b;
        cin >> time >> a >> b;
        
        myNetwork.connect(a, b);
        
        if(myNetwork.totally_connected) {
            cout << "The social network is connected! The time is " << time << "." << endl;
            return 0;
        }
    }
    
    if (n==1){
        cout << "The social network is a single member. It is connected!" << endl;
    }else{
        cout << "The social network is not connected!" << endl;
    }
    
    return 0;
}

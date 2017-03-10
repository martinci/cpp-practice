#include <iostream>
#include <map>

int fibon(int n, std::map<int, int> &memory)
{
    if (!memory.count(n)){
        // we haven't computed the n-th term
        if(n < 0){
            return -1;
        }
        if (n==0 or n==1){
            memory[n] = 1;
        }else{
            memory[n] = fibon(n-1, memory) + fibon(n-2, memory);
        }
    }
    return memory[n];
}

int main(){    
    std::cout << "How many terms of the Fibonacci sequence do you wish to see: ";
    int n;
    std:: cin >> n;

    std::map<int, int> memory;
  
    
    if (n < 0){
        std::cout << "That's not a valid number!!" << std::endl;
    }else{
        for (int i=0; i<n; i++){
            std::cout << fibon(i, memory) << " ";
        }
    }
    return 0;
}

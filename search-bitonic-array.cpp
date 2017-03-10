/* SEARCH BITONIC ARRAY
 *
 * Input:
 *    - A bitonic array, that is increasing seq. of integers followed by a decreasing sequence of integers.
 *      Eg. [1, 2, 3, 4, 7, 6, 5]. We can assume that all integers are distinct.
 *
 * TO DO:
 *    - Write a program that, given a bitonic array of n distinct integer values,
 *      determines whether a given integer is in the array.
 *    - (Standard version) Use 3log(n) compares at worst. CHECK!
 *    - (Advanced version) Use 2log(n) compares at worst. Show that no algorithm can guarantee fewer. IN PROGRESS...
 */

#include <iostream>
#include <vector>
#include <random>
#include <ctime>

bool bitonicSearch(std::vector<int>& arr, int lo, int hi, int x);

int main(int argc, char** argv)
{
    std::vector<int> arr{1, 2, 5, 6, 7, 3};
    std::cout << "Array = " ;
    for (auto &a: arr){
        std::cout << a << " ";
    }   

    int x{20};
    std::cout << std::endl << "x = " << x << std::endl;
    bool is_there{bitonicSearch(arr, 0, arr.size() - 1, x)};
    
    std::string s{is_there ? "contains ": "doesn't contain "};
    std::cout << "The array " << s << x << "." << std::endl;

    return 0;
}

bool bitonicSearch(std::vector<int>& arr, int lo, int hi, int x)
{
    // Trivial cases
    if (arr.size() == 1) {return x == arr[0];}
    if (arr.size() == 2) {return x == arr[0] or x == arr[1];}
    // We rely heavilly on the definition of bitonic.
    // Search for the max element, the transition between the inc./dec. arrays.
    int i{lo}, j{hi};
    int mid{(lo + hi) / 2};
    
    while (arr[mid] != x and i != mid){
        if (arr[mid] < arr[mid + 1]){
            // The max element is on the right of mid.
            i = mid;
        } else {
            // The max must be on the left of mid.
            j = mid;
        }
        mid = (i + j) / 2 ;
    }
    
    if (arr[mid] == x){
        return true;
    } else {
        // arr[mid+1] is the max of the array.
        mid++;
        // Now we only need to look for x on both parts of the array. Use binary search.
        int hi_left{mid}, lo_right{mid};
        int mid_left{(lo + mid) / 2}, mid_right{(hi + mid) / 2};

        while (lo <= hi_left){
            // Search on left (increasing) array
            if (arr[mid_left] == x){
                return true;
            }
            if (arr[mid_left] > x){
                hi_left = mid_left - 1;
            } else {
                lo = mid_left + 1;
            }
            mid_left = (lo + hi_left) / 2;
        }

        while ( lo_right <= hi){
            // Search on right (decreasing) array
            if (arr[mid_right] == x){
                return true;
            }
            if (arr[mid_right] < x){
                hi = mid_right - 1;
            } else {
                lo_right = mid_right + 1;
            }
            mid_right = (lo_right + hi) / 2;
        }
    }
    
    return false;
}

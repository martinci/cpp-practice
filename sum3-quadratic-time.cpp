/*3-SUM IN QUADRATIC TIME
 *
 * Input:
 *    - Array of integers.
 *
 * TO DO:
 *    - Design an algorithm that returns the number of triples that sum to zero.
 *    - Make sure it runs in O(n^2).
*/
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

int threeSum (std::vector<int>&);
int twoSum (std::vector<int>&, int, int);


int main(int argc, char** argv)
{
    std::vector<int> arr;
    if (argc == 1){
        // Generate random array
        std::random_device rd;
        std::default_random_engine e(rd());
        std::uniform_int_distribution<int> size(10, 10);
        std::uniform_int_distribution<int> value(-10, 10);
        int n = size(e);
        arr.reserve(n);
        std::cout << "The size of the array is " << n << std::endl;
        for (int i = 0; i < n; i++){
            arr.push_back(value(e));
        }
    } else {
        arr.reserve(argc);
        for (int i = 1; i < argc; i++){
            arr.push_back(std::stoi(argv[i]));
        }
    }
    std::sort(arr.begin(), arr.end());
    for (auto &value: arr){
        std::cout << value << " ";
    }
    std::cout << std::endl;
    std::cout << "There are " << threeSum(arr) << " triples that sum to 0.";
    return 0;
}


int threeSum(std::vector<int> &arr)
{
    // We assume that the array is sorted!
    // The algorithm is to loop through the elements and find pairs that sum to the complements of the elements.
    // The complexity will be n (loop) * n (twoSum) ~ n^2
    int count(0);
    int n(arr.size());
    for (int i = 0; i< n; ++i){
        int neg_a(-arr[i]);
        count += twoSum(arr, neg_a, i);
    }
    return count;
}

int twoSum(std::vector<int> &arr, int sum, int idx)
{
    // Returns number of pairs summing up to sum that don't include the element at index idx and start after it (avoid overcounting).
    int count(0);
    int n(arr.size());

    int lo(idx+1), hi(n-1);
    while (lo < hi){
        if (arr[lo] + arr[hi] > sum){
            hi--;
        } else if (arr[lo] + arr[hi] < sum){
            lo++;
        } else {
            count++;
            // account for repetitions of number
            if (arr[lo] == arr [lo + 1]) {
                lo++;
            } else {
                hi--;
            }
        }
    }
    return count;
}

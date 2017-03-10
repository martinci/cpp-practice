/* MERGE SORT
 *
 * Input:
 *     - An array of integers.
 *
 * TO DO:
 *    - Sort the array in ascending order using the merge sort algorithm. *
 */

#include <iostream>
#include <vector>
#include <random>

std::vector<int> mergeSort(std::vector<int>& arr, int lo, int hi);

int main()
{
    std::vector<int> arr;
    // Generate random array
    std::random_device rd;
    std::default_random_engine e(rd());
    // std::uniform_int_distribution<int> size(10, 10);
    std::uniform_int_distribution<int> value(-10, 10);
    int n = 10;
    // int n = size(e);
    arr.reserve(n);
    std::cout << "The size of the array is " << n << std::endl;
    for(int i = 0; i < n; i++) {
        int temp = value(e);
        arr.push_back(temp);
        std::cout << temp << " ";
    }
    std::cout << std::endl;

    std::vector<int> sorted{ mergeSort(arr, 0, n) };

    for(auto& a : sorted) {
        std::cout << a << " ";
    }

    return 0;
}

std::vector<int> merge(std::vector<int>& left, std::vector<int>& right)
{
    std::vector<int> sorted;
    int i(0), j(0);
    int n(left.size()), m(right.size());
    sorted.reserve(n + m);

    while(i < n and j < m) {
        if(left[i] > right[j]) {
            sorted.push_back(right[j]);
            j++;
        } else {
            sorted.push_back(left[i]);
            i++;
        }
    }

    if(i == n) {
        for(; j < m; j++) {
            sorted.push_back(right[j]);
        }
    } else {
        for(; i < n; i++) {
            sorted.push_back(left[i]);
        }
    }

    return sorted;
}

std::vector<int> mergeSort(std::vector<int>& arr, int lo, int hi)
{
    if(hi - lo == 1) {
        std::vector<int> sorted{ arr[lo] };
        return sorted;
    }

    int mid((lo + hi) / 2);

    std::vector<int> left, right;
    left.reserve((hi - lo) / 2 + 1);
    right.reserve((hi - lo) / 2 + 1);

    left = mergeSort(arr, lo, mid);
    right = mergeSort(arr, mid, hi);

    return merge(left, right);
}

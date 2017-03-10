/* BINARY SEARCH ALGORITHM
 *
 * Given a sorted array, find a given element or conclude it is not there.
 *
 */
#include <iostream>
#include <vector>

int binarySearch(std::vector<int> arr, int x)
{
    int lo(0), hi(arr.size() - 1);
    int mid = (lo + hi) / 2;

    while(lo <= hi) {
        if(arr[mid] == x) {
            return mid;
        } else {
            if(x > arr[mid]) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        mid = (lo + hi) / 2;
    }

    return -1;
}

int main()
{
    std::vector<int> arr{ 2, 8, 12, 25 };

    std::cout << binarySearch(arr, 2) << std::endl;
    std::cout << binarySearch(arr, 58) << std::endl;
}

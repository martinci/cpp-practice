/* DUTCH NATIONAL FLAG
 *
 * INPUT:
 *    - An array of n buckets, each containing a red, white, or blue pebble.
 *
 * TO DO:
 *    - Sort them by the color of the Dutch flag (red-white-blue) using the operations:
 *          I) swap(i,j): swap the pebble in bucket i with the pebble in bucket j.
 *          II) color(i): color of pebble in bucket i.
 *
 *    - The performance requirements are as follows:
 *          I) At most n calls to color().
 *          II) At most n calls to swap().
 *          III) Constant extra space.
 */
#include <iostream>
#include <random>
#include <vector>
#include <map>

class BucketArray
{
private:
    int _size;
    // We encode colors as follows: R=0, W=1, U=2
    std::vector<int> arr;
    int _color_calls{ 0 }, _swap_calls{ 0 };

public:
    BucketArray(int n)
        : _size(n)
    {
        arr.reserve(n);
    }

    void swap(const int i, const int j)
    {
        if(i < 0 or i >= _size or j < 0 or j >= _size) {
            std::cerr << "Index out of bounbds!" << std::endl;
            throw;
        }
        int temp{ arr[i] };
        arr[i] = arr[j];
        arr[j] = temp;
        _swap_calls++;
    }

    int color(const int i)
    {
        _color_calls++;
        return arr[i];
    }

    void addBucket(int c)
    {
        arr.push_back(c);
    }

    void showBuckets() const
    {
        // R=0, W=1, U=2
        for(auto& a : arr) {
            switch(a) {
            case 0:
                std::cout << "\033[1;31mR\033[0m";
                break;
            case 1:
                std::cout << "\033[1;37mW\033[0m";
                break;
            case 2:
                std::cout << "\033[1;34mU\033[0m";
                break;
            }
        }
        std::cout << std::endl;
    }

    void printCalls() const
    {
        std::cout << "We used " << _color_calls << " calls to color and " << _swap_calls << " calls to swap."
                  << std::endl;
    }

    int size() const
    {
        return _size;
    }
};

int main(int argc, char** argv)
{
    int n;
    std::random_device rd;
    std::default_random_engine e(rd());

    if(argc == 1) {
        // create random size array with random colors
        std::uniform_int_distribution<int> size(0, 30);
        n = size(e);
    } else {
        // the first argument is the size. Could add feature to read array from cin.
        n = std::stoi(argv[1]);
    }

    // Example of ~2n call to swap. Can be fixed if we don't care about color order.
    //std::array<int, 11> test {2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    //n = 11;

    BucketArray arr = BucketArray(n);
    std::uniform_int_distribution<int> color(0, 2);


    for(int i = 0; i < n; i++) {
        arr.addBucket(color(e));
        //arr.addBucket(test[i]);
    }

    std::cout << "Initial " << n << "-array = ";
    arr.showBuckets();

    // Sort the array by color. Recall that  R=0, W=1, U=2
    // We keep track of the [lo, hi] indices for each color.
    // E.g. red = [lo, hi]
    std::array<int, 2> red, white, blue;
    bool red_seen{ false }, white_seen{ false }, blue_seen{ false };

    for(int i = 0; i < n; i++) {
        int current_color{ arr.color(i) };
        switch(current_color) {
        case 0:
            // Red case, we need to bring it to the beginning, R W U.
            if(!blue_seen) {
                if(white_seen) {
                    arr.swap(i, white[0]);
                    // Update indices
                    if(!red_seen) {
                        red[0] = white[0];
                        red[1] = white[0];
                    } else {
                        red[1] = white[0];
                    }
                    white[0]++;
                    white[1]++;
                } else {
                    // If there is no blue nor white, we are in the right spot.
                    if(!red_seen) {
                        red[0] = i;
                        red[1] = i;
                    } else {
                        red[1] = i;
                    }
                }
            } else {
                // There is blue
                arr.swap(i, blue[0]);
                // Update indices
                if(!red_seen) {
                    red[0] = blue[0];
                    red[1] = blue[0];
                } else {
                    red[1] = blue[0];
                }
                blue[0]++;
                blue[1]++;

                if(white_seen) {
                    arr.swap(red[1], white[0]);
                    // Update indices
                    if(!red_seen) {
                        red[0] = white[0];
                        red[1] = white[0];
                    } else {
                        red[1] = white[0];
                    }
                    white[0]++;
                    white[1]++;
                }
                // No white. We are in the correct spot & index. Do nothing.
            }
            red_seen = true;
            break;

        case 1:
            // White case, we need to bring it into the middle, R W U.
            if(!blue_seen) {
                // No blue means we are in correct spot & index.
                if(!white_seen) {
                    white[0] = i;
                    white[1] = i;
                } else {
                    white[1] = i;
                }
            } else {
                arr.swap(i, blue[0]);
                // Update indices
                if(!white_seen) {
                    white[0] = blue[0];
                    white[1] = blue[0];
                } else {
                    white[1] = blue[0];
                }
                blue[0]++;
                blue[1]++;
            }
            white_seen = true;
            break;

        case 2:
            // Blue case, we are in the correct place, R W U.
            if(!blue_seen) {
                blue[0] = i;
                blue[1] = i;
            } else {
                blue[1] = i;
            }
            blue_seen = true;
            break;
        }
    }

    std::cout << "Sorted " << n << "-array = ";
    arr.showBuckets();
    arr.printCalls();
    return 0;
}

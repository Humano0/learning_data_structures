#include <iostream>
#include <vector>

using namespace std;

class BinarySearch
{
public:
    int binary_search(vector<int> arr, int item)
    {
        int low = 0, high = arr.size() - 1;
        while (low < high)
        {
            int mid = (low + high) / 2;
            if (arr[mid] == item){
                return mid;
            }
            else if (item > arr[mid]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return -1;
    }
    int binary_search_recursive(vector<int> arr, int low, int high, int item)
    {
        if (high >= low)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid] == item){
                return mid;
            }
            else if (arr[mid] > item){
                return binary_search_recursive(arr, low, mid - 1, item);
            }
            else{
                return binary_search_recursive(arr, mid + 1, high, item);
            }
        }
        return -1;
    }
};

int main()
{
    vector<int> test = {1, 3, 4, 6, 7, 12, 23, 51};
    BinarySearch *sol = new BinarySearch();
    cout << sol->binary_search_recursive(test, 0, test.size() - 1, 12);
}
#include <iostream>
#include <vector>

using namespace std;

class BinarySearch(){
    public:
        int binary_search(vector<int> arr, int item){
            int low = 0, high = arr.size() - 1;
            while(low < high){
                int mid = (low + high) / 2;
                if(arr[mid] == item){
                    return mid;
                }
                else if(item > arr[mid]){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
            return null;
        }
};

int main(){
    _VECTOR_<int> arr = {1, 3, 4, 6, 7, 12, 23, 51};
    class sol = BinarySearch();
    cout << sol.binary_search(arr, 12);
}
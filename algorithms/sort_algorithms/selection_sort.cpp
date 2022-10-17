#include <iostream>
#include <vector>

using namespace std;

class SelectionSort{
    public:
        void selection_sort(vector<int> arr){
            int arraySize = sizeof(arr) / sizeof(arr[0]);
            for(int i = 0; i < arraySize - 1; ++i){
                for(int j = i + 1; j < arraySize; ++j){
                    if(arr[j] < arr[i]){
                        swap(arr[j], arr[i]);
                    }
                }
            }
            for(int i = 0; i < arraySize; i++)
                cout << arr[i] << " ";
        }
};

int main()
{
    vector<int> test = {5, 12, 42, 31, 99, 12, 3, 21};
    SelectionSort *sol = new SelectionSort();
    sol->selection_sort(test);
}
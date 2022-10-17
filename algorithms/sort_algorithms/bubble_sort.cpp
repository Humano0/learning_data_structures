#include <iostream>
#include <vector>

using namespace std;

class BubbleSort{
    public:
        void swap(int arr[], int j) {
            int temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
        }
        void bubbleSort(int arr[], int arraySize){
            for (int i = 0; i < arraySize - 1; i++){
                for (int j = 0; j < arraySize - i - 1; j++){
                    if(arr[j] > arr[j + 1]){
                        swap(arr, j);
                    }
                }
            }
        }
        void printArr(int arr[], int arraySize){
            for (int i = 0; i < arraySize; i++){
                cout << arr[i] << " ";
            }
        }
        
};

int main(){
    int test[] = {3, 5, 1, 2, 6, 12, 8};
    int arraySize = sizeof(test) / sizeof(test[0]);

    BubbleSort *sol = new BubbleSort();
    sol->bubbleSort(test, arraySize);
    sol->printArr(test, arraySize);
}
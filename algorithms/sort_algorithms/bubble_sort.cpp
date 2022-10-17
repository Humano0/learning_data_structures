#include <iostream>
#include <vector>

using namespace std;

class BubbleSort{
    public:
        void swap(&n1, &n2) {
            int temp = *n1;
            *n1 = *n2;
            *n2 = temp;
        }
        void bubbleSort(int arr[], int arraySize){
            for (int i = 0; i < arraySize; i++){
                for (int j = 0; j < arraySize - i; j++){
                    if(arr[j] == arr[j + 1]){
                        swap(&arr[j], &arr[j + 1]);
                    }
                }
            }
        }
        void printArr(int arr[], int arraySize){
            for (int i = 0; i < arraySize; i++){
                cout << arr[i] << " ";
            }
        }
        
}

int main(){
    int test[] = {3, 5, 1, 2, 6, 12, 8};
    int arraySize = sizeof(test) / sizeof(test[0]);

    BubbleSort *sol = new BubbleSort();
    sol->bubbleSort(test, arraySize);
    sol->printArr(test, arraySize);
}
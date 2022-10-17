#include <iostream>
#include <vector>

using namespace std;

class InsertionSort{
    public:
        void insertionSort(int arr[], int arraySize)
        {
            for (int i = 0; i < arraySize; i++)
            {
                int key = arr[i];
                int j = i - 1;
                while (j >= 0 && arr[j] > key){
                    arr[j + 1] = arr[j];
                    j--;
                }
                arr[j + 1] = key;
            }
        }
        void printArr(int arr[], int arraySize)
        {
            for (int i = 0; i < arraySize; i++)
            {
                cout << arr[i] << " ";
            }
        }
};

int main()
{
    int test[] = {3, 5, 1, 2, 6, 12, 8};
    int arraySize = sizeof(test) / sizeof(test[0]);

    InsertionSort *sol = new InsertionSort();
    sol->insertionSort(test, arraySize);
    sol->printArr(test, arraySize);
}
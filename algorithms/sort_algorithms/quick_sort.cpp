#include <iostream>
#include <vector>

using namespace std;

class QuickSort{
    public:
        void swap(int arr[], int pos1, int pos2)
        {
            int temp;
            temp = arr[pos1];
            arr[pos1] = arr[pos2];
            arr[pos2] = temp;
        }

        int partition(int arr[], int low, int high)
        {
            int pivot = arr[high];
            int i = low - 1;
            for(int j = low; j <= high - 1; j++)
            {
                if (arr[j] < pivot){
                    i++;
                    swap(arr, i, j);
                }
            }
            swap(arr, i + 1, high);
            return i + 1;
        }

        void quickSort(int arr[], int low, int high)
        {
            if (low < high)
            {
                int pi = partition(arr, low, high);

                quickSort(arr, low, pi - 1);
                quickSort(arr, pi + 1, high);
            }
        }

        void printArr(int arr[], int arraySize){
            for (int i = 0; i < arraySize; i++){
                cout << arr[i] << " ";
            }
        }
};


int main()
{
    int test[] = {3,5,1,2,6,12,8};
    int arraySize = sizeof(test)/sizeof(test[0]);

    QuickSort *sol = new QuickSort();
    sol->quickSort(test, 0, arraySize - 1);
    sol->printArr(test, arraySize);
}
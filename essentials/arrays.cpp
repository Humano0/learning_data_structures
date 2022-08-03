//w1
#include <iostream>

using namespace std;

int main()
{
    int size;
    int arr[5] = {
        2,
        4,
    };
    for (int i = 0; i < sizeof(arr) / 4; ++i)
    {
        cout << arr[i] << endl;
    }
    cout << "--------------" << endl;

    for (int x : arr)
        cout << x << endl;

    cout << "--------------" << endl;

    cout << "Enter the size of the array: ";
    cin >> size;
    int arr1[size];
    for (int i = 0; i < size; ++i)
    {
        arr1[i] = i + 2;
    }
    for (int x : arr1)
        cout << x << endl;
}
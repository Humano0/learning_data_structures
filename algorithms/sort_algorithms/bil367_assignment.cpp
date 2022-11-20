#include <iostream>
#include <cstdlib>
#include <time.h>
#include <chrono>
#include <cmath>
#include <vector>

int test1[1000], test2[10000], test3[100000], test4[1000000];

using namespace std::chrono;

struct Node
{
    int value;
    struct Node *left, *right;
};
struct Node *newNode(int item)
{
    struct Node *temp = new Node;
    temp->value = item;
    temp->left = temp->right = NULL;
    return temp;
};

class HeapSort
{
public:
    void heapify(int arr[], int N, int i)
    {
        int largest = i;

        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < N && arr[l] > arr[largest])
            largest = l;

        if (r < N && arr[r] > arr[largest])
            largest = r;

        if (largest != i)
        {
            int temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;

            heapify(arr, N, largest);
        }
    }
    void heap_sort(int arr[], int n)
    {
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(arr, n, i);

        for (int i = n - 1; i > 0; i--)
        {
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;

            heapify(arr, i, 0);
        }
    }
};

class MergeSort
{
public:
    void merge(int arr[], int left, int mid, int right)
    {
        int subArrayOne = mid - left + 1;
        int subArrayTwo = right - mid;

        auto *leftArray = new int[subArrayOne], *rightArray = new int[subArrayTwo];

        for (auto i = 0; i < subArrayOne; i++)
            leftArray[i] = arr[left + i];
        for (auto j = 0; j < subArrayTwo; j++)
            rightArray[j] = arr[mid + 1 + j];

        auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
        int indexOfMergedArray = left;

        while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
        {
            if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo])
            {
                arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
                indexOfSubArrayOne++;
            }
            else
            {
                arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
                indexOfSubArrayTwo++;
            }
            indexOfMergedArray++;
        }
        while (indexOfSubArrayOne < subArrayOne)
        {
            arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
            indexOfMergedArray++;
        }
        while (indexOfSubArrayTwo < subArrayTwo)
        {
            arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
            indexOfMergedArray++;
        }
        delete[] leftArray;
        delete[] rightArray;
    }

    void merge_sort(int arr[], int begin, int end)
    {
        if (begin >= end)
            return;

        auto mid = begin + (end - begin) / 2;
        merge_sort(arr, begin, mid);
        merge_sort(arr, mid + 1, end);
        merge(arr, begin, mid, end);
    }
};

class TreeSort
{
public:
    /*
    Stores the sorted binary search tree
    In the given array(arr), i is the index holder
    */
    void storeSortedTree(Node *root, int arr[], int &i)
    {
        if (root != NULL)
        {
            storeSortedTree(root->left, arr, i);
            arr[i++] = root->value;
            storeSortedTree(root->right, arr, i);
        }
    }

    /*
    Inserts new node to the tree
    with given value
    */
    Node *insertNode(Node *node, int item)
    {
        if (node == NULL)
            return newNode(item);

        if (item < node->value)
            node->left = insertNode(node->left, item);
        else if (item > node->value)
            node->right = insertNode(node->right, item);

        return node;
    }

    // n = arr.size()
    void tree_sort(int arr[], int n)
    {
        struct Node *root = NULL;

        root = insertNode(root, arr[0]);
        for (int i = 1; i < n; i++)
            root = insertNode(root, arr[i]);

        int i = 0;
        storeSortedTree(root, arr, i);
    }
};

class QuickSort
{
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
        for (int j = low; j <= high - 1; j++)
        {
            if (arr[j] < pivot)
            {
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

    void printArr(int arr[], int arraySize)
    {
        for (int i = 0; i < arraySize; i++)
        {
            std::cout << arr[i] << " ";
        }
    }
};

class InsertionSort{
    public:
        void insertionSort(int arr[], int arraySize)
        {
            for (int i = 0; i < arraySize; i++)
            {
                int key = arr[i];
                int j = i - 1;
                while (j >= 0 && arr[j] > key)
                {
                    arr[j + 1] = arr[j];
                    j--;
                }
                arr[j + 1] = key;
            }
        }
};

class SelectionSort{
    public:
        void swap(int *xp, int *yp)
        {
            int temp = *xp;
            *xp = *yp;
            *yp = temp;
        }
        void selection_sort(int arr[], int n)
        {
            int i, j, min_idx;

            for (i = 0; i < n - 1; i++)
            {
                min_idx = i;
                for (j = i + 1; j < n; j++)
                    if (arr[j] < arr[min_idx])
                        min_idx = j;
                if (min_idx != i)
                    swap(&arr[min_idx], &arr[i]);
            }
        }
};

class Test: TreeSort, QuickSort, InsertionSort, SelectionSort, MergeSort, HeapSort{
    public:
        void initialize_array(){
            srand(time(0));
            for (int i = 0; i < 1000000; i++)
            {
                int random_num = rand();
                if (i < 1000)
                    test1[i] = test2[i] = test3[i] = test4[i] = random_num;
                else if (i < 10000)
                    test2[i] = test3[i] = test4[i] = random_num;
                else if (i < 100000)
                    test3[i] = test4[i] = random_num;
                else
                    test4[i] = random_num;
            }
        }

        void heap_sort_caller(){
            std::cout << "Heap Sort\t\t\t";

            auto time1 = high_resolution_clock::now();
            heap_sort(test1, 1000);
            auto time2 = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(time2 - time1);
            std::cout << duration.count() / pow(10, 6) << "\t ";

            heap_sort(test2, 10000);
            time1 = high_resolution_clock::now();
            duration = duration_cast<microseconds>(time1 - time2);
            std::cout << duration.count() / pow(10, 6) << "\t ";

            heap_sort(test3, 100000);
            time2 = high_resolution_clock::now();
            duration = duration_cast<microseconds>(time2 - time1);
            std::cout << duration.count() / pow(10, 6) << "\t ";

            heap_sort(test4, 1000000);
            time1 = high_resolution_clock::now();
            duration = duration_cast<microseconds>(time1 - time2);
            std::cout << duration.count() / pow(10, 6) << '\n';
        }
        void merge_sort_caller(){
            std::cout << "Merge Sort\t\t\t";

            auto time1 = high_resolution_clock::now();
            merge_sort(test1, 0, 1000);
            auto time2 = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(time2 - time1);
            std::cout << duration.count() / pow(10, 6) << "\t ";

            merge_sort(test2, 0, 10000);
            time1 = high_resolution_clock::now();
            duration = duration_cast<microseconds>(time1 - time2);
            std::cout << duration.count() / pow(10, 6) << "\t ";

            merge_sort(test3, 0, 100000);
            time2 = high_resolution_clock::now();
            duration = duration_cast<microseconds>(time2 - time1);
            std::cout << duration.count() / pow(10, 6) << "\t ";

            merge_sort(test4, 0, 1000000);
            time1 = high_resolution_clock::now();
            duration = duration_cast<microseconds>(time1 - time2);
            std::cout << duration.count() / pow(10, 6) << '\n';
        }
        void insertion_sort_caller(){
            std::cout << "Insertion Sort\t\t\t";

            auto time1 = high_resolution_clock::now();
            insertionSort(test1, 1000);
            auto time2 = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(time2 - time1);
            std::cout << duration.count() / pow(10, 6) << "\t ";
            
            insertionSort(test2, 10000);
            time1 = high_resolution_clock::now();
            duration = duration_cast<microseconds>(time1 - time2);
            std::cout << duration.count() / pow(10, 6) << "\t ";
            
            insertionSort(test3, 100000);
            time2 = high_resolution_clock::now();
            duration = duration_cast<microseconds>(time2 - time1);
            std::cout << duration.count() / pow(10, 6) << "\n";
            /*
            insertionSort(test4, 1000000);
            time1 = high_resolution_clock::now();
            duration = duration_cast<microseconds>(time1 - time2);
            std::cout << duration.count() / pow(10, 6) << '\n';
            */
        }
        void selection_sort_caller(){
            std::cout << "Selection Sort\t\t\t";

            auto time1 = high_resolution_clock::now();
            selection_sort(test1, 1000);
            auto time2 = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(time2 - time1);
            std::cout << duration.count() / pow(10, 6) << "\t ";

            selection_sort(test2, 10000);
            time1 = high_resolution_clock::now();
            duration = duration_cast<microseconds>(time1 - time2);
            std::cout << duration.count() / pow(10, 6) << "\t ";

            selection_sort(test3, 100000);
            time2 = high_resolution_clock::now();
            duration = duration_cast<microseconds>(time2 - time1);
            std::cout << duration.count() / pow(10, 6) << "\n";
            /*
            selection_sort(test4, 1000000);
            time1 = high_resolution_clock::now();
            duration = duration_cast<microseconds>(time1 - time2);
            std::cout << duration.count() / pow(10, 6) << '\n';
            */
        }
        void tree_sort_caller(){
            std::cout << "Tree Sort\t\t\t";

            auto time1 = high_resolution_clock::now();
            tree_sort(test1, 1000);
            auto time2 = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(time2 - time1);
            std::cout << duration.count() / pow(10, 6) << "\t ";

            tree_sort(test2, 10000);
            time1 = high_resolution_clock::now();
            duration = duration_cast<microseconds>(time1 - time2);
            std::cout << duration.count() / pow(10, 6) << "\t ";

            tree_sort(test3, 100000);
            time2 = high_resolution_clock::now();
            duration = duration_cast<microseconds>(time2 - time1);
            std::cout << duration.count() / pow(10, 6) << "\t ";
            
            tree_sort(test4, 1000000);
            time1 = high_resolution_clock::now();
            duration = duration_cast<microseconds>(time1 - time2);
            std::cout << duration.count() / pow(10, 6) << '\n';
        }
        void quick_sort_caller(){
            std::cout << "Quick Sort\t\t\t";

            auto time1 = high_resolution_clock::now();
            quickSort(test1, 0, 999);
            auto time2 = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(time2 - time1);
            std::cout << duration.count() / pow(10, 6) << "\t ";

            quickSort(test2, 0, 9999);
            time1 = high_resolution_clock::now();
            duration = duration_cast<microseconds>(time1 - time2);
            std::cout << duration.count() / pow(10, 6) << "\t ";

            quickSort(test3, 0, 99999);
            time2 = high_resolution_clock::now();
            duration = duration_cast<microseconds>(time2 - time1);
            std::cout << duration.count() / pow(10, 6) << "\t ";
            
            quickSort(test4, 0, 999999);
            time1 = high_resolution_clock::now();
            duration = duration_cast<microseconds>(time1 - time2);
            std::cout << duration.count() / pow(10, 6) << '\n';
        }

        void sorter(){
            std::cout << "Algorithms \\ Array Sizes \t" << "N = 1000 \t N = 10000 \t N = 100000 \t N = 1000000 \n";
            initialize_array();
            insertion_sort_caller();

            initialize_array();
            selection_sort_caller();

            initialize_array();
            merge_sort_caller();

            initialize_array();
            heap_sort_caller();

            initialize_array();
            tree_sort_caller();

            initialize_array();
            quick_sort_caller();
        }
};

int main(){
    Test tester;
    tester.sorter();
}
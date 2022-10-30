#include <iostream>
#include <cstdlib>
#include <time.h>
#include <chrono>
#include <cmath>

using namespace std::chrono;

struct Node{
    int value;
    struct Node *left, *right;
};
struct Node *newNode(int item){
    struct Node *temp = new Node;
    temp->value = item;
    temp->left = temp->right = NULL;
    return temp;
};

class TreeSort{
    public:
        /* 
        Stores the sorted binary search tree
        In the given array(arr), i is the index holder
        */
        void storeSortedTree(Node *root, int arr[], int &i){
            if(!root != NULL){
                storeSortedTree(root->left, arr, i);
                arr[i++] = root->value;
                storeSortedTree(root->right, arr, i);
            }
        }

        /*
        Inserts new node to the tree
        with given value
        */
        Node* insertNode(Node *node, int item){
            if(node == NULL)
                return newNode(item);
            
            if(item < node->value)
                node->left = insertNode(node->left, item);
            else if(item > node->value)
                node->right = insertNode(node->right, item);

            return node;
        }

        //n = arr.size(()
        void tree_sort(int arr[], int n){
            auto start = high_resolution_clock::now();
            struct Node *root = NULL;

            root = insertNode(root, arr[0]);
            for(int i = 1; i < n; i++)
                root = insertNode(root, arr[i]);
            
            int i = 0;
            storeSortedTree(root, arr, i);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            std::cout<< "Tree sort takes:" << duration.count() / pow(10, 6)<< std::endl;
        }
};

int main(){
    srand(time(0));
    int n1k[1000], n10k[10000], n100k[100000], n1m[1000000];
    int random_num;
    for(int i = 0; i < 1000000; i++){
        random_num = rand();
        if(i < 1000)
            n1k[i] = n10k[i] = n100k[i] = n1m[i] = random_num;
        else if(i < 10000)
            n10k[i] = n100k[i] = n1m[i] = random_num;
        else if(i < 100000)
            n100k[i] = n1m[i] = random_num;
        else
            n1m[i] = random_num;
    }

    TreeSort *treesort = new TreeSort();
    treesort->tree_sort(n1k, 1000);
    treesort->tree_sort(n10k, 10000);
    treesort->tree_sort(n100k, 100000);
    treesort->tree_sort(n1m, 1000000);
}
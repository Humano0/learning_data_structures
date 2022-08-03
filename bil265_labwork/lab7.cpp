#include <iostream>
//#include "d_dnode.h"
#include "d_node.h"
#include <queue>
#include "d_random.h"

using namespace std;

template <typename T>
void writeQueue(const queue<T> tmp) {
    queue<T> tp = tmp;
    cout << "Rastgele degerlerden olusan kuyruk: ";
    while (!tp.empty()) {
        cout << tp.front() << " ";
        tp.pop();
    }
}

template <typename T>
void writeList(node<T>* front)
{
    node<T>* curr = front;
    cout << "\nLink list: ";
    while (curr->next != NULL)
    {
        cout << curr->nodeValue << " ";
        curr = curr->next;
    }
}

template <typename T>
node<T>* queue2List(node<T>* str,const queue<T> tmp) {
    node<T>* front = str;
    queue<T> tp = tmp;
    /*while (!tp.empty()) {  //Kuyruğun başından sırayla listeye atar
        str->next = new node <int>();
        cout << tp.front() << " ";
        str->nodeValue = tp.front();
        str = str->next;
        tp.pop();
    }*/
    while (!tp.empty()) {  //Kuyruğu ters bir şekilde listeye atar
        str = new node<int>(tp.front(), front);
        front = str;
        tp.pop();
    }
    return front;
}

template <typename T>
void addLast(node<T>* last, const T& item) {
    last->next = new node<T>(item, NULL);
}

template <typename T>
void insertAfter(node<T>* curr, const T& item) {
    node<T>* newN = new node<T>(item);
    newN->next = curr->next;
    curr->next = newN;
}

template <typename T>
node<T>* findInLL(node<T>* front, const T& item) {
    node<T>* tmp = front;
    node<T>* prev = front->next;
    while (tmp->next != NULL) {
        if (tmp->nodeValue == item) {
            return tmp;
        }
        else if (prev->nodeValue != item && prev->next == NULL) {
            return tmp;
        }
        tmp = tmp->next;
        prev = prev->next;
    }
}

template <typename T>
void eraseAll(node<T>*& front, const T& target) {
    node<T>* curr = front, * prev = NULL, * deletedNode;
    while (curr != NULL) {
        if (curr->nodeValue == target) {
            deletedNode = curr;
            if (prev == NULL) {
                front = front->next;
                curr = front;
            }
            else {
                prev->next = curr->next;
                curr = prev->next;
            }
            delete deletedNode;
        }
        else {
            prev = curr;
            curr = curr->next;
        }
    }
}

template <typename T>
node<T>* copy(node<T>* front) {
    node<T>* cList = new node<T>(front->nodeValue, NULL);
    node<T>* cNew;
    node<T>* cFront = cList;
    do {
        front = front->next;
        cNew = new node<T>(front->nodeValue,NULL);
        cList->next = cNew;
        cList = cList->next;
    } while (front->next != NULL);
    return cFront;
}

int main()
{
    randomNumber rn;
    node<int>* nnd = new node<int>, *front, *target;
    node<int>* cFront;
    queue<int> quq;
    int x, y;

    cout << "Enter a number: ";
    cin >> x;
    for (int i = 0; i < x; i++)
        quq.push(rn.random(100));


    writeQueue(quq);
    front = queue2List(nnd, quq);
    writeList(front);

    cout << "\n\nDugum degeri giriniz :";
    cin >> x;
    cout << "Klavyeden bir sayi giriniz: ";
    cin >> y;

    nnd = front;
    target = findInLL(nnd, x);
    if (target->next == NULL)
        addLast(target, y);
    else
        insertAfter(target, y);
    writeList(front);

    cout << "\n\nSilmek istediginiz degeri giriniz: ";
    cin >> x;
    eraseAll(front, x);
    writeList(front);

    cFront = copy(front);
    cout << "\n\nExisting list has been copied.";
    writeList(cFront);
}

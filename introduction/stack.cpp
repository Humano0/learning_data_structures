/* 
    All variables in this program are restored in stack.
*/
#include <iostream>

using namespace std;

void stack1();
void stack2(int);

int main()
{
    int a, b;    
    stack1();

    return 0;
}

void stack1(){
    int x;
    stack2(x);
}

void stack2(int x){
    int a;
}
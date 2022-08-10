#include <iostream>

using namespace std;

void add_call_by_value(int x, int y)
{
    cout << x + y << endl
         << endl;
}

void swap_call_by_address(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void swap_call_by_reference(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

int main()
{
    add_call_by_value(10, 5);

    int x1 = 10, x2 = 25;

    swap_call_by_address(&x1, &x2);
    cout << "x1 = " << x1 << endl
         << "x2 = " << x2 << endl
         << endl;

    swap_call_by_reference(x1, x2);
    cout << "x1 = " << x1 << endl
         << "x2 = " << x2 << endl;

    return 0;
}
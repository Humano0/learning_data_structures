#include <iostream>

using namespace std;

template <class T>
class Rectangle
{
private:
    T length, width;

public:
    Rectangle(T length, T width)
    {
        this->length = length;
        this->width = width;
    }

    float get_Length()
    {
        return length;
    }
    void set_Length(T length)
    {
        this->length = length;
    }
    float get_Width()
    {
        return width;
    }
    void set_Width(T width)
    {
        this->width = width;
    }

    T area();
};

template <class T>
T Rectangle<T>::area()
{
    return length * width;
}

int main()
{
    Rectangle<float> rec(7, 8);

    cout << rec.area() << endl;

    return 0;
}
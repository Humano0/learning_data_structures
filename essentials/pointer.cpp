#include <iostream>

using namespace std;

void pointers();
void point_structure();
void point_structure_heap();

struct Rectangle{
  int length, width;  
};

int main()
{
    return 0;
}

void pointers(){
    int req = 10;
    int *preq = &req, *ppreq;
    int &referenceReq = req;
    ppreq = preq;
    
    cout << *ppreq << endl;
    
    cout << &req << "\t" << &referenceReq << endl ;
}

void point_structure(){
    struct Rectangle rec = {10,25};
    struct Rectangle *prec = &rec;
    
    cout << (*prec).length << endl;
    cout << prec->length << endl;
}

void point_structure_heap(){
    struct Rectangle *pp;
    struct Rectangle *p;
    
    pp = new struct Rectangle;
    p = (struct Rectangle *)malloc(sizeof(struct Rectangle));
    
    pp->length = 50;
    pp->width = 25;
    p->length = 10;
    p->width = 55;
    
    cout << pp->length * pp->width << endl;
    cout << p->length * p->width << endl;
}

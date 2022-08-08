#include <iostream>

using namespace std;

struct complex_number{
  float real, imaginary;
  
  void get_name(){
      //imaginary < 0 ? cout << real << imaginary << "i" << endl : cout << real << "+" << imaginary << "i";
      cout << real << (imaginary < 0 ? "" : "+") << imaginary << "i" << endl;
  }
};

int main()
{
    struct complex_number compn = {3, -5};
    
    struct complex_number mul_nums[10];
    
    compn.get_name();
    return 0;
}

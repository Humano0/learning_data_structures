#include <iostream>
#include <vector>

using namespace std;

class ShootingGrounds{
    public:
        int sumOfEvenNumsTAIL(int n, int answer){
            if(n == 0){
                return answer;
            }
            return sumOfEvenNumsTAIL(n - 1, answer + 2 * (n - 1));
        }
        int sumOfEvenNums(int n){
            return sumOfEvenNumsTAIL(n, 0);
        }
};

int main()
{
    //vector<int> test = {2, 4, 6, 8, 10, 12, 14, 16};
    ShootingGrounds *sol = new ShootingGrounds();
    cout << sol->sumOfEvenNums(5);
}
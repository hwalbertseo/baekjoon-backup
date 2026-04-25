#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    long long num = 1;
    for(long long i = n;i >= 2;i--){
        num *= i;
        while(num % 10 == 0){
            num /= 10;
        }
        num %= 100000000;
        /*2
        else{
            cout << num << " " << i << "\n";
        }
        */
    }
    num %= 100000;
    cout << num;
}
//04544

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    long long num = 1;
    for(int i = 2;i <= n;i++){
        num *= i;
        while(num % 10 == 0){
            num /= 10;
        }
        num %= 1000000;
    }
    num %= 100000;
    if(num < 10) cout << "0000" << num;
    else if(num < 100) cout << "000" << num;
    else if(num < 1000) cout << "00" << num;
    else if(num < 10000) cout << "0" << num;
    else{
        cout << num;
    }
}
//04544

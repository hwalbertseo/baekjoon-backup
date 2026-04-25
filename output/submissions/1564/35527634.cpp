#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    long long num = 1;
    for(int i = n;i >= 2;i--){
        num *= (long long)i;
        while(num % 10 == 0){
            num /= 10;
        }
        num %= 1000000000;
        /*2
        else{
            cout << num << " " << i << "\n";
        }
        */
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

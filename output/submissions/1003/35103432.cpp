#include <iostream>

using namespace std;

int num1 = 0;
int num0 = 0;

int fibonacci(int k){
    if(k == 0){
        num0++;
        return 0;
    }
    else if(k==1){
        num1++;
        return 1;
    }
    else{
        return fibonacci(k-1) + fibonacci(k-2);
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int num;
    cin >> num;
    for(int i = 0;i < num;i++){
        num1 = 0;
        num0 = 0;
        int temp = 0;
        cin >> temp;
        fibonacci(temp);
        cout << num0 << " " << num1 << "\n";
    }
}

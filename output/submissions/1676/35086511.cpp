#include <iostream>

using namespace std;

int main()
{
    int num;
    cin >> num;
    int sum = 0;
    for(int i = 5;i <= num;i = i + 5){
        sum++;
    }
    for(int i = 25;i <= num;i = i + 25){
        sum++;
    }
    for(int i = 125;i <= num;i = i + 125){
        sum++;
    }
    cout << sum;
}

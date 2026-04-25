#include <iostream>

using namespace std;

int main()
{
    int arr[10000] = {0,};
    int num;
    cin >> num;
    for(int i = 0;i < num;i++){
        int temp;
        cin >> temp;
        arr[temp-1]++;
    }
    for(int i = 0;i < 10000;i++){
        for(int j = 1;j <= arr[i];j++){
            cout << i+1 << "\n";
        }
    }
}

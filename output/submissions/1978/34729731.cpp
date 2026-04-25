#include <iostream>

using namespace std;

int main()
{
    int arr[1000] = {0,};
    int num;
    int cnt = 0;
    cin >> num;
    for(int i = 2;i <= 1000;i++){
        if(arr[i-1] == 0){
            for(int j = i + i;j <= 1000;j = j + i){
                arr[j-1] = 1;
            }
        }
    }
    for(int i = 0;i < num;i++){
        int temp;
        cin >> temp;
        if(arr[temp-1] == 0 && temp != 1){
            cnt++;
        }
    }
    cout << cnt;
}

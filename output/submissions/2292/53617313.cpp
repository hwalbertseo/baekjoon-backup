#include <iostream>

using namespace std;

long long arr[1000000];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    long long n;
    cin >> n;
    arr[1] = 1;
    arr[0] = 1;
    for(int i = 2;i < 1000000;i++){
        arr[i] = arr[i-1] + i;
    }
    for(int i = 1;i < 1000000;i++){
        arr[i] *= 6;
        arr[i] += 1;
    }
    for(int i = 0;i < 1000000;i++){
        //cout << arr[i-1] << " " << arr[i] << "\n";
        if(n > arr[i-1] && n <= arr[i]){
            cout << i + 1;
            break;
        }
    }
}

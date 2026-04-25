#include <iostream>


using namespace std;

int arr[100005];

int main()
{
    int n, k, b;
    cin >> n >> k >> b;
    fill(arr, arr+n+1, 1);
    arr[0] = 0;
    for(int i = 0;i < b;i++){
        int temp;
        cin >> temp;
        arr[temp] = 0;
    }
    for(int i = 1;i<=n;i++){
        arr[i] = arr[i-1] + arr[i];
    }
    int maxnum = -1;
    for(int i = 0;i <= n-k;i++){
        int temp;
        temp = arr[i+k]-arr[i];
        if(maxnum < temp){
            maxnum = temp;
        }
        //cout << "temp: " << temp << "\n";
    }
    cout << k - maxnum;
}

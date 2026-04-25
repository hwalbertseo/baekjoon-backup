#include <iostream>
#include <algorithm>

using namespace std;

int arr[1005];

int main()
{
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);
    for(int i = 1;i < n;i++){
        arr[i] = arr[i]+arr[i-1];
    }
    int ans = 0;
    for(int i = 0;i < n;i++){
        ans += arr[i];
    }
    cout << ans;
}

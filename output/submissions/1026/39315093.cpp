#include <iostream>
#include <algorithm>

using namespace std;

int arr[100];
int brr[100];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    for(int i = 0;i < n;i++){
        cin >> brr[i];
    }
    sort(arr, arr+n);
    sort(brr, brr+n, greater<int>());
    int cnt = 0;
    for(int i = 0;i < n;i++){
        cnt += arr[i]*brr[i];
    }
    cout << cnt;
}

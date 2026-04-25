#include <iostream>
#include <algorithm>

using namespace std;

int arr[100005];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);
    int m;
    cin >> m;
    int hi = n-1;
    int lo = 0;
    int cnt = 0;
    while(hi > lo){
        int temp = arr[hi] + arr[lo];
        if(temp == m){
            cnt++;
            lo++;
            hi--;
        }
        else if(temp > m){
            hi--;
        }
        else{
            lo++;
        }
    }
    cout << cnt;
}

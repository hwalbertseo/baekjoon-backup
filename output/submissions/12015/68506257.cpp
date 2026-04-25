#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[1000000];
int ans[1000000];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    ans[0] = arr[0];
    int len = 1;
    for(int i = 1;i < n;i++){
        int cur = arr[i];
        if(cur > arr[len-1]){
            arr[len] = cur;
            len++;
        }
        else{
            int idx = lower_bound(arr, arr+len, cur) - arr;
            ans[idx] = cur;
        }
    }
    cout << len;
}
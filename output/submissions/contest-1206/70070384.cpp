#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

int arr[100000];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    int sum = 0;
    for(int i = 1;i <= n;i++){
        cin >> arr[i];
        sum += arr[i];
    }
    int ans = 0;
    ans += sum*2;
    ans += n*2;
    for(int i = 1;i <= n;i++){
        int left = max(0, arr[i] - arr[i-1]);
        int right = max(0, arr[i] - arr[i+1]);
        ans += left + right;
    }
    cout << ans;  
}
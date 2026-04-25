#include <iostream>
#include <algorithm>

using namespace std;

int dp[200010];
int arr[200010];

int main(){
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> arr[i];
    }
    dp[1] = arr[1];
    dp[2] = arr[1] + arr[2];
    for(int i = 1;i <= n;i++){
        dp[i] = max(dp[i-1] + arr[i], dp[i]);
        dp[i+2] = dp[i-1] + (arr[i] + arr[i+1] + arr[i+2])*2;
    }
    cout << max(dp[n+2], dp[n]);
}
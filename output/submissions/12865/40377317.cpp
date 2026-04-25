#include <iostream>
#include <algorithm>

using namespace std;

int arr[105][2];
int dp[105][100005];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int p, q;
    cin >> p >> q;
    for(int i = 1;i <= p;i++){
        cin >> arr[i][0] >> arr[i][1];
    }
    for(int i = 1;i <= p;i++){
        for(int j = 1;j <= q;j++){
            int w = arr[i][0];
            int v = arr[i][1];
            if(w > j){
                dp[i][j] = dp[i-1][j];
                continue;
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-w]+v);
            }
        }
    }
    cout << dp[p][q];
}

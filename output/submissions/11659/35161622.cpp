#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    int arr[1005] = {0,};
    int sum[1005] = {0,};
    for(int i = 1;i<=n;i++){
        cin >> arr[i];
        sum[i] = sum[i-1] + arr[i];
    }
    for(int i = 0;i < m;i++){
        int s, e;
        cin >> s >> e;
        cout << sum[e]-sum[s-1] << "\n";
    }
}

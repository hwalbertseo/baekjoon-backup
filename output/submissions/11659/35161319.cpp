#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    int arr[1005];
    for(int i = 0;i<n;i++){
        cin >> arr[i];
    }
    for(int i = 0;i < m;i++){
        int s, e;
        cin >> s >> e;
        int sum = 0;
        for(int j = s;j <= e;j++){
            sum += arr[j-1];
        }
        cout << sum << "\n";
    }
}

#include <iostream>
#include <algorithm>

using namespace std;

int arr[100005];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, q;
    cin >> n >> q;
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);
    for(int j = 0;j < q;j++){
        int p, q;
        cin >> p >> q;
        int lb = lower_bound(&arr[0], &arr[n], p) - &arr[0];
        int ub = upper_bound(&arr[0], &arr[n], q) - &arr[0];
        cout << ub - lb << "\n";
    }
}

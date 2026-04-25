#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;

vector<pii> vec;
int arr[15000005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n = 0;
    cin >> n;
    vec.push_back({0, 0});
    for(int i = 0;i < n;i++){
        int a = 0, b = 0;
        cin >> a >> b;
        vec.push_back({a, b});
    }
    for(int i = 1;i < vec.size();i++){
        int days = vec[i].first;
        int money = vec[i].second;
        arr[i] = max(arr[i-1], arr[i]);
        arr[i + days - 1] = max(money + arr[i-1], arr[i + days - 1]);
    }
    // for(int i = 1;i <= n;i++){
    //     cout << arr[i] << " ";
    // }
    cout << arr[n];
}
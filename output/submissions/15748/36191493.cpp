#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

pair<int, int> arr[100005];

bool comp(pair<int, int> a, pair<int, int> b){
    if(a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int l, n, rp, rb;
    cin >> l >> n >> rp >> rb;
    stack<pair<int, int>> s;

    for(int i = 0;i < n;i++){
        int p, q;
        cin >> p >> q;
        arr[i] = {p, q};
    }

    sort(arr, arr+n, comp);

    for(int i = n-1;i >= 0;i--){
        s.push(arr[i]);
    }
    int cnt = 0;
    int distance = 0;
    while(s.size() > 0){
        if(s.top().first <= distance){
            s.pop();
            continue;
        }
        cnt += (s.top().first - distance) * s.top().second;
        distance = s.top().first;
        s.pop();
    }
    cout << cnt;
}

#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

pair<long long , long long > arr[100005];

bool comp(pair<long long , long long > a, pair<long long , long long > b){
    if(a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    long long l, n, rp, rb;
    cin >> l >> n >> rp >> rb;
    stack<pair<long long , long long >> s;
    int d = rp - rb;

    for(long long i = 0;i < n;i++){
        int p, q;
        cin >> p >> q;
        arr[i] = {p*d, q};
    }

    sort(arr, arr+n, comp);

    for(long long i = n-1;i >= 0;i--){
        s.push(arr[i]);
    }
    long long cnt = 0;
    long long distance = 0;
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

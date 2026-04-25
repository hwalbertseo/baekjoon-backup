#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

struct sta{
    ll first, second, num;
};

sta arr[1000001];
bool visit[500005];

bool comp(sta a, sta b){
    if(a.first == b.first){
        return a.second > b.second;
    }
    return a.first < b.first;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n, m;
    cin >> n >> m;
    ll idx = 0;
    for(ll i = 0;i < m;i++){
        ll p, q;
        cin >> p >> q;
        if(p < q){
            sta temp;
            temp.first = p;
            temp.second= q;
            temp.num = i+1;
            arr[idx] = temp;

            sta temp2;
            temp2.first = p+n;
            temp2.second= q+n;
            temp2.num = i+1;
            arr[idx+1] = temp2;
            idx += 2;
        }
        else{
            sta temp;
            temp.first = p;
            temp.second = q+n;
            temp.num = i+1;
            arr[idx] = temp;
            idx++;
        }
    }
    sort(arr, arr+idx, comp);
    ll fin = -1;
    for(ll i = 0;i < idx;i++){
        //cout << arr[i].first << " " << arr[i].second << " " << arr[i].num << "\n";
        if(arr[i].second <= fin){
            visit[arr[i].num] = 1;
        }
        else{
            fin = arr[i].second;
        }
    }
    for(ll i = 1;i <= m;i++){
        if(visit[i] == 0){
            cout << i << " ";
        }
    }
}

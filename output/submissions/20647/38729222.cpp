#include <iostream>
#include <vector>
#define ll long long

using namespace std;

vector<ll> arr[100005];
ll visit[100005];
ll days = 0;
ll pow2[50];

void dfs(ll cur){
    visit[cur] = 1;
    ll s = 0;
    for(ll i = 0;i < arr[cur].size();i++){
        if(visit[arr[cur][i]] == 0){
            s++;
        }
    }
    for(ll i = 0;i < 50;i++){
        if(pow2[i] >= s+1){
            days += i;
            break;
        }
    }
    days += s;
    for(ll i = 0;i < arr[cur].size();i++){
        if(visit[arr[cur][i]] == 1){
            continue;
        }
        dfs(arr[cur][i]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n;
    cin >> n;
    for(ll i = 0;i < n-1;i++){
        ll p, q;
        cin >> p >> q;
        arr[p].push_back(q);
        arr[q].push_back(p);
    }
    ll temp = 1;
    for(ll i = 0;i < 50;i++){
        pow2[i] = temp;
        temp *= 2;
    }
    dfs(1);
    cout << days;
}

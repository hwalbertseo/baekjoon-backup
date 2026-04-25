#include <iostream>
#include <stack>
#define ll long long

using namespace std;

ll arr[100005];
stack<pair<char, ll>> st;
ll f[100005];
ll b[100005];
bool visit[100005];

void clearvis(){
    for(int i = 0;i < 100005;i++){
        visit[i] = 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    ll cnt = 1;
    for(ll i = 0;i < n;i++){
        bool changed = false;
        while(!st.empty() && st.top().first > s[i]){
            st.pop();
        }
        if(st.empty() || st.top().first != s[i]){
            arr[i] = cnt;
            cnt++;
        }
        else{
            arr[i] = st.top().second;
        }
        st.push({s[i], arr[i]});
    }
    cnt = 0;
    for(ll i = 0;i < n;i++){
        if(visit[arr[i]] == 1){
            f[i] = cnt;
        }
        else{
            cnt++;
            f[i] = cnt;
            visit[arr[i]] = 1;
        }
    }
    clearvis();
    cnt = 0;
    for(ll i = n-1;i >= 0;i--){
        if(visit[arr[i]] == 1){
            b[i] = cnt;
        }
        else{
            cnt++;
            b[i] = cnt;
            visit[arr[i]] = 1;
        }
    }
    for(ll i = 0;i < q;i++){
        ll aq, bq;
        cin >> aq >> bq;
        ll ans = 0;
        ans += f[aq-2];
        ans += b[bq];
        cout << ans << "\n";
    }
}

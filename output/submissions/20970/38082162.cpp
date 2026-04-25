#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int n, m;
int arr[100005];
vector<int> v[100005];
int h[100005];
int visit[100005];
vector<int> valid;
bool r = false;
int first;
set<int> s[100005];

void rec(int cur){
    if(visit[cur] == 1){
        return;
    }
    visit[cur] = 1;
    int nxt = v[cur][v[cur].size()-1];
    if(r){
        //cout << cur << endl;
        h[cur] = first;
        for(int i = 1;i < v[cur].size();i++){
            v[first].push_back(v[cur][i]);
        }
        if(visit[nxt] == 0){
            rec(nxt);
        }
    }
    else{
        //cout << cur << endl;
        valid.push_back(cur);
        first = cur;
        h[cur] = cur;
        r = true;
        rec(nxt);
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        arr[i] = i;
        v[i].push_back(i);
    }
    for(int i = 0;i < m;i++){
        int p, q;
        cin >> p >> q;
        int temp = arr[p];
        arr[p] = arr[q];
        arr[q] = temp;
        v[arr[p]].push_back(p);
        v[arr[q]].push_back(q);
    }
    for(int i = 1;i <= n;i++){
        if(visit[i] != 1){
            r = false;
            rec(i);
        }
    }
    for(int i = 0;i < valid.size();i++){
        //cout << i << endl;
        int nxt = valid[i];
        for(int j = 0;j < v[nxt].size();j++){
            s[nxt].insert(v[nxt][j]);
        }
    }
    for(int i = 1;i <= n;i++){
        cout << s[h[i]].size() << "\n";
    }
}

#include <iostream>
#include <vector>

using namespace std;

int n, m;
string str;
vector<int> arr[100005];
int visit[100005];
int num[100005];
int nb = 0;

void dfs(int cur, char c){
    visit[cur] = 1;
    num[cur] = nb;
    for(int i = 0;i < arr[cur].size();i++){
        int nxt = arr[cur][i];
        if(visit[nxt] == 1){
            continue;
        }
        else if(str[nxt-1] != c){
            continue;
        }
        else{
            dfs(nxt, c);
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    cin >> str;
    for(int i = 0;i < n-1;i++){
        int p, q;
        cin >> p >> q;
        arr[p].push_back(q);
        arr[q].push_back(p);
    }
    for(int i = 1;i <= n;i++){
        if(visit[i] == 1){
            continue;
        }
        nb++;
        dfs(i, str[i-1]);
    }
    for(int i = 0;i < m;i++){
        int p, q;
        char c;
        cin >> p >> q >> c;
        if(num[p] == num[q]){
            if(str[p-1] == c){
                cout << 1;
            }
            else{
                cout << 0;
            }
        }
        else{
            cout << 1;
        }
    }
}

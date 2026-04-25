#include <iostream>
#include <vector>

using namespace std;

int n, m;
pair<int, int> arr[100005];
vector<int> v[100005];
int visit[100005];
int x1, x2, y1, y2;

void dfs(int cur){
    visit[cur] = 1;
    for(int i = 0;i < v[cur].size();i++){
        int now = v[cur][i];
        if(arr[now].first > x1){
            x1 = arr[now].first;
        }
        if(arr[now].first < x2){
            x2 = arr[now].first;
        }
        if(arr[now].second < y1){
            y1 = arr[now].second;
        }
        if(arr[now].second > y2){
            y2 = arr[now].second;
        }
        if(visit[now] == 0){
            dfs(now);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        int p, q;
        cin >> p >> q;
        arr[i+1] = {p,q};
    }
    for(int i = 0;i < m;i++){
        int p, q;
        cin >> p >> q;
        v[p].push_back(q);
        v[q].push_back(p);
    }
    int marea = 2e9;
    for(int i = 1;i <= n;i++){
        if(visit[i] == 0){
            x1 = -1, x2 = 2e9, y1 = 2e9, y2 = -1;
            dfs(i);
            int ans = (x1-x2)*2 + (y2-y1)*2;
            //cout << i << " " << x1 << " " << y1 << " " << x2 << " " << y2 << "\n";
            if(ans < marea){
                marea = ans;
            }
        }
    }
    cout << marea;
}

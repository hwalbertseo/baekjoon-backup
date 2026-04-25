#include <iostream>
#include <vector>

using namespace std;

vector<int> arr[100005];
bool visit[100005];
int subTree[100005];
int n, r;
vector<int> path;

void dfs(int cur, int last){
    path.erase(path.begin() + last, path.begin() + path.size());
    //cout << "cur "<< cur << "\n";
    visit[cur] = 1;
    subTree[cur]++;
    for(int i = 0;i < path.size();i++){
        subTree[path[i]]++;
    }
    path.push_back(cur);
    for(int i = 0;i < arr[cur].size();i++){
        int nxt = arr[cur][i];
        if(visit[nxt] == 0){

            dfs(nxt, last + 1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int q;
    cin >> n >> r >> q;
    for(int i = 1;i < n;i++){
        int p, q;
        cin >> p >> q;
        arr[p].push_back(q);
        arr[q].push_back(p);
    }
    dfs(r,0);
    for(int i = 0;i < q;i++){
        int temp;
        cin >> temp;
        cout << subTree[temp] << "\n";
    }
}

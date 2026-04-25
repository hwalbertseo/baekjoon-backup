#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool arr[101];
set<int> s;

void dfs(vector<vector<int>> v, int p){
    //cout << "p: " << p << "\n";
    s.insert(p);
    if(!arr[p]){
        arr[p] = true;
        //cout << "entered p: " << p << "\n";
        for(int i = 0;i < v[p].size();i++){
            dfs(v, v[p][i]);
        }
    }
    else return;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v;
    //set<int> s;
    for(int i = 0;i <= n;i++){
        vector<int> temp;
        v.push_back(temp);
    }
    for(int i = 0;i < m;i++){
        int p, q;
        cin >> p >> q;
        v[p].push_back(q);
        v[q].push_back(p);
    }
    /*
    for(int i = 1;i <= n;i++){
        cout << i << ": ";
        for(int j = 0;j < v[i].size();j++){
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
    */
    dfs(v, 1);
    cout << s.size() - 1;
}

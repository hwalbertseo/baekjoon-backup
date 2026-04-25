#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> arr[100005];
int visit[100005];
vector<int> path;
int cycleNum = 0;

void dfs(int cur){
    visit[cur] = 1;
    path.push_back(cur);
    for(int i = 0;i < arr[cur].size();i++){
        if(visit[arr[cur][i]] == 1){
            int idx = -1;
            for(int j = 0;j < path.size();j++){
                if(arr[cur][i] == path[j]){
                    idx = j;
                }
            }
            if(idx != -1){
                cycleNum += path.size()-idx;
            }
        }
        else{
            dfs(arr[cur][i]);
        }
    }
}

int main()
{
    cin >> n;
    for(int i = 1;i <= n;i++){
        int temp;
        cin >> temp;
        arr[i].push_back(temp);
    }
    for(int i = 1;i <= n;i++){
        if(visit[i] == 0){
            dfs(i);
            path.clear();
        }
    }
    cout << cycleNum;
}

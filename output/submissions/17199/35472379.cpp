#include <iostream>
#include <vector>

using namespace std;

vector<int> arr[105];
bool visit[105];
int cnt = 0;
int n;

void init(){
    for(int i = 0;i < 105;i++){
        visit[i] = 0;
    }
}

void dfs(int current){
    visit[current] = true;
    cnt++;
    for(int i = 0;i < arr[current].size();i++){
        if(!visit[arr[current][i]]){
            dfs(arr[current][i]);
        }
    }
}

int main()
{
    cin >> n;
    for(int i = 1;i < n;i++){
        int p, q;
        cin >> p >> q;
        arr[q].push_back(p);
    }
    for(int i = 1;i < n;i++){
        cnt = 0;
        dfs(i);
        if(cnt == n){
            cout << i;
            return 0;
        }
        init();
    }
    cout << -1;
}

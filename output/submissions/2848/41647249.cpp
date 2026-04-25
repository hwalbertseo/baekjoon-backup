#include <iostream>
#include <vector>
#include <queue>

using namespace std;

string strs[105];
vector<int> graph[30];
int pres[30];
int gr[30][30];
int visit[30];
int visited[30];
int ind[30];
queue<int> q;
vector<char> vq;

bool dfs(int cur){
    //cout << char(cur+'a') << "\n";
    if(visited[cur] != 0){
        if(visited[cur] == -1){
            //cout << "here: " << char(cur+'a') << "\n";
            return true;
        }
        return false;
    }
    visited[cur] = -1;
    for(int i = 0;i < graph[cur].size();i++){
        //cout << char(cur+'a') << " " << char(graph[cur][i] + 'a') << "\n";
        if(dfs(graph[cur][i])){
            return true;
        }
    }
    visited[cur] = 1;

    return false;
}

bool checkcycle(){
    for(int i = 0;i < 26;i++){
        if(visited[i] == 0 && pres[i] == 1){
            //cout << "beg: " << char(i+'a') << endl;
            bool t = dfs(i);
            if(t){
                return t;
            }
        }
        for(int j = 0;j < 30;j++){
            visited[j] = 0;
        }
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> strs[i];
        for(int j = 0;j < strs[i].size();j++){
            pres[strs[i][j]-'a'] = 1;
        }
    }
    for(int i = 0;i < n;i++){
        for(int j = i+1;j < n;j++){
            for(int r = 0;r < 10;r++){
                if(r >= strs[i].size() || r >= strs[j].size()){
                    break;
                }
                int a = strs[i][r] - 'a';
                int b = strs[j][r] - 'a';
                if(a == b){
                    continue;
                }
                else{
                    gr[a][b] = 1;
                    break;
                }
            }
        }
    }
    for(int i = 0;i < 26;i++){
        for(int j = 0;j < 26;j++){
            if(gr[i][j] == 1){
                graph[i].push_back(j);
                ind[j]++;
            }
        }
    }
/*
    for(int i = 0;i <26;i++){
        if(pres[i] == 1){
            cout << char(i+'a') << endl;;
            for(int j = 0;j < graph[i].size();j++){
                cout << char(graph[i][j]+'a') << " ";
            }
            cout << endl;
        }
    }
    cout << endl;
*/
    bool temp = checkcycle();
    if(temp){
        cout << "!";
        return 0;
    }
    for(int i = 0;i < 30;i++){
        if(pres[i] == 1 && ind[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        if(q.size() >= 2){
            cout << "?";
            return 0;
        }
        int cur = q.front();
        q.pop();
        if(visit[cur] == 1){
            cout << "!";
            return 0;
        }
        visit[cur] = 1;
        vq.push_back(cur + 'a');
        for(int i = 0;i < graph[cur].size();i++){
            int nxt = graph[cur][i];
            //cout << char(cur+'a') << " " << char(nxt+'a') << " " << ind[nxt] << "\n";
            ind[nxt]--;
            if(ind[nxt] == 0){
                q.push(nxt);
            }
        }
        //cout << q.size() << "\n";
    }
    for(int i = 0;i < 26;i++){
        if(visit[i] == 0 && pres[i] == 1){
            cout << "?";
            return 0;
        }
    }
    for(int i = 0;i < vq.size();i++){
        cout << vq[i];
    }
}

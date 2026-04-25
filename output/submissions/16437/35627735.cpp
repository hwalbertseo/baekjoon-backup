#include <iostream>
#include <vector>

using namespace std;

vector<int> arr[123460];
char animal[123460];
long long numan[123460];
long long subTree[123460];
int visit[123460];
int n;

long long dfs(int cur){
    visit[cur] = 1;
    //cout << cur << "\n";
    for(int i = 0;i < arr[cur].size();i++){
        int nxt = arr[cur][i];
        //cout << cur << " " << nxt << "\n";
        if(visit[nxt] != 1){
            subTree[cur] += dfs(nxt);
            //cout << "cur: " << cur << " subTree: "<< subTree[cur] << "\n";
        }
    }
    if(animal[cur] == 'W'){
        long long temp = subTree[cur] - numan[cur];
        return ((temp > 0) ? temp : 0);
    }
    else{
        return (subTree[cur] + numan[cur]);
    }

}

int main()
{
    cin >> n;
    for(int i = 2;i <= n;i++){
        char an;
        int num;
        int br;
        cin >> an >> num >> br;
        animal[i] = an;
        arr[i].push_back(br);
        arr[br].push_back(i);
        numan[i] = num;
    }
    dfs(1);
    cout << subTree[1];
}

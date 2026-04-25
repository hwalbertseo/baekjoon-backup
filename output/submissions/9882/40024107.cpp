#include <iostream>
#include <vector>

using namespace std;

int n = 12;
int inp[15];
vector<int> arr[4];
int big = 2e9;

void dfs(int cur){
    if(cur >= n){
        int ma = -1;
        int mi = 2e9;
        int add = 0;
        /*
        for(int i = 0;i < 4;i++){
            for(int j = 0;j < 3;j++){
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        */

        for(int i = 0;i < 4;i++){
            //cout << "in";
            for(int j = 0;j < 3;j++){
                add += arr[i][j];
            }
            //cout << add << "\n";
            if(add > ma){
                ma = add;
            }
            if(add < mi){
                mi = add;
            }
            //cout << add << " " << ma << " " << mi << "\n";
            //cout << "in";
            add = 0;
        }
        if(big > ma-mi){
            big = ma - mi;
        }
        return;
    }
    for(int i = 0;i < 4;i++){
        if(arr[i].size() > 2){
            continue;
        }
        arr[i].push_back(inp[cur]);
        dfs(cur+1);
        arr[i].pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    for(int i = 0;i < 12;i++){
        cin >> inp[i];
    }
    dfs(0);
    cout << big;
}

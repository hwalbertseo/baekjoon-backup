#include <iostream>

using namespace std;

char grid[1005][1005];
pair<int, int> ufind[1005][1005];

pair<int, int> srch(int x, int y){
    pair<int, int> temp = {x, y};
    if(ufind[x][y] == temp){
        return {x, y};
    }
    return ufind[x][y] = srch(ufind[x][y].first, ufind[x][y].second);
}

void comb(int x1, int y1, int x2, int y2){
    pair<int, int> p = srch(x1, y1);
    pair<int, int> q = srch(x2, y2);
    if(p == q){
        return;
    }
    ufind[p.first][p.second] = q;
}

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int p, q;
  cin >> p >> q;
  for(int i = 0;i < p;i++){
    string s;
    cin >> s;
    for(int j = 0;j < q;j++){
        grid[i][j] = s[j];
        ufind[i][j] = {i, j};
    }
  }
/*
  for(int i = 0;i < p;i++){
    for(int j = 0;j < q;j++){
        cout << "(" << i << " " << j << ")";
    }
    cout <<endl;
  }
*/
  for(int i = 0;i < p;i++){
    for(int j = 0;j < q;j++){
        if(grid[i][j] == 'D'){
            comb(i, j, i+1, j);
        }
        else if(grid[i][j] == 'L'){
            comb(i, j, i, j-1);
        }
        else if(grid[i][j] == 'R'){
            comb(i, j, i, j+1);
        }
        else if(grid[i][j] == 'U'){
            comb(i, j, i-1, j);
        }
    }
  }



  int ans = 0;
  for(int i = 0;i < p;i++){
    for(int j = 0;j < q;j++){
        pair<int, int> temp = {i, j};
        if(srch(i, j) == temp){
            ans++;
        }
    }
  }
  cout << ans;
}

/*
*/

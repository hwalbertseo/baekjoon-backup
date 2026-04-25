#include <iostream>
#include <cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int N;
int map[25][25];
int cnt = 0;  //번호 하나당 총 아파트 개수 누적
bool visited[25][25];
vector<int> v;
int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };

void dfs(int x, int y) {

    for (int i = 0; i < 4; i++) {

        int nx = x + dir[i][0];
        int ny = y + dir[i][1];

        if (0 <= nx && nx < N && 0 <= ny && ny < N) {
            if (visited[nx][ny] == false && map[nx][ny] == 1) {
                visited[nx][ny] = true;
                cnt++;
                dfs(nx, ny);
            }
        }   

    }
}

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf_s("%1d", &map[i][j]);  //입력이 특이하기 때문에 #include <cstdio>

            //cin >> map[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j] == false && map[i][j] == 1) {
 
                visited[i][j] = true;
                cnt++;

                dfs(i, j);
                v.push_back(cnt);
                cnt = 0;
            }
        }
    }
    cout << v.size() << "\n";
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << "\n";
 
    }

}
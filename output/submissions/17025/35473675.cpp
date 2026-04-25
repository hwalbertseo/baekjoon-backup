#include <iostream>

using namespace std;

//perimiter 구하면 된다 미래의 나야

int arr[1005][1005];
int visit[1005][1005];
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
int n;
int area = 0;
int maxArea = -1;
int per = 0;
int minPer = 2147483647;

void dfs(int x, int y){
    visit[x][y] = 1;
    for(int i = 0;i < 4;i++){
        int cx = dx[i]+x;
        int cy = dy[i]+y;
        if(visit[cx][cy] == 1) {
            continue;
        }
        if(arr[cx][cy] != 1){
            per++;
        }
        else if(arr[cx][cy] == 1){
            area++;
            dfs(cx, cy);
        }
    }
}

int main()
{
   cin >> n;
   for(int i = 1;i <= n;i++){
       string temp;
       cin >> temp;
       for(int j = 1;j <= n;j++){
            if(temp[j-1] == '#'){
                arr[i][j] = 1;
            }
            else{
                arr[i][j] = 0;
            }
       }
   }

   for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            if(arr[i][j] == 1 && visit[i][j] == 0){
                area = 1;
                per = 0;
                dfs(i, j);
                if(area > maxArea){
                    maxArea = area;
                    minPer = per;
                }
                else if(area == maxArea){
                    if(minPer > per){
                        minPer = per;
                    }
                }
            }
        }
   }
   /*
   for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            cout << visit[i][j] << " ";
        }
        cout << "\n";
   }
   */
   cout << maxArea << " " << minPer;
}

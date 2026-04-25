#include <iostream>

using namespace std;

int n, k;
int arr[105][15];
int visit[105][15];
bool exist = false;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

void invis(){
    for(int i = 0;i < n;i++){
        for(int j = 0;j < 10;j++){
            visit[i][j] = 0;
        }
    }
}

void init(){
    invis();
    exist = false;
}


void ff(int x, int y, int cur, int num){
    /*
    cout << "\n";
    for(int i = n-1;i >= 0;i--){
        for(int j = 0;j < 10;j++){
            cout << arr[i][j];
        }
        cout << "\n";
    }
    */
    //cout << x << " " << y << " " << cur << " " << num << "\n";

    visit[x][y] = 1;
    /*
    cout << visit[1][0] << endl;
    */
    if(num >= k){
        //cout << k << "\n";
        exist = true;
        arr[x][y] = 0;
    }
    for(int i = 0;i < 4;i++){
        int xx = dx[i] + x;
        int yy = dy[i] + y;
        if(xx < 0 || xx >= n || yy < 0 || yy >= 10){
            continue;
        }
        if(arr[xx][yy] == cur){
            //cout << "visit: " << visit[xx][yy] << " " << xx << " " << yy << "\n";
            //cout << arr[xx][yy] << " " << cur << "\n";
            if(visit[xx][yy] == 0){
                ff(xx, yy, cur, num+1);
            }
            else {
                if(num >= k){
                    ff(xx, yy, cur, num+1);
                }
            }
            //if(num < k) break;
        }
    }
}

void gravity(int y){
    int cntz = 0;
    for(int i = 0;i < n;i++){
      //cout << "arr: " << arr[i][y] << endl;
      if(arr[i][y] == 0){
        cntz++;
        //cout << cntz << endl;
      }
      else{
        //cout << cntz << endl;
        for(int j = i;j < n;j++){
         arr[j-cntz][y] = arr[j][y]; 
         if(cntz != 0) arr[j][y] = 0;
        }
        //i--;
        cntz = 0;
      }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k;
    for(int i = n-1;i >= 0;i--){
        string temp;
        cin >> temp;
        for(int j = 0;j < 10;j++){
            arr[i][j] = temp[j]-48;
        }
    }
    while(1){
        init();
        for(int i = 0;i < n;i++){
            //int zcount = 0;
            for(int j = 0;j < 10;j++){
                if(arr[i][j] != 0) {
                    ff(i, j, arr[i][j], 1);

                }
            }
        }

        for(int i = 0;i < 10;i++){
            gravity(i);
        }
        if(!exist) break;
    }
    //cout << "\n";
    for(int i = n-1;i >= 0;i--){
        for(int j = 0;j < 10;j++){
            cout << arr[i][j];
        }
        cout << "\n";
    }
}

/*
3 20
1111111111
1111111111
1111144444
*/

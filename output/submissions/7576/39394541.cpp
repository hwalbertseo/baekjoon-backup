#include <iostream>
#include <queue>

using namespace std;

int tomato[1001][1001];
int m, n, ans, cnt, curTomato, newTomato;

class Point{
    public:
    int x, y;
    Point(){
        x = 0;
        y = 0;
    }
    Point(int a, int b){
        x = a;
        y = b;
    }
};

queue<Point> ripe;
queue<Point> toRipe;

void riping(int a, int b){
    if(a >= 1){
        if(tomato[a - 1][b] == 0){
            tomato[a - 1][b]++;
            ripe.push(Point(a-1, b));
            cnt--;
            newTomato++;
        }
    }
    if(b >= 1){
        if(tomato[a][b-1] == 0){
            tomato[a][b - 1]++;
            ripe.push(Point(a, b -1));
            cnt--;
            newTomato++;
        }
    }
    if(a <= n - 2){
        if(tomato[a + 1][b] == 0){
            tomato[a + 1][b]++; 
            ripe.push(Point(a+1, b));
            cnt--;
            newTomato++;
        }
    }
    if(b <= m - 2){
        if(tomato[a][b+1] == 0){
            tomato[a][b + 1]++;
            ripe.push(Point(a, b+1));
            cnt--;
            newTomato++;
        }
    }
}

bool check(){
    while(toRipe.size() != 0){
        Point tmp = toRipe.front();
        toRipe.pop();
        int possible = 0, ch = 0;
        if(tmp.x >= 1){
            possible++;
            if(tomato[tmp.x - 1][tmp.y] == -1){
                ch++;
            }
        }
        if(tmp.y >= 1){
            possible++;
            if(tomato[tmp.x][tmp.y-1] == -1){
                ch++;
            }
        }
        if(tmp.x <= n - 2){
            possible++;
            if(tomato[tmp.x + 1][tmp.y] == -1){
                ch++;
            }
        }
        if(tmp.y <= m - 2){
            possible++;
            if(tomato[tmp.x][tmp.y+1] == -1){
                ch++;
            }
        }
        if(possible == ch){
            return true;
        }
    }
    return false;
}

void solve(){
    while(cnt != 0){
        ans++;
        while(!ripe.empty()){
            Point tmp = ripe.front();
            ripe.pop();
            int a = tmp.x;
            int b = tmp.y;
            riping(a, b);
        }
        curTomato = newTomato;
        newTomato = 0;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>m>>n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>tomato[i][j];
            if(tomato[i][j] == 1){
                Point tmp = Point(i, j);
                ripe.push(tmp);
                curTomato++;
            }
            else if(tomato[i][j] == 0){
                Point tmp = Point(i, j);
                toRipe.push(tmp);
                cnt++;
            }
        }
    }
    
    if(check()){
        cout<<"-1";
    }
    else{
        solve();
        cout<<ans;
    }
    
    return 0;
}
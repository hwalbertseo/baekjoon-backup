#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int x, y, w, h;
    int dist = 1e9;
    cin >> x >> y >> w >> h;
    if(x < y){
        dist = x;
    }
    else{
        dist = y;
    }
    if(w-x < dist){
        dist = w-x;
    }
    if(h-y < dist){
        dist = h-y;
    }
    cout << dist;
}

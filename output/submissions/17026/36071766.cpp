#include <iostream>
#include <algorithm>

using namespace std;

struct coo{
    long long x;
    long long y;
};

coo arr[100005];

bool comp(coo a, coo b){
    return a.y > b.y;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        long long p, q;
        cin >> p >> q;
        arr[i].x = p;
        arr[i].y = q;
    }
    sort(arr, arr+n, comp);
    int cnt = 1;
    for(int i = 1;i < n;i++){
        bool possible = true;
        for(int j = i-1;j >= 0;j--){
            int height = arr[j].y - arr[i].y;
            if(height == 0) continue;
            if(arr[i].x == arr[j].x) possible = false;
            else if(arr[i].x > arr[j].x){
                if(arr[i].x - arr[j].x <= height){
                    possible = false;
                }
            }
            else{
                if(arr[j].x - arr[i].x <= height){
                    possible = false;
                }
            }
        }
        if(possible) cnt++;
    }
    cout << cnt;
}

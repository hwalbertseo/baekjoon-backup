#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

struct coo{
    int x;
    int y;
};

coo arr[100005];

bool comp(coo a, coo b){
    return a.y > b.y;
}

int main()
{
    int n = 0;
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> arr[i].x >> arr[i].y;
    }
    sort(arr, arr+n, comp);
    map<int, int> m;
    int cnt = 0;
    for(int i = 0;i < n;i++){
        if(m[arr[i].x] > arr[i].y) {
            cnt++;
            continue;
        }
        for(int j = arr[i].y;j >= 0;j--){
            int diff = arr[i].y - j;
            int x = arr[i].x - diff;
            if(x >= 0){
                m[x];
                if(m[x] < j) m[x] = j;
            }
            x = arr[i].x + diff;
            if(x <= 1e9){
                m[x];
                if(m[x] < j) m[x] = j;
            }
        }
    }
    cout << n-cnt;
}

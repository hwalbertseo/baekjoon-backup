#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

struct lo{
    int f;
    int b;
    int h;
};

lo arr[100005];
int beg[100005];

bool comp(lo a, lo b){
    if(a.f == b.f) return a.b < b.b;
    else return a.f < b.f;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, q;
    cin >> n >> q;
    //int minstart = 2147483647;
    //int maxend = -1;
    for(int i = 0;i < n;i++){
        cin >> arr[i].f >> arr[i].b >> arr[i].h;
        beg[i] = arr[i].f;
    }

    sort(arr, arr+n, comp);

    int lo = arr[0].f;
    int hi = arr[0].b;
    int num = 1;
    beg[0] = num;
    for(int i = 1;i < n;i++){
        if(arr[i].f > hi){
            lo = arr[i].f;
            hi = arr[i].b;
            beg[i] = ++num;
        }
        else{
            beg[i] = num;
            hi = arr[i].b;
        }
    }
    /*
    cout << "\n";
    for(int i = 0;i < n;i++){
        cout << "beg: " << beg[i] << " ";
    }
    */
    for(int i = 0;i < q;i++){
        int s, e;
        cin >> s >> e;
        if(beg[s-1] == beg[e-1]) cout << 1;
        else cout << 0;
        cout << "\n";
    }
}

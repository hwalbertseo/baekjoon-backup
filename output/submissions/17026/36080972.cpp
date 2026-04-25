#include <iostream>
#include <algorithm>
#include <stack>
#define ll long long

using namespace std;

struct coo{
    ll f;
    ll b;
};

coo arr[100005];
int cnt = 0;

bool comp(coo a, coo b){
    if(a.f == b.f) return a.b < b.b;
    return a.f > b.f;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n = 0;
    cin >> n;
    for(int i = 0;i < n;i++){
        ll p, q;
        cin >> p >> q;
        coo temp;
        temp.f = p-q;
        temp.b = p+q;
        arr[i] = temp;
    }
    sort(arr, arr+n, comp);
    /*
    for(int i = 0;i < n;i++){
        cout << arr[i].f << " " << arr[i].b << "\n";
    }
    */
    ll hi = arr[0].b-1;
    for(int i = 0;i < n;i++){
        if(arr[i].b > hi){
            cnt++;
        }
    }
    cout << cnt;
}

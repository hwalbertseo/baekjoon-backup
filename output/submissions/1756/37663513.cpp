#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

ll arr[300005];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> arr[i];
    }
    int idx = n+1;
    int rec;
    for(int i = 1;i <= m;i++){
        ll p;
        cin >> p;
        for(int j = 1;j < idx;j++){
            if(arr[j] < p){
                idx = j;
                rec = j-1;
            }
        }
    }
    cout << rec;
}

#include <iostream>
#define ll long long

using namespace std;

ll arr[300005];
ll ans[300005];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> arr[i];
    }
    int b = n;
    int a = 1;
    for(int i = 1;i <= m;i++){
        cin >> ans[i];
    }
    int rec = 0;
    while(b >= 1 && a <= m){
        if(ans[a] < arr[b]){
            rec = b;
            a++;
        }
        b--;
    }
    cout << rec;
}

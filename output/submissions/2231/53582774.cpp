#include <iostream>

using namespace std;

int tens[8];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    //cout <'< 1e3;
    int temp = 1;
    for(int i = 0;i < 8;i++){
        tens[i] = temp;
        temp *= 10;
    }
    int n, ans;
    cin >> n;
    ans = 1e9;
    for(int i = n;i >= 0 ;i--){
        int sum = i;
        int now = i;
        for(int j = 7;j >= 0;j--){
            int cur = now/tens[j];
            now %= tens[j];
            sum += cur;
            //cout << sum << " " << cur << " " << i << endl;
        }
        if(sum == n && i < ans){
            ans = i;
        }
    }
    if(ans == 1e9){
        ans = 0;
    }
    cout << ans;
}

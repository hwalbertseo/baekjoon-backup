#include <iostream>
#include <map>

using namespace std;

int arr[200005];
int cnt[100005];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> arr[i];
    }
    int hi = 0;
    int lo = 1;
    int maxlen = -1;
    while(true){
        if(hi >= n){
            break;
        }
        //cout << hi << " " << lo << endl;
        hi++;
        cnt[arr[hi]]++;
        if(cnt[arr[hi]] > m){
            cnt[arr[lo]]--;
            while(cnt[arr[hi]] > m){
                lo++;
                cnt[arr[lo]]--;
            }
        }
        else{
            if(maxlen < hi-lo + 1){
                maxlen = hi-lo + 1;
            }
        }
    }
    cout << maxlen;
}

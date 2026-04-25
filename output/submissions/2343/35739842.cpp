#include <iostream>
#include <algorithm>

using namespace std;

long long sum[100005];
int n, m;

int srch(int p){
    //cout << "ent";
    int cnt = 0;
    int sind = n;
    for(int i = n;i >= 1;i--){
        int tot = sum[sind] - sum[i];
        //cout << "sind: " << sind << " " << i << " " << tot << " " << p <<  "\n";
        if(tot == p || i == 1){
            sind = i;
            cnt++;
            continue;
        }
        else if(tot > p){
            if(sind - i == 1){
                return 0;
            }
            sind = ++i;
            cnt++;
            continue;
        }
    }
    return cnt;
}

int main()
{
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    int total;
    for(int i = 1;i <= n;i++){
        cin >> sum[i];
    }
    sort(sum+1, sum+n+1);
    for(int i = 1;i <= n;i++){
        sum[i] += sum[i-1];
    }
    total = sum[n];
    int lo = sum[n] - sum[n-1];
    int hi = total+1;
    while(lo <= hi){
        if(lo == hi){
            cout << hi;
            break;
        }
        int mid = (lo + hi)/2;
        int cur = srch(mid);
        //cout << lo << " " << hi << " " << mid << " " << cur << "\n";
        if(cur == m){
            if(srch(mid-1) != m){
                cout << mid;
                break;
            }
            else{
                hi = mid;
                continue;
            }
        }
        else if(cur > m){
            lo = mid+1;
            continue;
        }
        else{
            hi = mid;
            continue;
        }
    }
}

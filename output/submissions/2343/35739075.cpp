#include <iostream>
#include <algorithm>

using namespace std;

int sum[100005];
int n, m;

int srch(int p){
    int cnt = 0;
    int sind = n;
    for(int i = n;i >= 0;i--){
        int tot = sum[sind] - sum[i];
        //cout << "sind: " << sind << " " << i << " " << tot << " " << p <<  "\n";
        if(tot == p || i == 0){
            sind = i;
            cnt++;
            continue;
        }
        else if(tot > p){
            sind = ++i;
            cnt++;
            continue;
        }
    }
    return cnt;
}

int main()
{
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
    int lo = 1;
    int hi = total+1;
    while(lo < hi){
        int mid = (lo + hi)/2;
        int cur = srch(mid);
        //cout << lo << " " << hi << " " << mid << " " << cur << "\n";
        if(cur == m){
            if(srch(mid-1) > m){
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
            if(lo == hi){
                cout << lo;
                break;
            }
            continue;
        }
        else{
            hi = mid;
            continue;
        }
    }
}

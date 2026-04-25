#include <iostream>
#include <algorithm>

using namespace std;

int arr[55];
int n, m, l;

int dist(int p){
    if(p == 0) return 0;
    int cnt = 0;
    int cur = 0;
    //cout << p << "\n";
    for(int i = 0;i <= n;i++){
        //cout << cnt << "\n";
        if(cur + p < arr[i]){
            cnt++;
            cur = cur+p;
            i--;
        }
        else{
            cur = arr[i];
        }
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> l;
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    arr[n] = l;
    sort(arr, arr+n+1);
    int lo, hi;
    lo = 1;
    hi = l;
    while(lo < hi){
        int mid = (hi + lo)/2;
        int num = dist(mid);
        //cout << lo << " " << hi << " " << num << "\n";
        if(num == m){
            int temp = dist(mid-1);
            //cout << mid-1 << " " << temp << "\n";
            if(temp > m){
                //cout << "h";
                cout << mid;
                break;
            }
            else {
                //cout << "j";
                hi = mid;
            }
        }
        else if(num > m){
            lo = mid+1;
        }
        else if(num < m){
            hi = mid;
        }
        if(lo >= hi){
            cout << hi;
            break;
        }
    }
}

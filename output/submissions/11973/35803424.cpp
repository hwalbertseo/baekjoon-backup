#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[50005];

int func(int p){
    if(p==0) return 2147483647;
    int cnt = 1;
    int cur = 0;
    for(int i = 0;i < n;i++){
        if(cur >= n) break;
        int temp = arr[i] + 2*p;
        //cout << "\n" << temp << " " << arr[i] << " " << 2*p << "\n";
        if(arr[cur] <= temp){
            //cout << i << ", " << temp << ", " << arr[cur] << ", " << cur << "  /  ";
            cur++;
            i--;
        }
        else{
            i = cur-1;
            cnt++;
            //cout << "\np: " << p << " " << arr[cur] << " " << cnt << "\n";
        }
    }
    //cout << arr[cur] << " " << cnt << "\n";
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);
    int hi = arr[n-1]/2 + 5;
    int lo = 1;
    //func(4);
    while(lo < hi){
        int mid = (hi + lo)/2;
        int num = func(mid);
        //cout << num << " " << mid << "\n";
        if(num == m){
            int temp = func(mid-1);
            if(temp > m){
                cout << mid;
                break;
            }
            else{
                hi = mid;
            }
        }
        else if(num < m){
            hi = mid;
        }
        else {
            lo = mid + 1;
        }
        if(lo >= hi){
            cout << hi;
        }
    }
}

#include <iostream>

using namespace std;

int arr[1000001];
int maxlen;
int len, n;

void bin(long long high, long long low){
    if(high <= low) {
        cout << high;
        return;
    }
    long long mid = (high + low)/2;
    long long mid2 = mid+1;
    //cout << mid << "\n";
    long long cnt1 = 0;
    long long cnt2 = 0;
    for(int i = 0;i < len;i++){
        cnt1 += (arr[i]/mid);
        cnt2 += (arr[i]/mid2);
    }
    if(cnt1 == n){
        if(cnt2 < n){
            cout << mid;
            return;
        }
        else{
            bin(high, mid+1);
            return;
        }
    }
    else if(cnt1 < n){
        bin(mid-1, low);
        return;
    }
    else if(cnt1 > n){
        if(cnt2 < n){
            cout << mid;
            return;
        }
        bin(high, mid+1);
        return;
    }
}

int main()
{
    cin >> n >> len;
    maxlen = -1;
    for(int i = 0;i < len;i++){
        cin >> arr[i];
        if(maxlen < arr[i]) maxlen = arr[i];
    }
    bin(maxlen, 1);
}

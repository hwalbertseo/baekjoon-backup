#include <iostream>

using namespace std;

int prime[4000005];
int pm[4000005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    for(int i = 2;i < n+1;i++){
        if(prime[i] > 0){
            continue;
        }
        else{
            for(int j = 2;i*j < n+1;j++){
                prime[i*j] = 1;
            }
        }
    }
    int idx = 1;
    for(int i = 2;i < n+1;i++){
        if(prime[i] == 0){
            pm[idx++] = i;
        }
    }
    for(int i = 1;i < idx;i++){
        pm[i] += pm[i-1];
    }
    int lo = 0;
    int hi = 1;
    int cnt = 0;
    while(lo < hi && hi < idx){
        int target = pm[hi] - pm[lo];
        if(target == n){
            cnt++;
            hi++;
        }
        else if(target < n){
            hi++;
        }
        else{
            lo++;
        }
    }
    cout << cnt;
}
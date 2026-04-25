#include <iostream>
#include <algorithm>
#include <set>
#define ll long long

using namespace std;

ll arr[5005];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n;
    cin >> n;
    for(ll i = 0;i < n;i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);
    ll nxt = 0;
    ll mi = 9e17;
    ll m[3];
    for(ll i = 0;i < n;i++){
        for(ll j = i+1;j < n;j++){
            ll sum = arr[i]+arr[j];
            int ind1 = lower_bound(&arr[0], &arr[n], -sum) - &arr[0];
            int ind2 = ind1-1;
            ll temp = 9e17;
            ll ms[3];
            while(ind1 == i || ind1 == j) ind1++;
            if(ind1 < n){
                temp = abs(sum + arr[ind1]);
                ms[0] = arr[i];
                ms[1] = arr[j];
                ms[2] = arr[ind1];
            }
            while(ind2 == j || ind2 == i) ind2--;
            if(ind2 >= 0){
                ll ts = abs(sum+arr[ind2]);
                if(temp > ts){
                    temp = ts;
                    ms[0] = arr[i];
                    ms[1] = arr[j];
                    ms[2] = arr[ind2];
                }
            }
            if(temp < mi){
                mi = temp;
                m[0] = ms[0];
                m[1] = ms[1];
                m[2] = ms[2];
            }
            //cout << ind << "\n";
        }
    }
    sort(m, m+3);
    cout << m[0] << " " << m[1] << " " << m[2];
}

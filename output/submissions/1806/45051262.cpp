#include <iostream>
#define ll long long

using namespace std;

ll psum[100005];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll p, q;
    cin >> p >> q;
    for(ll i = 1;i <= p;i++){
        cin >> psum[i];
    }
    /*
    for(ll i = 1;i <= p;i++){
        psum[i] = psum[i-1] + psum[i];
    }
    */
    ll sum = psum[1];
    ll left = 0, right = 1;
    ll minlen = 2e9;
    while(right <= p){
        sum -= psum[left];
        left++;
        while(sum < q){
            right++;
            if(right > p){
                if(minlen == 2e9){
                    cout << 0;
                }
                else cout << minlen;
                return 0;
            }
            sum += psum[right];
        }
        //cout << left << " " << right << " " << sum << endl;
        if(minlen > right-left+1){
            minlen = right-left+1;
        }
    }
}

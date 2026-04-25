#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

ll k, n, a[4];
vector<ll> s[4];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k;
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    for(ll i = 0;i < n;i++){
        char p;
        ll q;
        cin >> p >> q;
        s[p-'A'].push_back(q);
    }
    for(ll i = 0;i < 4;i++){
        sort(s[i].begin(), s[i].end());
    }
    //cout << "hjl";
    for(int i = 0;i < k;i++){
        ll mxar = -1;
        char mxch;
        for(ll j = 0;j < 4;j++){
            ll ar = 1;
            if(s[j].empty()) {
                continue;
            }
            //cout << s[j][0];
            ar = (s[j][s[j].size()-1]);
            if(mxar == -1 || ar*a[mxch-'A'] > mxar*a[j]){
                mxar = ar;
                mxch = j+'A';
            }
            //cout << ar << endl;
        }
        //cout << "b";
        cout << mxch << " " << mxar << "\n";
        s[mxch-'A'].pop_back();
/*
        for(int i = 0;i < 4;i++){
            cout << s[i][0] << endl;
        }
*/

        //cout << s[mxch-'A'].empty() << "\n";
        a[mxch-'A'] += mxar;
    }
}
/*
4 4
1 1 1 1
A 1
A 1
A 1
A 1
*/

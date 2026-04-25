#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

ll k, n, a[4];
vector<int> s[4];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k;
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    for(int i = 0;i < n;i++){
        char p;
        int q;
        cin >> p >> q;
        s[p-'A'].push_back(q);
    }
    for(int i = 0;i < 4;i++){
        sort(s[i].begin(), s[i].end(), greater<int>());
    }
    for(int i = 0;i < k;i++){
        int mxar = -1;
        char mxch;
        int mxin;
        for(int j = 0;j < 4;j++){
            int ar = 1;
            for(int r = 0;r < 4;r++){
                if(j == r && !s[r].empty()){
                    ar *= a[r]+s[r][0];
                }
                else{
                    ar *= a[r];
                }
            }
            if(ar > mxar){
                mxar = ar;
                mxch = j+'A';
                mxin = s[j][0];
            }
        }
        s[mxch-'A'].erase(s[mxch-'A'].begin());
        cout << mxch << " " << mxin << "\n";
        a[mxch-'A'] += mxin;
    }
}

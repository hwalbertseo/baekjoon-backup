#include <iostream>
#include <vector>
#include <set>
#define ll long long

using namespace std;

ll k, n, a[4];
multiset<int, greater<int>> s[4];

int main()
{
    cin >> n >> k;
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    for(int i = 0;i < n;i++){
        char p;
        int q;
        cin >> p >> q;
        s[p-'A'].insert(q);
    }
    for(int i = 0;i < k;i++){
        int mxar = -1;
        char mxch;
        int mxin;
        for(int j = 0;j < 4;j++){
            int ar = 1;
            for(int r = 0;r < 4;r++){
                if(j == r && !s[r].empty()){
                    ar *= a[r]+*(s[r].begin());
                }
                else{
                    ar *= a[r];
                }
            }
            if(ar > mxar){
                mxar = ar;
                mxch = j+'A';
                mxin = *(s[j].begin());
            }
        }
        s[mxch-'A'].erase(s[mxch-'A'].begin());
        cout << mxch << " " << mxin << "\n";
    }
}

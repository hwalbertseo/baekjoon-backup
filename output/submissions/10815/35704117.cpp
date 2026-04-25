#include <iostream>
#include <algorithm>

using namespace std;

int has[500005];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> has[i];
    }
    sort(has, has+n);
    int m;
    cin >> m;
    for(int j = 0;j < m;j++){
        int temp;
        cin >> temp;
        int lo = 0;
        int hi = n;
        bool yes = false;
        while(lo < hi){
            //cout << "iter / ";
            //cout << lo << " " << hi << " ";
            int mid = (lo + hi)/2;
            //cout << "\n  " << mid << " " << has[mid] << " " << temp << "\n";
            if(has[mid] == temp){
                yes = true;
                break;
            }
            else if(has[mid] < temp){
                lo = mid+1;
                continue;
            }
            else if(has[mid] > temp){
                hi = mid;
                continue;
            }
        }
        if(yes) cout << 1 << " ";
        else cout << 0 << " ";
    }

}

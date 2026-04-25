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
        int topind = 0;
        int botind = 0;
        int temp;
        cin >> temp;
        int lo = 0;
        int hi = n;
        while(lo < hi){
            //cout << "iter / ";
            //cout << lo << " " << hi << " ";
            int mid = (lo + hi)/2;
            //cout << "\n  " << mid << " " << has[mid] << " " << temp << "\n";
            if(has[mid] == temp){
                if(has[mid+1] > temp || mid == n-1){
                    topind = mid+1;
                    break;
                }
                else{
                    lo = mid+1;
                }

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
        lo = 0;
        hi = n;
        while(lo < hi){
            //cout << "iter / ";
            //cout << lo << " " << hi << " ";
            int mid = (lo + hi)/2;
            //cout << "\n  " << mid << " " << has[mid] << " " << temp << "\n";
            if(has[mid] == temp){
                if(has[mid-1] < temp || mid == 0){
                    botind = mid;
                    break;
                }
                else{
                    hi = mid;
                }

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
        cout << topind - botind << " ";
    }

}

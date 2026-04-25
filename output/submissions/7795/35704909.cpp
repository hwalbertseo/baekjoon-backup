#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int ts;
    cin >> ts;
    for(int its = 0;its < ts;its++){
        int a[20005];
        int b[20005];

        int alen, blen;
        cin >> alen >> blen;
        for(int i = 0;i < alen;i++){
            cin >> a[i];
        }
        for(int i = 0;i < blen;i++){
            cin >> b[i];
        }
        sort(b, b+blen);

        int cnt = 0;
        for(int i = 0;i < alen;i++){
            int lo = 0;
            int hi = alen;
            while(lo < hi){
                int mid = (lo + hi)/2;
                int mid2 = mid-1;

                if(b[mid] < a[i]){
                    lo = mid+1;
                    if(lo >= blen){
                        cnt += blen;
                        //cout << blen << " added1\n";
                        break;
                    }
                }
                else if(b[mid] >= a[i]){
                    if(b[mid2] < a[i]){
                        cnt += mid;
                        //cout << mid << " added2\n";
                        break;
                    }
                    else{
                        hi = mid;
                    }
                }
            }
        }
        cout << cnt << "\n";
    }
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int l, k, c;
int arr[10005];
int mincut = -1;
int maxlen = -1;

int part(int p){
    vector<int> cuts;
    if(p <= 0){
        return 0;
    }
    int cnt = 0;
    int prevcut = 0;
    for(int i = 0;i < k;i++){
        if(l - prevcut >= p){
            for(int j = k-1;j >= 0;j--){
                //cout << "ent";
                if(arr[j] <= prevcut + p){
                    cnt++;
                    //cout << "a: " << arr[j] << "\n";
                    prevcut = arr[j];
                    cuts.push_back(prevcut);
                    //cout << prevcut << "\n";
                    break;
                }
            }
            //cout << prevcut << " ";
        }
    }
    //cout << cuts[0];
    if(cuts.size()>0) mincut = cuts[0];
    //cout << "\n";
    //cout << p << " " << cnt << "\n";
    return cnt;
}

int main()
{
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> l >> k >> c;
    for(int i = 0;i < k;i++){
        cin >> arr[i];
    }
    sort(arr, arr+k);
    int lo = 1;
    int hi = l;
    //cout << part(6);

    while(lo < hi){
        int mid = (lo + hi)/2;
        int num = part(mid);
        if(num <= c){
            int temp = part(mid-1);
            if(temp > c || (mid-1 != l && temp == 0)){
                //part(mid);
                cout << mid << " " << mincut;
                break;
            }
            else{
                hi = mid;
            }
        }
        else if(num > c){
            lo = mid+1;
        }
        if(lo >= hi){
            cout << hi << " " << mincut;
            break;
        }
    }

}

/*
13 3 2
2 7 10
*/

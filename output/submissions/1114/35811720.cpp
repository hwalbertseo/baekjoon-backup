#include <iostream>
#include <algorithm>

using namespace std;

int l, k, c;
int arr[10005];
int mincut = -1;
int maxlen = -1;

int part(int p){
    if(p <= 0){
        return 0;
    }
    int cnt = 0;
    int prevcut = k-1;
    int lastcut = l;
    int prfx = 0;
    for(int i = l-1;i >= 0;i--){
        prfx++;
        cout << "arr: " << arr[prevcut]  << " i: " << i << " prfx:" << prfx << " cnt:" << cnt << endl;

        if(prfx > p){
            cout << "ent\n";
            if(lastcut-arr[prevcut] > prfx){
                //cout << "i:" << i << " arr:" << arr[prevcut] << " prfx:" << prfx << "\n";
                return 2147483647;
            }
            else{
                prfx = arr[prevcut]-i;
                prevcut--;
                cnt++;
                lastcut = arr[prevcut];
            }
        }
        if(lastcut-arr[prevcut-1] <= prfx){
            prevcut--;
        }
    }

    //cout << cuts[0];
    /*
    cout << "p: " << p << "\n";
    for(int i = 0;i < cuts.size();i++){
        cout << cuts[i] << " ";

    }
    cout << "\n";
    */
    mincut = lastcut;
    //cout << "\n";
    cout << "p: " << p << " " << cnt << "\n";
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
        cout << "mid: " << mid << " num: " << num << endl;
        if(num <= c){
            int temp = part(mid-1);
            cout << "mid-1: " << mid-1 << " temp: " << temp << endl;
            if(temp > c){
                part(mid);
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

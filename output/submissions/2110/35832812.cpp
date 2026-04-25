#include <iostream>
#include <algorithm>
//#include <vector>
#define MAXN 214748647

using namespace std;

int n, c;
int arr[200005];
//vector<int> cut;
int minlen = MAXN;

int func(int p){
    int cnt = 1;
    int last = 0;
    //cut.push_back(arr[0]);
    for(int i = 1;i < n;i++){
        if(arr[i] - arr[last] >= p){
            cnt++;
            if(minlen > arr[i]-arr[last]){
                minlen = arr[i]-arr[last];
            }
            last = i;
        }
    }
    /*
    for(int i = 0;i < cut.size();i++){
        cout << cut[i] << " ";
    }
    cout << endl;
    */
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false); cout.tie(0); cin.tie(0);
    cin >> n >> c;
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);
    int hi = arr[n-1]+1;
    int lo = 1;
    /*
    for(int i = 1;i < arr[n-1];i++){
        cout << i << ": " <<  (func(i)) << endl;
        //cut.clear();
    }
    */
    while(lo < hi){
        int mid = (hi + lo)/2;
        int num = func(mid);
        if(num == c){
            int temp = func(mid+1);
            if(temp == c){
                lo = mid+1;
            }
            else if(temp < c){
                cout << mid;
                break;
            }
        }
        else if(num > c){
            lo = mid + 1;
        }
        else if(num < c){
            hi = mid;
        }
        if(lo >= hi){
            cout << hi;
            break;
        }
    }

}

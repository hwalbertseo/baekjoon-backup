#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

struct ball{
    int index;
    int c;
    int s;
};

ball arr[200002];
int cnt[200002];
int edible[200002];
int stacksize[200002];

bool comp(ball a, ball b){
    return a.s < b.s;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> arr[i].c >> arr[i].s;
        arr[i].index = i;
    }
    sort(arr, arr+n, comp);
    edible[arr[0].index] = 0;
    cnt[arr[0].c] += arr[0].s;
    stacksize[0] = arr[0].s;
    for(int i = 1;i < n;i++){
        int hi = i-1;
        int lo = 0;
        while(hi > lo){
            int mid = (hi + lo)/2 + 1;
            if(arr[mid].s < arr[i].s){
                lo = mid;
            }
            else if(arr[mid].s == arr[i].s){
                hi = mid-1;
            }
        }
        edible[arr[i].index] += stacksize[hi] - cnt[arr[i].c];
        cnt[arr[i].c]+=arr[i].s;
        stacksize[i] += stacksize[i-1] + arr[i].s;
    }
    for(int i = 0;i < n;i++){
        cout << edible[i] << "\n";
    }
}

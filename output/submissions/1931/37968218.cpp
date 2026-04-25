#include <iostream>
#include <algorithm>

using namespace std;

pair<int, int> arr[100005];

bool comp(pair<int, int> a, pair<int,int> b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        int p, q;
        cin >> p >> q;
        arr[i] = {p, q};
    }
    sort(arr, arr+n, comp);
    int cnt = 0;
    int lastend = 0;
    for(int i = 0;i < n;i++){
        if(arr[i].first < lastend){
            continue;
        }
        else{
            lastend = arr[i].second;
            cnt++;
        }
    }
    cout << cnt;
}

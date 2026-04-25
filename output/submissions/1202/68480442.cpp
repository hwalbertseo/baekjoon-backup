#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

priority_queue<int, vector<int>> pq;
pair<int, int> arr[500000];

bool comp1(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first){
        return a.second < b.second;
    }
    return a.first < b.first;
}

bool comp2(pair<int, int> a, pair<int, int> b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k;
    cin >> n >> k;
    for(int i = 0;i < n;i++){
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr, arr+n, comp1);
    int val = 0;
    for(int j = 0;j < k;j++){
        int bag;
        cin >> bag;
        pq.push(bag);
    }
    /*
    for(int i = 0;i < n;i++){
        cout << arr[i].first << " " << arr[i].second << "\n";
    }
    //cout << pq.top();
    */
    pair<int, int> p;
    p.first = pq.top();
    p.second = 1e9;
    auto temp = lower_bound(arr, arr+n, p, comp1) - arr;
    sort(arr, arr+temp, comp2);
    /*
    cout << "\n";
    for(int i = 0;i < n;i++){
        cout << arr[i].first << " " << arr[i].second << "\n";
    }
    */
    for(int i = 0;i < k;i++){
        val += arr[temp-i-1].second;
    }
    cout << val;
}
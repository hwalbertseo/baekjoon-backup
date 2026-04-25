#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

priority_queue<int, vector<int>> pq;
pair<int, int> arr[500000];
priority_queue<int, vector<int>> pqp;

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
        int rk;
        cin >> rk;
        pqp.push(rk);
    }
    //cout << "sorte";
    
    int fst = 0;
    for(int i = 0;i < k;i++){
        pair<int, int> p;
        p.first = pqp.top();
        pqp.pop();
        p.second = 2e9;
        int idx = lower_bound(arr, arr+n, p) - arr;
        //cout << idx;
        /*
        for(int j = 0;j < idx;j++){
            cout << arr[j].first << " " << arr[j].second << "\n";
        }
        */
        for(;fst < idx;fst++){
            pq.push(arr[fst].second);
        }
        if(!pq.empty()){
            val += pq.top();
            pq.pop();
        }
    }
    cout << val;
    
}
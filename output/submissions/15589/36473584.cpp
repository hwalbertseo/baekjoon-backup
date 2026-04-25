#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct cow{
    int start;
    int index;
    int ent;
};

bool comp(cow a, cow b){
    return a.start < b.start;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<cow> v;
    for(int i = 0;i < n;i++){
        int p, q;
        cin >> p >> q;
        v.push_back({p, i, 1});
        v.push_back({q, i, -1});
    }
    sort(v.begin(), v.end(), comp);
    set<int> cur;
    int total = 0;
    int alone[100005] = {0,};
    for(int i = 0;i < n*2;i++){
        if(cur.size() == 1){
            alone[*cur.begin()] += v[i].start - v[i-1].start;
            //cout << i << " " << v[i].start << endl;
        }
        if(cur.size() > 0){
            total += v[i].start - v[i-1].start;
        }
        if(v[i].ent == 1){
            cur.insert(v[i].index);
            //cout << v[i].index << " ";
        }
        else{
            //cout << v[i].index << " ";
            cur.erase(v[i].index);
        }
    }
    int m = 2e9;
    for(int i = 0;i < n;i++){
        //cout << alone[i] << "\n";
        if(alone[i] < m){
            m = alone[i];
            //cout << i << " " << m << "\n";
        }
    }
    cout << total - m;
}

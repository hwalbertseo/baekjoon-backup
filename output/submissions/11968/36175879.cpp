#include <iostream>
#include <set>
#include <vector>

using namespace std;
int arr[100001];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    set<int> bes;
    vector<int> v;
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        int temp;
        cin >> temp;
        arr[temp] = 1;
        v.push_back(temp);
    }
    for(int i = 1;i <= 2*n;i++){
        if(arr[i] == 0){
            bes.insert(i);
        }
    }
    int cnt = 0;
    for(int i = 0;i < n;i++){
        auto it = bes.upper_bound(v[i]);
        if(it != bes.end()){
            cnt++;
        }
    }
    cout <<cnt;
}

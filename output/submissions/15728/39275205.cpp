#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int a[105];
int b[105];
int banned[20005];

struct num{
    int x, tot;
};

bool comp(num a, num b){
    return a.tot < b.tot;
}

vector<num> v;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int p, q;
    cin >> p >> q;
    for(int i = 0;i < p;i++){
        cin >> a[i];
    }
    for(int i = 0;i < p;i++){
        cin >> b[i];
    }
    sort(a, a+p);
    sort(b, b+p);
    //first, big
    int big = a[p-1];
    int small = a[0];
    for(int i = 0;i < p;i++){
        num a;
        a.x = b[p-i-1];
        a.tot = big * b[p-i-1];
        num c;
        c.x = b[i];
        c.tot = small * b[i];
        v.push_back(a);
        v.push_back(c);
    }
    sort(v.begin(), v.end(), comp);
    int bannable = q;
    for(int i = v.size()-1;i >= 0;i--){
        if(banned[v[i].x+10000] == 1){
            continue;
        }
        else if(bannable > 0){
            banned[v[i].x+10000] = 1;
            bannable--;
            continue;
        }
        else{
            cout << v[i].tot;
            return 0;
        }
    }
}

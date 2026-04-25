#include <iostream>
#include <map>
#include <set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int len = n;
    map<string, multiset<string>> m;
    for(int i = 0;i < n;i++){
        string temp1, temp2;
        cin >> temp1 >> temp2;
        temp1 = temp1.substr(0, 2);
        if(temp1 == temp2) continue;
        else{
            m[temp1];
            m[temp1].insert(temp2);
        }
    }
    int cnt = 0;
    for(auto i = m.begin();i != m.end();i++){
        string state, city;
        state = (*i).first;
        for(auto j = (*i).second.begin();j != (*i).second.end();j++){
            city = (*j);
            if(m.count(city) == 0){
                continue;
            }
            else{
                auto lb = m[city].lower_bound(state);
                for(;*fi == state;fi++){
                    cnt++;
                }
            }
        }
    }
    cout << cnt/2;
}

/*
8
MIAMI FL
DALLAS TX
FLINT MI
CLEMSON SC
BOSTON MA
ORLANDO FL
FLINT OR
FLINT FL
*/

#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int len = n;
    map<string, vector<string>> m;
    for(int i = 0;i < n;i++){
        string temp1, temp2;
        cin >> temp1 >> temp2;
        temp1 = temp1.substr(0, 2);
        if(temp1 == temp2) continue;
        else{
            m[temp1];
            m[temp1].push_back(temp2);
        }
    }
    int cnt = 0;
    for(auto i = m.begin();i != m.end();i++){
        string state, city;
        state = (*i).first;
        for(int j = 0;j < (*i).second.size();j++){
            city = (*i).second[j];
            if(m.count(city) == 0){
                continue;
            }
            else{
                string city2;
                for(int r = 0;r < m[city].size();r++){
                    city2 = m[city][r];
                    if(city2 == state){
                        cnt++;
                    }
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

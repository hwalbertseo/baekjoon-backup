#include <iostream>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    map<string, int> m;
    for(int i = 0;i < n;i++){
        string temp;
        cin >> temp;
        m[temp] = m[temp] + 1;
    }
    int maxsold = -1;
    string sold;
    for(auto it = m.begin();it != m.end();it++){
        if((*it).second > maxsold){
            maxsold = (*it).second;
            sold = (*it).first;
        }
    }
    cout << sold;
}

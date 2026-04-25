#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    set<string> s;
    for(int i = 0;i < n;i++){
        string temp;
        cin >> temp;
        s.insert(temp);
    }
    int cnt = 0;
    vector<string> in;
    for(int i = 0;i < m;i++){
        string temp;
        cin >> temp;
        if(s.count(temp) == 1) {
            cnt++;
            in.push_back(temp);
        }
    }
    cout << cnt << "\n";
    for(int i = 0;i < cnt;i++){
        cout << in[i] << "\n";
    }
}

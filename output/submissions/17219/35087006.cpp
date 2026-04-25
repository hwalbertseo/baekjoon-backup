#include <iostream>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    map<string, string> ma;
    for(int i = 0;i < n;i++){
        string name, pw;
        cin >> name >> pw;
        ma.insert(pair<string, string>(name, pw));
    }
    for(int i = 0;i < m;i++){
        string temp;
        cin >> temp;
        cout << ma[temp] << "\n";
    }
}

#include <iostream>
#include <string>

using namespace std;

string s, t;
int n, m;
int ten[3] = {1, 10, 100};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> s >> t;
    for(int i = 0;i < 3;i++){
        n += (s[i]-48)*ten[i];
        m += (t[i]-48)*ten[i];
    }
    cout << ((n > m) ? n : m);
}

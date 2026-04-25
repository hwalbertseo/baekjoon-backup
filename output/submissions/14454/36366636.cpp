#include <iostream>
#include <string>

using namespace std;

string cc(string s, long long n){
    if(s.size() >= n) return s;
    string a = s[s.size()-1] + s;
    //cout << "in";
    a.erase(a.size()-1, 1);
    //cout << a << "\n";
    return cc(s+a, n);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    string inp;
    long long a;
    cin >> inp >> a;
    string res = cc(inp, a);
    cout << res[a-1];
}

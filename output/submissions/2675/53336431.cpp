#include <iostream>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int tc;
    cin >> tc;
    for(int i = 0;i < tc;i++){
        int n;
        string s;
        cin >> n;
        cin >> s;
        //cout << s;
        for(int j = 0;j < s.length();j++){
            for(int r = 0;r < n;r++){
                cout << s[j];
            }
        }
        cout << "\n";
    }

}

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    string tc;
    for(;;){
        cin >> tc;
        if(tc[0] == '0'){
            break;
        }
        int len = tc.length();
        string ans = "blah";
        for(int i = 0;i < len/2;i++){
            if(tc[i] != tc[len-i-1]){
                ans = "no\n";
                break;
            }
        }
        if(ans == "blah") ans = "yes\n";
        cout << ans;
    }
}

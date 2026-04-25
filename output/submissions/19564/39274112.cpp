#include <iostream>

using namespace std;

int main()
{
    string n;
    cin >> n;
    int ans = 0;
    for(int i = 1;i < n.size();i++){
        if(n[i] <= n[i-1]){
            ans++;
        }
    }
    cout << ans+1;
}

#include <iostream>
#include <string>

using namespace std;

int arr[10];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int p, q, r;
    cin >> p >> q >> r;
    int n = p*q*r;
    string s = to_string(n);
    for(int i = 0;i < s.length();i++){
        char c = s[i];
        int temp = c-48;
        arr[temp]++;
    }
    for(int i = 0;i < 10;i++){
        cout << arr[i] << "\n";
    }
}

#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;

int arr[1000000];
string s_i, s_n;

int manacher(string s){
    int r = 0, c = 0, max = 0;
    for(int i = 0;i < s.size();i++){
        if(i > r){
            arr[i] = 0;
        }
        else{
            arr[i] = min(arr[2 * c - i], r - i);
        }
        while(s[i - arr[i] - 1] == s[i + arr[i] + 1] && i + arr[i] + 1 < s.size() && i - arr[i] - 1 >= 0){
            arr[i]++;
        }
        if(r < i + arr[i] - 1){
            r = i + arr[i];
            c = i;
        }
        if(arr[i]> max){
            max = arr[i];
        }

    }
    return max;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> s_i;
    string s_n = "";
    for(int i = 0;i < s_i.size();i++){
        s_n = s_n + "#" + s_i[i];
    }
    s_n = s_n + "#";
    cout << manacher(s_n);
}
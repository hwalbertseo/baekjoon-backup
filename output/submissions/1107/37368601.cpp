#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int arr[11];
int tens[10];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    tens[0] = 1;
    for(int i = 1;i < 10;i++){
        tens[i] = tens[i-1]*10;
    }
    //int cnt = 0;
    int intn = 0;
    int m;
    cin >> intn;
    cin >> m;
    for(int i = 0;i < m;i++){
        int p;
        cin >> p;
        arr[p] = 1;
    }
    int ans1 = 2e9;
    int ans2 = 2e9;
    int cnt1 = 0;
    int cnt2 = 0;
    cnt2 = abs(100 - intn);
    for(int i = 0;intn+i <= 999999;i++){
        int num = intn + i;
        string temp = to_string(num);
        bool pos = true;
        for(int j = 0;j < temp.size();j++){
            if(arr[temp[j]-48] == 1){
                pos = false;
            }
        }
        if(pos){
            ans1 = num;
            break;
        }
    }
    for(int i = -1;intn+i >= 0;i--){
        int num = intn + i;
        string temp = to_string(num);
        //cout << temp << endl;
        bool pos = true;
        for(int j = 0;j < temp.size();j++){
            if(arr[temp[j]-48] == 1){
                pos = false;
            }
        }
        if(pos){
            ans2 = num;
            break;
        }
    }
    cout << ans1 << " " << ans2 << "\n";
    int n1 = to_string(ans1).size();
    int n2 = to_string(ans2).size();
    cnt1 = min(n1 + abs(ans1-intn), n2 + abs(intn-ans2));
    //cout << intn << " " << ans << "\n";
    cout << min(cnt1, cnt2);
    //cout << intn;
    //cout << ans;
}
/*
99
10
0 1 2 3 4 5 6 7 8 9
*/

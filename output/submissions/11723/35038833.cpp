#include <iostream>
#include <set>
using namespace std;
set<int> all, none;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    set<int> s;
    for(int i = 1; i < 21; i++) all.insert(i);
    int num;
    cin >> num;
    for(int i = 0;i < num;i++){
        string temp;
        int n;
        cin >> temp;
        if(temp[0] == 'a' && temp[1] == 'd'){
            cin >> n;
            s.insert(n);
        }
        else if(temp[0] == 'r'){
            cin >> n;
            s.erase(n);
        }
        else if(temp[0] == 'c'){
            cin >> n;
            cout << s.count(n) << "\n";
        }
        else if(temp[0] == 't'){
            cin >> n;
            if(s.count(n) == 1){
                s.erase(n);
            }
            else{
                s.insert(n);
            }
        }
        else if(temp[0] == 'a'){
            s = all;
        }
        else {
            s.clear();
        }
    }
}
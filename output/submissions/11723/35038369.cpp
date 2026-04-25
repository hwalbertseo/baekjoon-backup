#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    set<int> s;
    set<int> all;
    for(int j = 1;j < 21;j++){
        all.insert(j);
    }
    long long num;
    cin >> num;
    for(long long i = 0;i < num;i++){
        string temp;
        int n;
        cin >> temp;
        if(temp[0] == 'a' && temp[1] == 'l'){
            s.clear();
            s = all;
        }
        else if(temp[0] == 'a'){
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
        else if(temp[0] == 'e'){
            s.clear();
        }
    }
}

#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    set<int> s;
    long long num;
    cin >> num;
    for(long long i = 0;i < num;i++){
        string temp;
        int n;
        cin >> temp;
        if(temp.compare("add") == 0){
            cin >> n;
            s.insert(n);
        }
        else if(temp.compare("remove") == 0){
            cin >> n;
            s.erase(n);
        }
        else if(temp.compare("check") == 0){
            cin >> n;
            cout << s.count(n) << "\n";
        }
        else if(temp.compare("toggle") == 0){
            cin >> n;
            if(s.count(n) == 1){
                s.erase(n);
            }
            else{
                s.insert(n);
            }
        }
        else if(temp.compare("all") == 0){
            s.clear();
            for(int j = 1;j < 21;j++){
                s.insert(j);
            }
        }
        else if(temp.compare("empty") == 0){
            s.clear();
        }
    }
}

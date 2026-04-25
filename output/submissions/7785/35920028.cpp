#include <iostream>
#include <set>

using namespace std;

int main()
{
    int n;
    cin >> n;
    set<string> s;
    for(int i = 0;i < n;i++){
        string name, here;
        cin >> name >> here;
        if(here == "enter"){
            s.insert(name);
        }
        else{
            s.erase(name);
        }
    }
    for(auto it = s.rbegin();(it) != (s.rend());it++){
        cout << *it << "\n";
    }
}

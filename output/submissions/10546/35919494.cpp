#include <iostream>
#include <set>

using namespace std;

int main()
{
    int n;
    cin >> n;
    set<string> s;
    for(int i = 0;i < n*2-1;i++){
        string temp;
        cin >> temp;
        if(s.count(temp) == 1){
            s.erase(temp);
        }
        else{
            s.insert(temp);
        }
    }
    auto it = s.begin();
    cout << *it;
}

#include <iostream>
#include <set>
#define ll long long

using namespace std;

set<ll> s;

int main()
{
    int ts;
    cin >> ts;
    for(int ii = 0;ii < ts;ii++){
        //cout << "ent";
        s.clear();
        int n;
        cin >> n;
        for(int i = 0;i < n;i++){
            char p;
            ll q;
            cin >> p >> q;
            if(p == 'I'){
                s.insert(q);
            }
            else{
                if(s.empty()){
                    continue;
                }
                if(q == 1){
                    auto ed = s.end();
                    ed--;
                    s.erase(ed);
                }
                else{
                    s.erase(s.begin());
                }
            }
        }
        if(s.empty()){
            cout << "EMPTY\n";
        }
        else{
            cout << *s.rbegin() << " " << *s.begin() << "\n";
        }
    }
}

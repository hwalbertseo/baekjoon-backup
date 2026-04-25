#include <iostream>
#include <set>

using namespace std;

set<int> s;
set<int> f;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;

    int temp;
    cin >> temp;
    cout << temp << "\n";
    s.insert(temp);

    int last = *s.begin();
    for(int i = 1;i < n;i++){
        int p;
        cin >> p;
        if(p > last){
            s.insert(p);
        }
        else{
            f.insert(p);
        }
        if(f.size() < i/2){
            f.insert(*s.begin());
            s.erase(s.begin());
        }
        else if(f.size() > i/2){
            auto tp = f.end();
            tp--;
            s.insert(*tp);
            f.erase(tp);
        }
        last = *s.begin();
        cout << last << "\n";
    }
}

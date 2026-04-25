#include <iostream>
#include <set>

using namespace std;

set<int> s;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    int cnt = 0;
    int temp;
    cin >> temp;
    cout << temp << "\n";
    s.insert(temp);
    for(int i = 1;i < n;i++){
        int p;
        cin >> p;
        s.insert(p);
        if(i%2 == 1){
            auto it = s.begin();
            for(int i = 0;i < cnt;i++){
                it++;
            }
            cout << *it << "\n";
        }
        else{
            cnt++;
            auto it = s.begin();
            for(int i = 0;i < cnt;i++){
                it++;
            }
            cout << *it << "\n";
        }
    }
}

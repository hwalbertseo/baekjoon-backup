#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    multiset<int> s;
    for(int i = 0;i < n;i++){
        int temp;
        cin >> temp;
        if(temp != 0) s.insert(temp);
        else{
            if(s.size() == 0) cout << 0 << "\n";
            else{
                cout << *(s.begin()) << "\n";
                s.erase(s.begin());
            }
        }
    }
}

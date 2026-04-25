#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    set<int> s;
    for(int i = 0;i < n;i++){
        int temp;
        cin >> temp;
        s.insert(temp);
    }
    while(s.size()!= 0){
        int p = *(s.begin());
        cout << p << "\n";
        s.erase(p);
    }
    cout << 0;
}

#include <iostream>
#include <set>

using namespace std;

int arr[1000005];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    set<int> s;
    for(int i = 0;i < n;i++){
        int temp;
        cin >> temp;
        arr[i] = temp;
        s.insert(temp);
    }
    for(int i = 0;i < n;i++){
        auto it = s.lower_bound(arr[i]);
        cout << distance(s.begin(), it) << " ";
    }
}

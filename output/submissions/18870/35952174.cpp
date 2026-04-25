#include <iostream>
#include <set>

using namespace std;

int arr[1000005];
int a[1000005];

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
    int ind = 0;
    for(auto it = s.begin();it != s.end();it++){
        a[ind++] = *it;
    }
    for(int i = 0;i < n;i++){
        int lb = lower_bound(&a[0], &a[s.size()], arr[i]) - &a[0];
        cout << lb << " ";
    }
}

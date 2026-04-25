#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int a[105];
int b[105];
vector<int> v;

int main()
{
    int p, q;
    cin >> p >> q;
    for(int i = 0;i < p;i++){
        cin >> a[i];
    }
    for(int i = 0;i < p;i++){
        cin >> b[i];
    }
    sort(a, a+p);
    sort(b, b+p);
    //first, big
    int big = a[p-1];
    int small = a[0];
    for(int i = 0;i < p;i++){
        v.push_back(big * b[p-i-1]);
        v.push_back(small * b[i]);
    }
    sort(v.begin(), v.end());
    cout << v[v.size()-1-q];
}

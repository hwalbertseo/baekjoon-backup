#include <iostream>
#include <algorithm>

using namespace std;

int a[105];
int b[105];

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
    cout << a[p-1] * b[p-1-q];
}

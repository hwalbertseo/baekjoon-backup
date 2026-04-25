#include <iostream>

using namespace std;

int main()
{
    int p, q;
    cin >> p >> q;
    int tot = p*q;
    for(int i = 0;i < 5;i++){
        int r;
        cin >> r;
        cout << r-tot << " ";
    }
}

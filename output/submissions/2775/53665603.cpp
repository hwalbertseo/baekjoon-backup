#include <iostream>
#define ll long long

using namespace std;

ll arr[100][100];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 0; i < 100; i++)
    {
        arr[0][i] = i;
    }
    for (int i = 1; i < 100; i++)
    {
        for (int j = 1; j < 100; j++)
        {
            arr[i][j] = arr[i][j - 1] + arr[i - 1][j];
        }
    }
    ll tc;
    cin >> tc;
    for (int i = 0; i < tc; i++)
    {
        ll k, n;
        cin >> k >> n;
        cout << arr[k][n] << "\n";
    }
}

#include <iostream>
#include <algorithm>

using namespace std;

int arr[500];
int maxscore[500];
int n;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> arr[i];
    }
    maxscore[1] = arr[1];
    maxscore[2] = arr[1]+arr[2];
    maxscore[3] = arr[3] + max(maxscore[1], arr[2]);
    for(int i = 4;i <= n;i++){
        maxscore[i] = max(arr[i] + arr[i-1] + maxscore[i-3],
                          arr[i] + maxscore[i-2]);
    }
    cout << maxscore[n];
}

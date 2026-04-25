#include <iostream>

using namespace std;

int arr[1000000001];

int main()
{
    int n, q;
    cin >> n >> q;
    for(int i = 0;i < n;i++){
        int temp;
        cin >> temp;
        arr[temp]++;
    }
    for(int i = 1;i <= 1000000000;i++){
        arr[i] = arr[i]+arr[i-1];
    }

    for(int i = 0;i < q;i++){
        int p, q;
        cin >> p >> q;
        cout << arr[q] - arr[p-1] << "\n";
    }
}

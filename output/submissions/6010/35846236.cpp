#include <iostream>

using namespace std;

int arr[50005];
int n, q;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    int last = 1;
    for(int i = 1;i <= n;i++){
        int temp;
        cin >> temp;
        for(int j = last;j < last+temp;j++){
            arr[j] += arr[j-1] + i;
        }
        last = last+temp;
    }

    for(int i = 0;i < q;i++){
        int temp;
        cin >>temp;
        cout << arr[temp+1] - arr[temp] << "\n";
    }

}

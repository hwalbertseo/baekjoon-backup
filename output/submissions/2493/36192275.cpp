#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int arr[500005];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    arr[0] = 2147483647;
    for(int i = 1;i <= n;i++){
        cin >> arr[i];
    }
    int a[500005];
    for(int i = n;i >= 0;i--){
        for(int j = i-1;j >= 0;j--){
            if(arr[j] > arr[i]){
                a[i-1] = j;
                break;
            }
        }
    }
    for(int i = 0;i < n;i++){
        cout << a[i] << " ";
    }
}

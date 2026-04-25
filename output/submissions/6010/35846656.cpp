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
        arr[i] = arr[i-1] + temp;
    }
    for(int i = 0;i < q;i++){
        int temp;
        cin >> temp;
        int lo = 1;
        int hi = n;
        while(lo < hi){
            int mid = (lo + hi)/2;
            if(arr[mid] <= temp){
                lo = mid+1;
            }
            else if(arr[mid] > temp){
                hi = mid;
            }
        }
        cout << lo << "\n";
    }
}

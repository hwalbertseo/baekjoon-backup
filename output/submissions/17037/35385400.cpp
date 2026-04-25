#include <iostream>

using namespace std;

int arr[1005][1005];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    int cnt = 0;
    for(int i = 0;i < n;i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int j = x1;j < x2;j++){
            for(int r = y1;r < y2;r++){
                arr[j][r]++;
                if(arr[j][r] == k){
                    cnt++;
                }
                else if(arr[j][r] > k){
                    cnt--;
                }
            }
        }
    }
    cout << cnt;
}

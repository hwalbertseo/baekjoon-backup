#include <iostream>
#include <algorithm>

using namespace std;

int arr[100];
int brr[100];
int sorted[100];
int ans[100];
int visit[100];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    for(int i = 0;i < n;i++){
        cin >> brr[i];
        sorted[i] = brr[i];
    }
    sort(arr, arr+n);
    sort(sorted, sorted+n, greater<int>());
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(brr[j] == sorted[i] && visit[j] == 0){
                ans[j] = arr[i];
                visit[j] = 1;
            }
        }
    }
    int cnt = 0;
    for(int i = 0;i < n;i++){
        cnt += ans[i]*brr[i];
    }
    cout << cnt;
}

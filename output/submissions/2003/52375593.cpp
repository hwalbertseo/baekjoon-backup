#include <iostream>

using namespace std;

int arr[100001];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    int sum = 0;
    int beg = 0;
    int fin = -1;
    int cnt = 0;
    for(;;){
        fin++;
        if(fin == n){
            break;
        }
        sum += arr[fin];
        while(sum > m){
            sum -= arr[beg];
            beg++;
        }
        if(sum < m){
            continue;
        }
        else if(sum == m){
            cnt++;
            //cout << beg << " " << fin << endl;
            continue;
        }
    }
    cout << cnt;
}

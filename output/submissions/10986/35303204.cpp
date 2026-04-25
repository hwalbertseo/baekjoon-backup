#include <iostream>

using namespace std;

long long arr[100005];

int main()
{
    int n, m;
    cin >> n >> m;
    int maxsum = 0;
    for(int i=1;i<=n;i++){
        int ps;
        cin >> ps;
        arr[i] = arr[i-1]+ps;
        for(int j = 0;j < i;j++){
            long long h = arr[i]-arr[j];
            if(h%m == 0){
                maxsum++;
            }
        }
    }
    cout << maxsum;
}

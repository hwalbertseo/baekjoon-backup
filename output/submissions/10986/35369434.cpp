#include <iostream>

using namespace std;

int arr[1000005];
long long remainder[1005];

long long C(long long x){
    if(x == 0) return 0;
    return (x*(x-1))/2;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    long long maxsum = 0;
    for(int i=1;i<=n;i++){
        int ps;
        cin >> ps;
        arr[i] = (arr[i-1]+ps)%m;
        remainder[arr[i]]++;
    }
    maxsum = remainder[0] + C(remainder[0]);
    for(int i = 1;i<m;i++){
        maxsum += C(remainder[i]);
    }
    cout << maxsum;
}

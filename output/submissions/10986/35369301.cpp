#include <iostream>

using namespace std;

long long arr[100005];
long long remainder[1005];

int C(int x){
    if(x == 0) return 0;
    return (x*(x-1))/2;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int maxsum = 0;
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

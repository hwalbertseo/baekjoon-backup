#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    int sum1[100005] = {0,};
    int sum2[100005] = {0,};
    int sum3[100005] = {0,};
    for(int i = 1;i<=n;i++){
        int temp;
        cin >> temp;
        if(temp == 1) {
            sum1[i] = sum1[i-1] + 1;
            sum2[i] = sum2[i-1];
            sum3[i] = sum3[i-1];
        }
        else if(temp == 2) {
            sum1[i] = sum1[i-1];
            sum2[i] = sum2[i-1] + 1;
            sum3[i] = sum3[i-1];
        }
        else if(temp == 3) {
            sum1[i] = sum1[i-1];
            sum2[i] = sum2[i-1];
            sum3[i] = sum3[i-1] + 1;
        }
    }
    for(int i = 0;i < m;i++){
        int s, e;
        cin >> s >> e;
        cout << sum1[e]-sum1[s-1] << " ";
        cout << sum2[e]-sum2[s-1] << " ";
        cout << sum3[e]-sum3[s-1] << "\n";
    }
}

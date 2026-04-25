#include <iostream>

using namespace std;

int arr[100005];
int sum[100005];
int minarr[100005];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int num;
    cin >> num;

    fill_n(minarr, -1, true);
    for(int i = 0;i < num;i++){
        cin >> arr[i];
    }
    minarr[0] = arr[num-1];
    for(int i = 1;i<=num;i++){
        sum[i] = sum[i-1] + arr[num-i];
        if(arr[num-i]<minarr[i-1]){
            minarr[i] = arr[num-i];
        }
        else{
            minarr[i] = minarr[i-1];
        }
    }
    double maxscore = 0;
    int ans = 0;
    for(int i= 1;i <= num;i++){\
        double temp = (double)(sum[i]-sum[1]-minarr[i]) / (double)i;
        if(maxscore < temp){
            ans = i;
            maxscore = temp;
        }
    }
    cout << num-ans;
}

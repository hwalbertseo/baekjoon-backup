#include <iostream>
#include <vector>

using namespace std;

int arr[100005];
int sum[100005];
int minarr[100005];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int num;
    cin >> num;
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
    double maxscore = -1;
    vector<int> v;
    for(int i= 2;i < num;i++){
        double temp = (double)(sum[i]-minarr[i]) / (double)(i-1);
        //cout << i << " " << minarr[i] << " " << sum[i]-sum[0]-minarr[i] << " " << temp << "\n";
        if(maxscore < temp){
            v.clear();
            v.push_back(num-i);
            maxscore = temp;
        }
        else if(maxscore == temp){
            v.push_back(num-i);
        }
    }
    for(int i = 0;i < v.size();i++){
        cout << v[i] << " ";
    }
}

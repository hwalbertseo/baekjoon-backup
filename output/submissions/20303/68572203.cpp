#include <iostream>
#include <vector>

using namespace std;

int arr[30005];
int candy[30005];
int dp[3005];
vector<pair<int, int>> v;

int srch(int x){
    if(arr[x] < 0){
        return x;
    }
    else{
        return arr[x] = srch(arr[x]);
    }
}

void join(int a, int b){
    int p = srch(a);
    int q = srch(b);
    //cout << a << " " << b <<"\n";
    //cout << p << " " << q <<"\n";

    if(p == q){
        return;
    }
    if(arr[p] < arr[q]){
        arr[p] += arr[q];
        arr[q] = p;
        candy[p] += candy[q];
    }
    else{
        arr[q] += arr[p];
        arr[p] = q;
        candy[q] += candy[p];
    }
    return;
}

int main(){
    for(int i = 0;i < 30005;i++){
        arr[i] = -1;
    }
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1;i <= n;i++){
        cin >> candy[i];
    }
    for(int i = 0;i < m;i++){
        int p, q;
        cin >> p >> q;
        join(p, q);
        /*
        for(int j = 1;j <= n;j++){
            cout << arr[j] << " ";
        }
        cout << "\n";
        */
    }
    for(int i = 1;i <= n;i++){
        if(arr[i] < 0){
            pair<int, int> temp;
            temp.first = i;
            temp.second = -arr[i];
            v.push_back(temp);
        }
    }
    /*
    for(int i = 1;i <= n;i++){
        cout << candy[srch(i)] << " ";
    }
    cout << "\n";
    for(int i = 1;i <= n;i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
    */
    for(int i = 0;i < v.size();i++){
        pair<int, int> temp = v[i];
        int idx = temp.first;
        int num = temp.second;
        //cout << idx << " " << num << "\n";
        for(int j = k-1;j > 0;j--){
            if(j < num){
                continue;
            }
            dp[j] = max(dp[j], dp[j-num] + candy[srch(idx)]);
        }
    }
    cout << dp[k-1];
}
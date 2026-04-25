#include <iostream>
#include <algorithm>

using namespace std;

int arr[1005];
int temp[1005];
int basket[1005];

void init(){
    for(int i = 0;i < 1000;i++){
        basket[i] = 0;
        temp[i] = 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);
    int maxnum = 0;
    for(int i = 0;i < arr[n-1];i++){
        init();
        int mnum = 0;
        for(int j = 0;j < m;j++){
            temp[j] = arr[n-j-1];
        }
        int cur = 0;
        int filldex = 0;
        while(filldex < m){
            if(cur > m){
                break;
            }
            if(temp[cur] < i){
                cur++;
                continue;
            }
            else{
                basket[filldex] += i;
                temp[cur] -= i;
            }
            filldex++;
        }
        sort(temp, temp+m);
        cur = m-1;
        for(;filldex < m;filldex++){
            basket[filldex] = temp[cur--];
        }
        for(int j = 0;j < m/2;j++){
            mnum += basket[m-j-1];
        }
        if(mnum > maxnum){
            maxnum = mnum;
        }
        /*
        for(int j = 0;j < m;j++){
            cout << basket[j] << " ";
        }
        cout << endl;
        */
    }
    cout << maxnum;
}

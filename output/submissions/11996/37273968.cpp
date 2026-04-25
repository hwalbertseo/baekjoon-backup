#include <iostream>
#include <vector>

using namespace std;

int n;
int arr[1005];
int copyarr[1005];

void init(){
    for(int i = 0;i < 1005;i++){
        arr[i] = copyarr[i];
    }
}

pair<int, int> findi(int last){
    int mov = 0;
    for(int i = last;;i--){
        if(i<0){
            i+=n;
        }
        if(arr[i] > 0){
            return {mov, i};
        }
        mov++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> copyarr[i];
    }
    vector<int> lastv;
    for(int i = 0;i <= n+3;i++){
        int idx = i%n;
        if(copyarr[idx] == 0 && copyarr[(idx+1) % n] != 0){
            lastv.push_back(idx);
        }

    }
    int maxans = 2e9;
    for(int k = 0;k < lastv.size();k++){
        init();
        int last = lastv[k];
        int flag = n-1;
        int ans = 0;
        while(flag >= 0){
            pair<int, int> pass = findi(last);
            ans += pass.first * pass.first;
            arr[pass.second]--;
            //cout << "l: " << last << "  s: " << pass.first << "\n";
            last--;
            if(last < 0){
                last += n;
            }

            flag--;
        }
        if(maxans > ans){
            maxans = ans;
        }
    }
    cout << maxans;

}

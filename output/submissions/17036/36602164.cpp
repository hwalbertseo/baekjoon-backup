#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> v;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for(int i = 0;i < n;i++){
        int p;
        cin >> p;
        v.push_back(p);
    }
    sort(v.begin(), v.end());
    int side1 = v[n-2] - v[0];
    int side2 = v[n-1] - v[1];
    int maxside = max(side1, side2);
    int mav = maxside - (n-2);


    //find min
    int d = n-1;
    int maxcnt = -1;
    for(int i = 0;i < n-1;i++){
        int cnt = 1;
        int j;
        for(j = i+1;j < n;j++){
            int dif = v[j] - v[i];
            if(dif > d){
                break;
            }
            else if(dif == d){
                cnt++;
                break;
            }
            else{
                cnt++;
                continue;
            }
        }
        if(cnt > maxcnt){
            maxcnt = cnt;
        }
    }
    int miv = n-maxcnt;
    if(v[n-2] - v[0] == n-2){
        if(v[n-1] != v[n-2] + 2 && v[n-1] != v[n-2]+1 ){
            miv++;
        }
    }
    else if(v[n-1] - v[1] == n-2){
        if(v[0] != v[1]-2 && v[0] != v[1]-1){
            miv++;
        }
    }
    cout << miv << "\n" << mav;
}

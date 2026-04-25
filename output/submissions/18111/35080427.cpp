#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, m, b;
    cin >> n >> m >> b;
    int len = n*m;
    vector<int> v;
    int mv, Mv, org;
    for(int i = 0;i < len;i++){
        int temp;
        cin >> temp;
        if(mv > temp) mv = temp;
        if(Mv < temp) Mv = temp;
        v.push_back(temp);
    }
    org = mv;
    for(int i = 0;i < len;i++){
        v[i] -= mv;
    }
    mv = 0;
    Mv -= mv;
    int time = 0;
    int minT = 99999;
    int top = 0;
    for(int i = 0;i < Mv;i++){
        bool noBlock = false;
        time = 0;
        for(int j = 0;j < len;j++){
            if(v[j] > i){
                time += 2*(v[j]-i);
            }
            else if(v[j] < i){
                if(b < i - v[j]){
                    noBlock = true;
                    break;
                }
                else{
                    time += i-v[j];
                }
            }
        }
        if(noBlock) break;
        if(minT >= time){
            minT = time;
            top = org + i;
        }
    }
    cout << minT << " " << top;
}

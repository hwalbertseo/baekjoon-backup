#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main(){
    //ios_base::sync_with_stdio(false); cin.tie(0);
    int n, l;
    cin >> n >> l;
    int max = 0;
    int num = 0;
    for(int i = 0;i < n;i++){
        bool cont = false;
        int cnt = 0;
        for(int j = 0;j < l;j++){
            int p;
            scanf("%1d", &p);
            if(p == 1){
                if(!cont){
                    cont = true;
                    cnt += 1;
                }
            }
            else{
                cont = false;
            }
        }
        //cout << cnt << " ";
        //cout << max << "\n";
        if(cnt > max){
            max = cnt;
            num = 1;
        }
        else if(cnt == max){
            num += 1;
        }
    }
    cout << max << " " << num;
}
#include <iostream>
#include <algorithm>

using namespace std;

int nail[2005];
int pole[40005];

int main(){
    int n, m, r;
    cin >> n >> m >> r;
    r *= 2;
    for(int i = 0;i < n;i++){
        cin >> nail[i];
    }
    for(int i = 0;i < m;i++){
        cin >> pole[i];
    }
    int max = 0;
    sort(nail, nail+n);
    for(int i = 0;i < m;i++){
        int height = pole[i];
        int start = 0;
        int end = 0;
        int locmax = 0;
        while(start <= end && end < n){
            int a = nail[start]; int b= nail[end];
            int low = b - a;
            int area = low*height;
            if(area <= r){
                if(locmax < area){
                    locmax = area;
                }
                end += 1;
            }
            else{
                start += 1;
            }
        }
        if(locmax > max){
            max = locmax;
        }
    }
    if(max == 0){
        cout << -1;
    }
    else{
        cout << fixed;
        cout.precision(1);
        cout << (double) max / (double) 2;
    }
}
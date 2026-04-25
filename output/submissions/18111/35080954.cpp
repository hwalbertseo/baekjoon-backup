#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, m, block;
    cin >> n >> m >> block;
    int len = n*m;
    int arr[len];
    int mv, Mv, org;
    for(int i = 0;i < len;i++){
        int temp;
        cin >> arr[i];
        if(mv > arr[i]) mv = arr[i];
        if(Mv < arr[i]) Mv = arr[i];
    }
    org = mv;
    for(int i = 0;i < len;i++){
        arr[i] -= mv;
    }
    mv = 0;
    Mv -= mv;
    int time = 0;
    int minT = 9999999;
    int top = 0;
    for(int i = 0;i < Mv;i++){
        int b = block;
        bool noBlock = false;
        time = 0;
        for(int j = 0;j < len;j++){
            if(arr[j] > i){
                b += arr[j]-i;
                time += 2*(arr[j]-i);
            }
            else if(arr[j] < i){
                if(b < i - arr[j]){
                    noBlock = true;
                    break;
                }
                else{
                    b -= i-arr[j];
                    time += i-arr[j];
                }
            }
        }
        if(noBlock) break;
        if(minT >= time){
            minT = time;
            top = org + i;
        }
    }
    cout << minT << " " << top << "\n";
}

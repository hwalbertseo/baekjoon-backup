#include <iostream>
#include <algorithm>

using namespace std;

int height[500005];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, h;
    cin >> n >> h;
    int minnum = -1;
    int num = 0;
    for(int i = 0;i < n;i++){
        int temp;
        cin >> temp;
        //cout << "\n";
        if(i%2 == 0){
            for(int j = temp-1;j >= 0;j--){
                //cout << " " << j;
                height[j]++;
            }
        }
        else{
            for(int j = h-1;j >= h-temp;j--){
                //cout << " " << j;
                height[j]++;
            }
        }
    }
    sort(height, height+h);
    minnum = height[0];
    for(int i = 0;i < h;i++){
        if(minnum == height[i]){
            num++;
        }
        else {
            break;
        }
    }
    cout << minnum << " " << num;
}

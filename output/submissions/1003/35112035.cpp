#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int num;
    cin >> num;
    int arr0[40] = {0,};
    int arr1[40] = {0,};
    arr0[0] = 1;
    arr0[1] = 0;
    arr1[0] = 0;
    arr1[1] = 1;
    int maxnum = 2;
    for(int i = 0;i < num;i++){
        int temp = 0;
        //cout << " maxnum: " << maxnum << "\n";
        cin >> temp;
        if(arr0[temp] == 0 && arr1[temp] == 0){
            for(;maxnum <= temp;maxnum++){
                arr0[maxnum] = arr0[maxnum-1] + arr0[maxnum-2];
                arr1[maxnum] = arr1[maxnum-1] + arr1[maxnum-2];
                //cout << arr0[maxnum] << " maxnum: " << maxnum << "\n";
            }
            maxnum--;
        }
        cout << arr0[temp] << " " << arr1[temp] << "\n";
    }
}

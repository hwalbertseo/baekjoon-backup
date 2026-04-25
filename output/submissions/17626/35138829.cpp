#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int arr[55000];
    int num;
    cin >> num;
    arr[0] = 1;
    int maxnum = 1;
    for(;maxnum * maxnum <= num;maxnum++){
        //cout << maxnum << "\t";
        continue;
    }

    //step 1;
    for(int i = 1;i <= maxnum;i++){
        arr[i*i] = 1;
    }
    if(arr[num] >0) {cout<< arr[num]; return 0;}

    //step2;
    for(int i = 1;i <= num;i++){
        for(int j = 1;j <= maxnum;j++){
            if(i+j*j <= num && arr[i] == 1 && arr[i+j*j] == 0 ){
                arr[i+j*j] = 2;
            }
        }
        if(arr[num] >0) {cout<< arr[num]; return 0;}
    }
    for(int i = 1;i <= num;i++){
        for(int j = 1;j <= maxnum;j++){
            if(i+j*j <= num && arr[i] == 2 && arr[i+j*j] == 0){
                arr[i+j*j] = 3;
            }
        }
        if(arr[num] >0) {cout<< arr[num]; return 0;}
    }
    for(int i = 1;i <= num;i++){
        for(int j = 1;j <= maxnum;j++){
            if(i+j*j <= num && arr[i]  == 3 && arr[i+j*j] == 0){
                arr[i+j*j] = 4;
            }
        }
        if(arr[num] >0) {cout<< arr[num]; return 0;}
    }

}

#include <iostream>
#include <algorithm>

using namespace std;

int bin(int arr[], int lim, int num){
    int left = 0;
    int right = arr[0];
    int mid;
    int sum = 0;
    while(1){
        sum = 0;
        mid = (right + left)/2;
        for(int j = 0;j < num;j++){
            sum += arr[j]/mid;
        }
        if(sum == lim) {
            sum = 0;
            mid = (right + left)/2 + 1;
            for(int j = 0;j < num;j++){
                sum += arr[j]/mid;
            }
            if(sum == lim){
                left = mid+1;
            }
            else{
                return mid;
            }
        }
        else if(sum > lim){
            left = mid+1;
        }
        else if(sum < lim){
            right = mid-1;
        }
    }
    return mid;
}

bool great(int i, int j){
    return i>j;
}

int main()
{
    int num, lim;
    cin >> num >> lim;
    int arr[num];
    for(int i = 0;i < num;i++){
        cin >> arr[i];
    }
    sort(arr, arr+num, great);
    int n = bin(arr, lim, num);
    cout << n-1;
}

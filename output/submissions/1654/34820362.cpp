#include <iostream>
#include <algorithm>

using namespace std;

int bin(int arr[], int lim, int num){
    long long left = 0;
    long long right = arr[0];
    long long mid, mid2;
    int sum, sum2;;
    while(left<right){
        sum = 0;
        sum2 = 0;
        mid = (right + left)/2;
        mid2 = (right+left)/2 + 1;
        for(int j = 0;j < num;j++){
            sum += arr[j]/mid;
            sum2 += arr[j]/mid2;
        }
        if(sum == lim) {
            if(sum2 == lim){
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
    return left;
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
    if(num == 1) {
        cout << arr[0]/lim;
    }
    else{
        sort(arr, arr+num, great);
        int n = bin(arr, lim, num);
        cout << n;
    }
}

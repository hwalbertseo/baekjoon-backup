#include <iostream>

using namespace std;

int *sorted;

void combine(int arr[], int left, int mid, int right){
    int lInd = left;
    int rInd = mid+1;
    int k = left;
    while(lInd <= mid && rInd <= right){
        if(arr[lInd] <= arr[rInd]){
            sorted[k++] = arr[lInd++];
        }
        else {
            sorted[k++] = arr[rInd++];
        }
    }
    if(lInd > mid){
        for(int i = rInd;i <= right;i++){
            sorted[k++] = arr[i];
        }
    }
    else{
        for(int i = lInd;i <= mid;i++){
            sorted[k++] = arr[i];
        }
    }
    for(int i = left;i <= right;i++){
        arr[i] = sorted[i];
    }
}

void mergeSort(int arr[], int left, int right){
    int mid = (left+ right)/2;
    if(left < right){
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        combine(arr, left, mid, right);
    }
}

int main()
{
    int num;
    cin >> num;
    int arr[num];
    sorted = new int[num];
    for(int i = 0;i < num;i++){
        cin >> arr[i];
    }
    mergeSort(arr,0, num);

    //mean
    double sum = 0;
    int mean = 0;
    for(int i = 0;i < num;i++){
        sum += arr[i];
    }
    sum = sum / num;
    if(sum < 0) mean = sum-0.5;
    else mean = sum + 0.5;

    //median
    int med;
    if(num %2 == 1) med = arr[num/2];
    else med = (arr[num/2 - 1] + arr[num/2])/2;

    //mode
    int mode;
    int cnt = 1;
    int maxcnt = 1;
    int modechange = 0;
    if(num == 1) mode = arr[0];
    else{
        for(int i = 0;i < num-1;i++){
            if(arr[i+1] == arr[i]){
                cnt++;
            }
            else cnt = 1;
            if(maxcnt < cnt){
                maxcnt = cnt;
                mode = arr[i];
                modechange = 1;
            }
            else if(maxcnt == cnt){
                if(modechange == 1){
                    mode = arr[i];
                }
                modechange++;
            }
        }
    }

    //range
    int range = arr[num-1] - arr[0];

    cout << mean << "\n" << med << "\n" << mode << "\n" << range;
}

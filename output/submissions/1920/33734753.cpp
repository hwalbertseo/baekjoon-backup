#include <iostream>

using namespace std;

void quickSort(int arr[], int low, int high){
    //cout << high << " " << low << endl;
    if(high <= low) return;
    int pivot = arr[high];
    int a = low-1;
    for(int i = low;i < high;i++){
        if(arr[i] >= pivot){
            continue;
        }
        else if(arr[i] < pivot){
            a++;
            int temp = arr[i];
            arr[i] = arr[a];
            arr[a] = temp;
        }
    }
    a++;
    int temp = arr[high];
    arr[high] = arr[a];
    arr[a] = temp;
    quickSort(arr, low, a-1);
    quickSort(arr, a+1, high);
    return;
}

int binSrch(int arr[], int strt, int fin, int num){
    int mid = (strt + fin)/2;
    if(fin == strt && arr[mid] != num) return 0;
    if(arr[mid] == num) return 1;
    else if(arr[mid] > num) return binSrch(arr, strt, mid-1, num);
    else if(arr[mid] < num) return binSrch(arr, mid+1, fin, num);
    return 0;
}

int main()
{
    int n1 = 0;
    int n2 = 0;
    cin >> n1;
    int arr1[n1];
    for(int i = 0;i < n1;i++){
        cin >> arr1[i];
    }
    cin >> n2;
    int arr2[n2];
    for(int i = 0;i < n2;i++){
        cin >> arr2[i];
    }

    quickSort(arr1, 0, n1-1);

    for(int i = 0;i < n2;i++){
        cout << binSrch(arr1, 0, n2-1, arr2[i]) <<endl;
    }

}

#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;
/*
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
*/

int binSrch(int arr[], int n, int key){
    int strt = 0;
    int fin = n-1;
    int mid = (strt + fin)/2;
    while(strt <= fin){
        mid = (strt + fin)/2;
        if(arr[mid] == key){
            return 1;
        }
        else if(arr[mid] < key){
            strt = mid+1;
        }
        else if(arr[mid] > key){
            fin = mid-1;
        }
    }
    return 0;
}

int main()
{
    int n1 = 0;
    int n2 = 0;
    scanf("%d", &n1);
    int arr1[n1];
    for(int i = 0;i < n1;i++){
        scanf("%d",&arr1[i]);
    }
    sort(arr1, arr1+n1);
    scanf("%d", &n2);
    for(int i = 0;i < n2;i++){
        int temp =0;
        scanf("%d",&temp);
        printf("%d\n", binSrch(arr1, n2, temp));
    }


}

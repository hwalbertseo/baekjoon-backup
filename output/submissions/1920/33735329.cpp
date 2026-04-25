#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

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
    int temp;
    scanf("%d", &n1);
    int arr1[n1];
    for(int i = 0;i < n1;i++){
        scanf("%d",&arr1[i]);
    }
    sort(arr1, arr1+n1);
    scanf("%d", &n2);
    for(int i = 0;i < n2;i++){
        scanf("%d",&temp);
        printf("%d\n", binSrch(arr1, n2, temp));
    }

    return 0;
}

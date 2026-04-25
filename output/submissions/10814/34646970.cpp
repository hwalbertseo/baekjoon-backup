#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int *temp;
string *ntemp;

void combine(int arr[], int left, int mid, int right, string name[]){
    int lInd = left;
    int rInd = mid+1;
    int k = left;
    while(lInd <= mid && rInd <= right){
        if(arr[lInd] <= arr[rInd]){
            ntemp[k] = name[lInd];
            temp[k++] = arr[lInd++];
        }
        else{
            ntemp[k] = name[rInd];
            temp[k++] = arr[rInd++];
        }
    }
    if(lInd > mid){
        for(int i = rInd;i <= right;i++){
            ntemp[k] = name[i];
            temp[k++] = arr[i];
        }
    }
    else{
        for(int i = lInd;i <= mid;i++){
            ntemp[k] = name[i];
            temp[k++] = arr[i];
        }
    }
    for(int i = left;i <= right;i++){
        name[i] = ntemp[i];
        arr[i] = temp[i];
    }
}

void mergeSort(int arr[], int left, int right, string name[]){
    int mid = (left+right)/2;
    if(left<right){
        mergeSort(arr, left, mid, name);
        mergeSort(arr, mid+1, right, name);
        combine(arr, left, mid, right, name);
    }
}

int main()
{
    int num = 0;
    scanf("%d", &num);
    int number[num];
    temp = new int[num];
    string name[num];
    ntemp = new string[num];
    for(int i = 0;i < num;i++){
        cin >> number[i] >> name[i];
    }
    mergeSort(number, 0, num-1, name);
    for(int i = 0;i < num;i++){
        cout << number[i] << " " << name[i] << "\n";
    }//
}

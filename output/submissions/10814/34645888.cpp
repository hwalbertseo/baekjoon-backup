#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int *temp;

void combine(int arr[], int left, int mid, int right){
    int lInd = left;
    int rInd = mid+1;
    int k = left;
    while(lInd <= mid && rInd <= right){
        if(arr[lInd] <= arr[rInd]){
            temp[k++] = arr[lInd++];
        }
        else{
            temp[k++] = arr[rInd++];
        }
    }
    if(lInd > mid){
        for(int i = rInd;i <= right;i++){
            temp[k++] = arr[i];
        }
    }
    else{
        for(int i = lInd;i <= mid;i++){
            temp[k++] = arr[i];
        }
    }

    for(int i = left;i <= right;i++){
        arr[i] = temp[i];
    }
}

void mergeSort(int arr[], int left, int right){
    int mid = (left+right)/2;
    if(left<right){
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        combine(arr, left, mid, right);
    }
}

int main()
{
    int num = 0;
    scanf("%d", &num);
    int number[num];
    temp = new int[num];
    int ind[num];
    string name[100000];
    for(int i = 0;i < num;i++){
        cin >> number[i] >> name[i];
        ind[i] = number[i];
    }
    mergeSort(number, 0, num-1);
    for(int i = 0;i < num;i++){
        printf("%d ", number[i]);
        for(int j = 0;j < num;j++){
            if(ind[j] == number[i]){
                if(name[j].compare("nullName") != 0) {
                    cout << name[j] << endl;
                    name[j] = "nullName";
                }
                else continue;
                break;
            }
        }
    }
}

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
        //cout << arr[k] << name[k] << endl;
        if(arr[lInd] <= arr[rInd]){
            //printf("1");
            ntemp[k] = name[lInd];
            temp[k++] = arr[lInd++];
        }
        else{
            //printf("2");
            ntemp[k] = name[rInd];
            temp[k++] = arr[rInd++];
        }
    }
    if(lInd > mid){
        //printf("3");
        for(int i = rInd;i <= right;i++){
            ntemp[k] = name[i];
            temp[k++] = arr[i];
        }
    }
    else{
        //printf("4");
        for(int i = lInd;i <= mid;i++){
            ntemp[k] = name[i];
            temp[k++] = arr[i];
        }
    }
    for(int i = left;i <= right;i++){
        //cout << ntemp[i];
        //cout << name[i];
        name[i] = ntemp[i];
        //cout << name[i] << endl;
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
        cout << number[i] << " " << name[i] << endl;
    }//
}

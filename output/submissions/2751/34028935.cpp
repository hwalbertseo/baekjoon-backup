#include <iostream>
#include <stdio.h>

using namespace std;

void qs(int arr[], int beg, int fin){
    if(beg >= fin) return;
    int piv = fin;
    int p = beg-1;
    for(int i = beg;i < fin;i++){
        if(arr[i] < arr[piv]){
            p++;
            int temp = arr[i];
            arr[i] = arr[p];
            arr[p] = temp;
        }
    }
    p++;
    int temp = arr[piv];
    arr[piv] = arr[p];
    arr[p] = temp;
    qs(arr, beg, p-1);
    qs(arr, p+1, fin);
}

int main()
{
    int num = 0;
    scanf("%d", &num);
    int arr[num];
    for(int i = 0;i < num;i++){
        scanf("%d", &arr[i]);
    }
    qs(arr, 0, num-1);
    for(int i = 0;i < num;i++){
        printf("%d ", arr[i]);
    }
}

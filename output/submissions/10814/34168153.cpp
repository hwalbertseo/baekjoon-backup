#include <iostream>
#include <stdio.h>

using namespace std;

void swapE(int x[], int i, int j){
    int temp = x[i];
    x[i] = x[j];
    x[j] = temp;
}

void maxHeap(int x[], int parent, int len){
    int bigInd = parent*2;
    int child1 = x[parent*2];
    if(parent*2 > len) return;
    //printf("parent: %d\n", parent);
    if(parent*2+1 <= len) {
        //printf("1");
        int child2 = x[parent*2+1];
        bigInd = (child1 < child2) ? parent*2+1 : parent*2;
        //printf("bigInd: %d, child1: %d, child2: %d\n", bigInd, child1, child2);
    }

    if(x[bigInd] > x[parent]) {
        //printf("2");
        swapE(x, parent, bigInd);
        if(parent != 1) maxHeap(x, parent/2, len);
    }

    if(parent*2 <= len){
        //printf("3");
        maxHeap(x, parent*2, len);
    }

    if(parent*2+1 <= len) {
        //printf("4");
        maxHeap(x, parent*2+1, len);
    }
    //printf("5");
    return;
}

typedef struct student{
    int number;
    string name;
}Stud;

int main()
{
    int num;
    scanf("%d", &num);
    int arr[num+1];
    Stud arr2[num+1];
    arr[0] = -1;
    arr2[0].number = 0;
    for(int i = 1;i < num+1;i++){
        scanf("%d %s", &arr2[i].number, &arr2[i].name);
        arr[i] = arr2[i].number;
    }
    for(int i = num;i > 0;i--){
        maxHeap(arr, 1, i);
        swapE(arr, 1, i);
    }
    for(int i = 1;i < num+1;i++){
        printf("%d ", arr[i]);
        for(int j = 1;j <= num;j++){
            if(arr2[j].number == arr[i]){
                printf("%s", arr2[j].name);
                arr2[j].number = 0;
                break;
            }
        }
        printf("\n");
    }

}
/*
5
3
1
4
5
7
*/

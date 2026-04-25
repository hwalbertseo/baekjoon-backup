#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int num = 0;
    scanf("%d", &num);
    int arr[num][3];
    for(int i = 0;i < num;i++){
        scanf("%d %d", &arr[i][0], &arr[i][1]);
    }
    for(int i = 0;i < num;i++){
        arr[i][2] = 1;
    }
    for(int i = 0;i < num;i++){
        for(int j = 0;j < num;j++){
            if(arr[i][0] < arr[j][0] && arr[i][1] < arr[j][1]){
                arr[i][2]++;
            }
        }
    }
    for(int i = 0;i < num;i++){
        printf("%d ", arr[i][2]);
    }
}

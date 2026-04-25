#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int arr[10000] = {0,};
    int num;
    scanf("%d", &num);
    for(int i = 0;i < num;i++){
        int temp;
        scanf("%d", &temp);
        arr[temp-1]++;
    }
    for(int i = 0;i < 10000;i++){
        if(arr[i-1] >= 1){
            for(int j = 1;j <= arr[i];j++){
                printf("%d", i+1);
            }
        }
    }
}

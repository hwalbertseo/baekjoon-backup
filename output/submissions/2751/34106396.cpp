#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int num = 0;
    scanf("%d", &num);
    bool arr2[1000000] = {false,};
    bool arr1[1000000] = {false,};
    for(int i = 0;i < num;i++){
        int temp = 0;
        scanf("%d", &temp);
        if(temp >= 0) arr1[temp-1] = true;
        else arr2[-(temp+1)] = true;
    }
    for(int i = 1000000-1;i >=0;i--){
        if(arr2[i]) printf("%d\n", -(i+1));
    }
    for(int i = 0;i < 1000000;i++){
        if(arr1[i]) printf("%d\n", i+1);
    }

}

#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int num = 0;
    scanf("%d", &num);
    bool arr[1000000] = {false,};
    for(int i = 0;i < num;i++){
        int temp = 0;
        scanf("%d", &temp);
        arr[temp-1] = true;
    }
    for(int i = 0;i < 1000000;i++){
        if(arr[i]) printf("%d\n", i+1);
    }

}

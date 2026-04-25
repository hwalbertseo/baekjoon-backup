#include <iostream>
#include <cstdio>

using namespace std;


int main()
{
    int sum = 0;
    int rem[42] = {0,};
    for(int i = 0;i < 10;i++){
        int temp;
        scanf("%d", &temp);
        int remTemp = temp%42;
        rem[remTemp]++;
    }
    for(int i = 0;i < 42;i++){
        if(rem[i] > 0) sum++;
    }
    printf("%d", sum);
}

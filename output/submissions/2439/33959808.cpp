#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int num = 0;
    scanf("%d", &num);
    for(int i = 0;i < num;i++){
        for(int j = 1;j < num-i;j++){
            printf(" ");
        }
        for(int j = 0;j <= i;j++){
            printf("*");
        }
        printf("\n");
    }
}

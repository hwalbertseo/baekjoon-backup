#include <stdio.h>
#include <stdlib.h>

//14697
int main()
{
    int a;
    int b;
    int c;
    int num;
    int j = 300;
    scanf("%d %d %d %d", &a, &b, &c, &num);
    for(int p = 0;p < j;p++){
        for(int q = 0;q < j;q++){
            for(int r = 0;r < j;r++){
                if((a*p) + (b*q) + (c*r) == num){
                    printf("1");
                    return;
                }
            }
        }
    }
    printf("0");
}
#include <stdio.h>
#include <stdlib.h>

int a, b;
int c[100];
int p;

int main()
{
    for(p = 0;;p++){
        scanf("%d %d", &a, &b);
        if(a == 0 && b == 0){
            break;
        }
        else{
            c[p] = a+b;
        }
    }
    for(int q = 0;q < p;q++){
        printf("%d \n", c[q]);
    }
}

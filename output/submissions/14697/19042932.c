#include <stdlib.h>
#include <stdio.h>

int n;
int a, b, c;
int m[1000] = {0,};

int main()
{
    m[0] = 1;
    scanf("%d %d %d %d", &a, &b, &c, &n);
    for(int p = 0;p < n;p++){
        if(m[p] == 1){
            m[p + a] = 1;
            m[p + b] = 1;
            m[p + c] = 1;
        }
    }
    printf("%d", m[n]);
}

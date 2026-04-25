#include <stdio.h>
#include <stdlib.h>

int n = 0;

struct node{
    int coo;
    int col;
    int len;
};

struct node p[9999999];

int srch(int x1, int x2){
    //printf("x1: %d x2: %d, %d\n", x1, x2, n);
    if(x2 >= n){
        //printf("x1: %d x2: %d, %d\n", x1, x2, n);
        //printf("1\n");
        srch(x1 + 1, 0);
        return;
    }
    if(x1 >= n){
        //printf("x1: %d x2: %d, %d\n", x1, x2, n);
        //printf("2\n");
        return;
    }
    if(x1 == x2){
        //printf("x1: %d x2: %d, %d\n", x1, x2, n);
        //printf("3\n");
        srch(x1, x2+1);
        return;
    }

    if(p[x2].col == p[x1].col){
        if(p[x1].len == 0 || abs(p[x1].coo - p[x2].coo) < p[x1].len){
            p[x1].len = abs(p[x1].coo - p[x2].coo);
            //printf("q\n");
            srch(x1, x2+1);
            return;
        }
    }
    srch(x1, x2+1);
    return;
}

int main()
{
    scanf("%d", &n);
    for(int q = 0;q < n;q++){
        scanf("%d %d", &p[q].coo, &p[q].col);
    }
    for(int q = 0;q < n;q++){
        p[q].len = 0;
    }
    srch(0, 0);
    int cnt = 0;
    for(int q = 0;q < n;q++){
        cnt = cnt + p[q].len;
    }
    printf("%d", cnt);
}

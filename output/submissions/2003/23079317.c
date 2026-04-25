#include <stdio.h>
#include <stdlib.h>

int n = 0;
int m = 0;
int cnt = 0;
int sum = 0;

int a[999999] = {0,};

int jg(int x, int y){
    //printf("\nsum: %d, %d, %d\n", sum, x, y);
    if(y == n && sum < m){
        //printf("1");
        return;
    }
    if(x == y){
        //printf("2");
        sum = sum + a[y];
        jg(x, y + 1);
        return;
    }
    if(sum == m){
        //printf("3");
        cnt++;
        sum = sum - a[x];
        jg(x + 1, y);
        return;
    }
    if(sum > m){
        //printf("4");
        sum = sum - a[x];
        jg(x + 1, y);
        return;
    }
    if(sum < m){
        //printf("5");
        sum = sum + a[y];
        jg(x, y + 1);
        return;
    }
    return;
}

int main()
{
    //Baekjoon 2003
    scanf("%d %d", &n, &m);
    for(int i = 0;i < n;i++){
        scanf("%d", &a[i]);
    }
    jg(0, 0);
    printf("%d", cnt);
}

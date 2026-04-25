#include <stdio.h>
#include <stdlib.h>

int l[99999] = {0,};
int p[99999] = {0,};
int v[99999] = {0,};
int cnt = 0;
int n = 0;

int hamsu(int adays, int lday, int tday){
    int total;
    int temp = tday / lday;
    int temp2 = tday % lday;
    if(temp2 <= 5) total = temp*5 + temp2;
    else total = temp*5 + 5;
    return total;
}

int main()
{
    for(int i = 0;;i++){
        scanf("%d %d %d", &l[i], &p[i], &v[i]);
        if(l[i] == 0 && p[i] == 0 && v[i] == 0){
            n = i;
            break;
        }
    }
    for(int i = 0;i < n;i++){
        printf("Case %d: %d\n", i+1, hamsu(l[i], p[i], v[i]));
    }
}

#include <stdio.h>
#include <stdlib.h>

int n = 0;
int l = 0;
int a[1005] = {0,};
int cnt = 0;

int main()
{
    scanf("%d %d", &n, &l);
    for(int i = 0;i < n;i++){
        int temp;
        scanf("%d", &temp);
        a[temp] = 1;
    }
    l = l - 1;
    /*
    for(int i = 0; i < 1000; i++){
        printf("%d ", a[i]);
    }
    */
    for(int i = 0; i < 1001; i++){
        if(a[i] == 1){
            for(int j = 0;j <= l;j++){
                a[i + j] = 0;
            }
            cnt++;
        }
    }
    printf("%d", cnt);
}

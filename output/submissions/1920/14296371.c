#include <stdio.h>
#include <stdlib.h>

int n[100000000];
int m[100000000];
int nn;
int mn;
int cnt = 0;

int main()
{
    scanf("%d", &nn);
    for(int p = 0;p < nn;p++){
        scanf("%d",&n[p]);
    }
    scanf("%d", &mn);
    for(int p = 0;p < mn;p++){
        scanf("%d",&m[p]);
    }
    printf("\n");
    for(int p = 0;p < mn;p++){
        cnt = 0;
        for(int q = 0;q < nn;q++){
            if(n[q] == m[p]){
                cnt++;
            }
        }
        printf("%d\n",cnt);
    }
}

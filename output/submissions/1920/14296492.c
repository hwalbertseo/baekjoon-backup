#include <stdio.h>
#include <stdlib.h>

int n[10000];
int m[10000];
int nn = 0;
int mn = 0;
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
    for(int p = 0;p < mn;p++){
        cnt = 0;
        for(int q = 0;q < nn;q++){
            if(n[q] == m[p]){
                cnt++;
                break;
            }
        }
        printf("%d\n",cnt);
    }
}

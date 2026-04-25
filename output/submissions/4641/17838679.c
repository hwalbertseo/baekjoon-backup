#include <stdio.h>
#include <stdlib.h>

int n[9999][9999] = {0,};
int map = 0;
int numb = 0;
int num[9999] = {0,};
int plchd;
int cnt = 0;

int main()
{
    for(int p = 0;;p++){
        //printf("ent");
        if(map == -1){
            numb = p -1;
            break;
        }
        for(int q = 0;;q++){
            scanf("%d", &n[p][q]);
            if(n[p][q] == 0){
                num[p] = q - 1;
                break;
            }
            if(n[p][q] == -1){
                map = -1;
                break;
            }
        }
    }
    for(int p = 0;p < numb;p++){
        //printf("int\n");
        //printf("%d\n", num[p]);
        for(int q = 0;q < num[p];q++){
            //printf("ent\n");
            if(n[p][q] > n[p][q+1]){
                //printf("%d, %d\n", n[p][q], n[p][q+1]);
                plchd = n[p][q];
                n[p][q] = n[p][q+1];
                n[p][q+1] = plchd;
                p = 0;
                q = -1;
            }
        }
    }

    for(int p = 0;p < numb;p++){
        cnt = 0;
        for(int q = 0;q < num[p];q++){
            //printf("ent\n");
            for(int r = q;r < num[p];r++){
                //printf("%d %d %d\n", n[p][q], n[p][r], n[p][r] % n[p][q]);
                if(n[p][q] != n[p][r] && n[p][r] == n[p][q] * 2){
                    cnt++;
                    //printf("\n");
                }
            }
        }
        printf("%d\n", cnt);
    }
    /*
    map = 0;
    for(int p = 0;;p++){
        //printf("ent");
        if(map == -1){
            break;
        }
        for(int q = 0;;q++){
            printf("%d ", n[p][q]);
            if(n[p][q] == 0){
                break;
            }
            if(n[p][q] == -1){
                map = -1;
                break;
            }
        }
        printf("\n");
    }*/

}

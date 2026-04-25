#include <stdio.h>
#include <stdlib.h>

int n = 0;
int k = 0;
int cus[1000002][3] = {{0,}};
int ct[1000002][3] = {{0,}};
long long cnt1 = 0;
long long cnt2 = 0;
int arrcnt = 3;

int arrlen(){
    for(int i = 0;i < 99999;i++){
        if(cus[i][0] != 0){
            return i;
        }
    }
}


int cemp(){
    int tempcnt = 0;
    for(int i = 0;i < k;i++){
        if(ct[i][0] == 0) tempcnt++;
    }
    if(tempcnt >= k) return 1;
    else return 0;
}

int main()
{
    scanf("%d %d", &n, &k);

    for(int i = 0;i < n;i++){
        scanf("%d %d", &cus[i][0], &cus[i][1]);
    }

    for(int i = 0;i < k;i++){
        int temp = arrlen();
        ct[i][0] = cus[temp][0];
        ct[i][1] = cus[temp][1];
        cus[temp][0] = 0;
    }

    for(;;){
        if(cemp() == 1){
            break;
        }
        for(int x = 0;x < k;x++){
            if(ct[x][0] == 0){
                ct[x][1] = -1;
            }
        }
        for(int p = k - 1;p > -1;p--){
            if(ct[p][1] == 0){
                cnt2++;
                //printf("2: %d 1: %d ct: %d. %d. %d \n", cnt2, cnt1, ct[p][0], (cnt2*ct[p][0]), cnt1 + (cnt2*ct[p][0]));
                cnt1 = cnt1 + (cnt2*ct[p][0]);

            }
        }
        for(int p = 0; p < k;p++){
            if(ct[p][1] <= 0){
                //int temp = arrlen();
                ct[p][0] = cus[arrcnt][0];
                ct[p][1] = cus[arrcnt][1];
                cus[arrcnt][0] = 0;
                arrcnt++;
            }
        }

        for(int p = 0; p < k;p++){
            ct[p][1]--;
        }
        //printf("%d\n", arrlen());
/*
        for(int p = 0; p < k;p++){
            printf("\n%d %d", ct[p][0], ct[p][1]);
        }
*/
        //printf("\n");
    }
    //for(int i = 0;i < n;i++){
    //    printf("%d, ", ord[i]);
    //}
    printf("%d", cnt1);
}

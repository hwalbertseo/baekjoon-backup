#include <stdio.h>
#include <stdlib.h>

int n;
int k;
int cus[1000000][2];
int ct[1000000][2];
int second = 1;
int ord[1000000] = {0,};
long long cnt = 0;

int arrlen(){
    for(int i = 0;i < 99999;i++){
        if(cus[i][0] != 0){
            return i;
        }
    }
}

int arrlen2(int x[]){
    for(int i = 0;i < 99999;i++){
        if(x[i] == 0){
            return i;
        }
    }
}

long long addi(int x[]){
    for(int i = 0;i < 99999;i++){
        cnt = cnt + ((i+1) * ord[i]);
    }
    return cnt;
}

int cemp(){
    int tempcnt = 0;
    for(int i = 0;i < k;i++){
        if(ct[i][0] == 0) tempcnt++;
    }
    if(tempcnt == k) return 1;
    else return 0;
}

int main()
{
    scanf("%d %d", &n, &k);

    for(int i = 0;i < n;i++){
        scanf("%d %d", &cus[i][0], &cus[i][1]);
    }

    for(int i = 0;i < k;i++){
        ct[i][0] = cus[arrlen()][0];
        ct[i][1] = cus[arrlen()][1];
        cus[arrlen()][0] = 0;
    }

    for(int pr = 0;pr < 9999; pr++){
        if(cemp() == 1){
            break;
        }
        for(int p = k - 1;p > -1;p--){
            if(ct[p][1] <= 0){
                ord[arrlen2(ord)] = ct[p][0];
            }
        }
        for(int p = 0; p < k;p++){
            if(ct[p][1] <= 0){
                ct[p][0] = cus[arrlen()][0];
                ct[p][1] = cus[arrlen()][1];
                cus[arrlen()][0] = 0;
            }
        }

        for(int p = 0; p < k;p++){
            ct[p][1]--;
        }
        //printf("%d\n", arrlen());
        //printf("%d %d\n", one.cusnm, one.tm);
        //printf("%d %d\n", two.cusnm, two.tm);
        //printf("%d %d\n\n", three.cusnm, three.tm);
    }
    //printf("%d\n", arrlen2(ord));
    //for(int i = 0;i < n;i++){
    //    printf("%d, ", ord[i]);
    //}
    printf("%d", addi(ord));
}

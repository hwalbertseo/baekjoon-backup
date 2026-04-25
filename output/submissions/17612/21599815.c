#include <stdio.h>
#include <stdlib.h>

int n;
int k;
int cus[100000][2];
int second = 1;
int ord[100000] = {0,};
int cnt = 0;

struct cntr{
    int cusnm;
    int tm;
};

struct cntr one;
struct cntr two;
struct cntr three;

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

int addi(int x[]){
    for(int i = 0;i < arrlen2(ord);i++){
        cnt = cnt + ((i+1) * ord[i]);
    }
    return cnt;
}

int main()
{
    scanf("%d %d", &n, &k);

    for(int i = 0;i < n;i++){
        scanf("%d %d", &cus[i][0], &cus[i][1]);
    }
    printf("\n");

    one.cusnm = cus[arrlen()][0];
    one.tm = cus[arrlen()][1];
    cus[arrlen()][0] = 0;

    two.cusnm = cus[arrlen()][0];
    two.tm = cus[arrlen()][1];
    cus[arrlen()][0] = 0;

    three.cusnm = cus[arrlen()][0];
    three.tm = cus[arrlen()][1];
    cus[arrlen()][0] = 0;

    for(;;){
        if(three.cusnm == 0 && two.cusnm == 0 && one.cusnm == 0){
            break;
        }

        if(three.tm <= 0){
            ord[arrlen2(ord)] = three.cusnm;
        }

        if(two.tm <= 0){
            ord[arrlen2(ord)] = two.cusnm;
        }

        if(one.tm <= 0){
            ord[arrlen2(ord)] = one.cusnm;
        }

        if(one.tm == 0){
            one.cusnm = cus[arrlen()][0];
            one.tm = cus[arrlen()][1];
            cus[arrlen()][0] = 0;
        }

        if(two.tm <= 0){
            two.cusnm = cus[arrlen()][0];
            two.tm = cus[arrlen()][1];
            cus[arrlen()][0] = 0;
        }

        if(three.tm <= 0){
            three.cusnm = cus[arrlen()][0];
            three.tm = cus[arrlen()][1];
            cus[arrlen()][0] = 0;
        }

        one.tm--;
        two.tm--;
        three.tm--;
        //printf("%d\n", arrlen());
        //printf("%d %d\n", one.cusnm, one.tm);
        //printf("%d %d\n", two.cusnm, two.tm);
        //printf("%d %d\n\n", three.cusnm, three.tm);
    }
    //printf("%d\n", arrlen2(ord));
    //for(int i = 0;i < n;i++){
    //    printf("%d, ", ord[i]);
    //}
    printf("\n%d", addi(ord));
}

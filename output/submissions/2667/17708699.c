#include <stdio.h>
#include <stdlib.h>

int arr[25][25] = {0,};
int a = 0;
int cnt = 0;
int cnt1[100] = {0,};
int recent;
int use;

int tans(){
    for(int o = 0;o < 100;o++){
        if(cnt1[o] == 0){
            return o;
        }
    }
}

void choo(int x, int y){
    cnt1[recent]++;
    arr[x][y] = -2;
    //printf("\n(%d, %d) entered\n", x, y);
    //printf("%d\n", cnt1[recent]);
    if(x == -1 || x == a){
        //printf("x returned\n\n");
        return;
    }
    if(y == -1 || y == a){
        //printf("y returned\n\n");
        return;
    }
    if(arr[x + 1][y] == 1){
        //printf("ent (%d,%d) check: %d\n", x + 1, y, arr[x+1][y]);
        choo(x + 1,y);
    }
    if(arr[x][y + 1] == 1){
        //printf("ent (%d,%d) check: %d\n", x, y + 1, arr[x][y + 1]);
        choo(x,y + 1);
    }
    if(arr[x - 1][y] == 1){
        //printf("ent (%d,%d) check: %d\n", x - 1, y, arr[x-1][y]);
        choo(x - 1,y);
    }
    if(arr[x][y - 1] == 1){
        //printf("ent(%d,%d) check: %d\n", x, y - 1, arr[x][y-1]);
        choo(x,y - 1);
    }
    return;
}


int main()
{
    scanf("%d", &a);
    if(5 > a || a > 25){
        return;
    }
    for(int p = 0;p < a;p++){
        for(int q = 0;q <a;q++){
            scanf("%1d", &arr[p][q]);
        }
    }
    for(int r = 0;r < a; r++){
        for(int f = 0; f < a; f++){
            //printf("\n(%d,%d) check: %d\n", r, f, arr[r][f]);
            if(arr[r][f] == 1){
                cnt++;
                recent = tans();
                //printf("recent: %d\n", recent);
                choo(r,f);
            }
        }
    }
    printf("\n%d\n", cnt);
    for(int m = 0;m < tans();m++){
        for(int n = 0;n < tans();n++){
            if(m < n && cnt1[m] > cnt1[n]){
                use = cnt1[m];
                cnt1[m] = cnt1[n];
                cnt1[n] = use;
            }
        }
    }
    for(int u = 0;u < tans();u++){
        printf("%d\n",cnt1[u]);
    }
}
/*
7
0110100
0110101
1110101
0000111
0100000
0111110
0111000

3
7
8
9
*/

#include <stdio.h>
#include <stdlib.h>

int arr[10000][55][55] = {{{0,}}};

int TC;
int k;
int xlen[10000], ylen[10000];
int cnt = 0;
int result;
int k = 0;

void makezero(int p, int q, int r){
    arr[p][q][r] = 0;
    k++;
    //printf("makezero %d  %d %d\n", k, q, r);
    if(arr[p][q+1][r] == 1){
        makezero(p, q+1, r);
    }
    if(arr[p][q][r+1] == 1){
        makezero(p, q, r+1);
    }
    if(arr[p][q+1][r] != 1 && arr[p][q][r+1] != 1){
        return;
    }
}

int bfs(int tc, int x, int y){
    //printf("lp\n");
    if(arr[tc][x][y] == 0){
        if(x == xlen[tc] + 1 && y == ylen[tc] + 1){
            result = cnt;
            return;
        }
        if(x == xlen[tc] + 1 && y != ylen[tc] + 1){
            bfs(tc, 0, y+1);
            return;
        }
        bfs(tc, x+1, y);
    }
    else{
        cnt++;
        makezero(tc, x, y);
        if(x == xlen + 1 && y == ylen + 1){
            return;
        }
        if(x == xlen + 1 && y != ylen + 1){
            bfs(tc, 0, y+1);
            return;
        }
        bfs(tc, x+1, y);
    }
    return;
}

int main() {
    scanf("%d", &TC);
    for(int i = 0;i < TC;i++){
        scanf("%d %d %d", &xlen[i], &ylen[i], &k);
        for(int j = 0;j < k;j++){
            int xc;
            int yc;
            scanf("%d %d", &xc, &yc);
            arr[i][xc+1][yc+1] = 1;
        }
    }
    for(int i = 0;i < TC;i++){
        /*
        for(int j = 0;j < xlen[i];j++){
            for(int k = 0; k < ylen[i];k++){
                printf("%d ", arr[i][j][k]);
            }
            printf("\n");
        }
        */
        //printf("\n");
        cnt = 0;
        bfs(i, 0, 0);
        printf("%d\n", cnt);
    }
}
/*
2
10 8 17
0 0
1 0
1 1
4 2
4 3
4 5
2 4
3 4
7 4
8 4
9 4
7 5
8 5
9 5
7 6
8 6
9 6
10 10 1
5 5
*/

#include <stdio.h>
#include <stdlib.h>

int k, n;
int arr[999999] = {0,};
int in;

int max(int a, int b){
    int temp = 0;
    temp = (a > b) ? a : b;
}

int res(int p){
    //printf("jung\n");
    int cnt = 0;
    for(int r = 0;r < k;r++){
        cnt = cnt + (arr[r] / p);
    }
    return cnt;
}

int bin(int x, int y){
    int mid = (x + y) / 2;
    printf("%d %d %d\n", x, y, mid);
    if(res(mid) == 1 && res(mid + 1) != 1){
        return mid;
    }
    else if(y - 1 == x){
        return mid;
    }
    else if(res(mid) >= n){
        bin(mid,y);
    }
    else if(res(mid) < n){
        bin(x,mid);
    }
}

int main()
{
    scanf("%d %d", &k, &n);
    for(int i = 0;i < k;i++){
        scanf("%d", &arr[i]);
        if(max(arr[1], arr[i]) == arr[i]){
            int temp = arr[1];
            arr[1] = arr[i];
            arr[i] == temp;
        }
        //printf("ji");
    }
    printf("%d", bin(1, arr[1]));
}

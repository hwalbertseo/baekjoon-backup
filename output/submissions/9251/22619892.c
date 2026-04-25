#include <stdio.h>
#include <string.h>

int main()
{
    char a[10000];
    char b[10000];

    scanf("%s", a);
    scanf("%s", b);

    int arr[100][100] = {0,};

    for(int i = 0;i < strlen(a)+1;i++){
        arr[i][0] = 0;
        arr[0][i] = 0;
    }

    for(int i = 1;i < strlen(a)+1;i++){
        for(int j = 1;j < strlen(b)+1; j++){
            if(a[i-1] == b[j-1]){
                arr[i][j] = arr[i-1][j-1] + 1;
            }
            else{
                arr[i][j] = (arr[i-1][j] > arr[i][j-1]) ? arr[i-1][j] : arr[i][j-1];
            }
        }
    }

    printf("%d", arr[strlen(a)][strlen(b)]);
}

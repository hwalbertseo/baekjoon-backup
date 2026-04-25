#include <stdio.h>
#include <string.h>

int main()
{
    char a[] = "ACAYKP";
    char b[] = "CAPCAK";

    scanf("%s", a);
    scanf("%s", b);

    //char an[] = "0";
    //char bn[] = "0";

    //strcat(an, a);
    //strcat(bn, b);

    int arr[100][100] = {0,};

    for(int i = 0;i < sizeof(a);i++){
        arr[i][0] = 0;
        arr[0][i] = 0;
    }

    for(int i = 1;i < sizeof(a);i++){
        for(int j = 1;j < sizeof(b); j++){
            if(a[i-1] == b[j-1]){
                arr[i][j] = arr[i-1][j-1] + 1;
            }
            else{
                arr[i][j] = (arr[i-1][j] > arr[i][j-1]) ? arr[i-1][j] : arr[i][j-1];
            }
        }
    }
    for(int i = 1;i < sizeof(a);i++){
        for(int j = 1;j < sizeof(b); j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("%d", arr[sizeof(a)-1][sizeof(b)-1]);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0;i < n;i++){
        char s[100];
        scanf("%s", &s);
        int point = 0;
        int totpoint = 0;
        for(int j = 0;j < strlen(s);j++){
            if(s[j] == 'X'){
                point = 0;
            }
            else{
                point++;
            }
            totpoint += point;
        }
        printf("%d\n", totpoint);
    }
}

#include <stdio.h>
#include <stdlib.h>

int m;
int n;
int l;
int a, b, c;
int cnt = 0;
int rec;

int main()
{
    scanf("%d", &l);
    for(int m = 2;m <= l;m++){
        for(int n = 1;n < m;n++){
            a = m*m - n*n;
            b = 2 * m * n;
            c = m*m + n*n;
            if((a * a) + (b * b) == (c * c)){
            //printf("brrt: %d %d %d %d %d\n", m, n, a, b, c);
                if(a < b){
                    rec = b % a;
                    if(a % rec == 0 && b % rec == 0 && c % rec == 0 && rec != 1){
                    }
                    else{
                        //printf("%d %d %d %d %d\n", m, n, a, b, c);
                        cnt++;
                    }
                }
                else if(b < a){
                    rec = a % b;
                    if(a % rec == 0 && b % rec == 0 && c % rec == 0 && rec != 1){
                    }
                    else{
                        //printf("%d %d %d %d %d\n", m, n, a, b, c);
                        cnt++;
                    }
                }
            }
        }
    }
    printf("%d", cnt);
}

#include <stdio.h>
#include <stdlib.h>

int cnt = 0;
int blah = 0;

int drop(int dl, int db){
    if (db <= dl*10){
        blah = blah + (dl % db)/(db / 10);
        drop(dl, db*10);
    }
    else{
        if(dl % blah == 0){
            //printf("dl: %d, blah: %d\n", dl, blah);
            cnt++;
            return;
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    if(n <= 10){
        printf("%d", n);
    }
    else{
        for(int doc = 11;doc <= n;doc++){
            blah = 0;
            drop(doc, 10);
        }
        printf("%d", cnt + 10);
    }
}

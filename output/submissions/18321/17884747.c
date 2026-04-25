#include <stdio.h>
#include <stdlib.h>

struct node{
    int ent1;
    int ent2;
    int width;
};

struct node wormhole[100005];

int fact[100005] = {0,};
int cow[100005] = {0,};
int sortspace = 0;
int minw = -1;
int nworm;
int ncow;
int lazy;

void xmove(int h){
    if(h > ncow){
        return;
    }
    if(cow[h - 1] == fact[h - 1]){
        sort(h + 1);
        return;
    }
    for(int j = 0;j < nworm;j++){
        if(wormhole[j].ent1 == cow[h-1]){
            sort(lazy);
            xmove(lazy);
            continue;
        }

        /*
        else if(wormhole[j].ent2 == cow[m-1]){
            if(minw < 0 || wormhole[j].width < minw){
                minw = wormhole[j].width;
            }
            sortspace = cow[m-1];
            cow[m-1] = cow[wormhole[j].ent1];
            cow[wormhole[j].ent1] = sortspace;
            sort(lazy);
            continue;
        }*/
    }
    return;
}


void sort(int m){
    if(m > ncow){
        return;
    }
    if(cow[m - 1] == fact[m - 1]){
        sort(m + 1);
        return;
    }
    for(int j = 0;j < nworm;j++){
        if(wormhole[j].ent1 == cow[m-1]){
            if(minw < 0 || wormhole[j].width < minw){
                minw = wormhole[j].width;
            }
            sortspace = cow[m-1];
            cow[m-1] = cow[wormhole[j].ent2];
            cow[wormhole[j].ent2] = sortspace;
            sort(lazy);
            xmove(lazy);
            continue;
        }
        /*
        else if(wormhole[j].ent2 == cow[m-1]){
            if(minw < 0 || wormhole[j].width < minw){
                minw = wormhole[j].width;
            }
            sortspace = cow[m-1];
            cow[m-1] = cow[wormhole[j].ent1];
            cow[wormhole[j].ent1] = sortspace;
            sort(lazy);
            continue;
        }*/
    }
    return;
}

int main()
{
    scanf("%d %d", &ncow, &nworm);
    for(int p = 0;p < ncow;p++){
        cow[p] = p + 1;
    }
    for(int p = 0;p < ncow;p++){
        scanf("%d", &fact[p]);
    }
    for(int p = 0;p < nworm;p++){
        scanf("%d %d %d", &wormhole[p].ent1, &wormhole[p].ent2, &wormhole[p].width);
    }
    for(int p = 0;p < nworm;p++){
        if(cow[p] != fact[p]){
            lazy = p;
        }
    }
    sort(1);
    printf("%d", minw);
}

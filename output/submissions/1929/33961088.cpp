#include <iostream>
#include <cstdio>

using namespace std;

void setHash(int has[], int len){
    for(int i = 2;i < len;i++){
        for(int j = 2;i*j < len;j++){
            has[i*j] = 1;
        }
    }
}

int main()
{
    int p, q;
    scanf("%d %d", &p, &q);
    int hashTable[q+1] = {0,};
    setHash(hashTable, q+1);
    for(int i = p;i < q+1;i++){
        if(hashTable[i] == 0) printf("%d\n", i);
    }
}

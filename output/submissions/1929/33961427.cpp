#include <iostream>
#include <cstdio>

using namespace std;

void setHash(bool has[], int len){
    for(int i = 2;i < len;i++){
        if(has[i] == false){
            if(i < 1001){
                for(int j = i * i;j < len;j = j + i){
                    has[j] = true;
                }
            }
        }
    }
}

int main()
{
    int p, q;
    scanf("%d %d", &p, &q);
    bool hashTable[q+1] = {false,};
    setHash(hashTable, q+1);
    for(int i = p;i < q+1;i++){
        if(hashTable[i] == false) printf("%d\n", i);
    }
}

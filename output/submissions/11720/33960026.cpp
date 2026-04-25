#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int num = 0;
    scanf("%d", &num);
    int sum = 0;
    for(int i = 0;i < num;i++){
        int temp;
        scanf("%1d", &temp);
        sum += temp;
    }
    printf("%d", sum);
}

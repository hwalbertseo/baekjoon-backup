#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int sum = 0;
    for(int i = 0;i < 5;i++){
        int temp = 0;
        scanf("%d", &temp);
        sum += temp*temp;
    }
    printf("%d", sum%10);
}

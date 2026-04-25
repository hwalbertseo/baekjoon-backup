#include <iostream>
#include <cstdio>
#include <math.h>

using namespace std;

double mean(double arr[], int num){
    double sum = 0;
    for(int i = 0;i < num;i++){
        sum = sum + arr[i];
        //printf("%lf\n", arr[i]);
    }
    return sum/(double)num;
}

int main()
{
    int num = 0;
    scanf("%d", &num);
    double maxi = 0;
    double arr[num];
    for(int i = 0;i < num;i++){
        scanf("%lf", &arr[i]);
        if(arr[i] > maxi) maxi = arr[i];
    }
    double newArr[num];

    for(int i = 0;i < num;i++){
        newArr[i] = arr[i]/maxi;
        newArr[i] = newArr[i]*100;
    }
    printf("%lf", mean(newArr, num));

}

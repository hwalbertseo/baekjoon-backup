#include <iostream>
#include <cstdio>
#include <algorithm>
#include <functional>

using namespace std;

int findMax(int k, int arr[], int sol){
    int res = 0;
    int temps = sol;
    int len = sizeof(arr);

    while(res==k){
        int div = 0;
        for(int i = 0;i < len;i++){
            div += arr[i]/temps;
        }
        //printf("res: %d\n", res);
        res = div;
        temps++;
    }
    return temps;
}

int rec(int k, int arr[], int st, int en){
    int mid = st+en;
    mid = mid/2;
    int len = sizeof(arr);
    int sum = 0;
    for(int i = 0;i < len;i++){
        //printf("sum: %d, add: %d\n", mid,(int)arr[i]/mid);
        sum = sum + ((int)arr[i]/mid);
    }
    //printf("sum: %d\n", sum);
    if(sum == k) return findMax(k, arr, mid);
    else if(sum > k){
        return rec(k, arr, mid, en);
    }
    else{
        return rec(k, arr, st, mid);
    }
}


int main()
{
    int n, num;
    scanf("%d %d", &n, &num);
    int arr[n];
    for(int i = 0;i < n;i++){
        scanf("%d",&arr[i]);
    }
    sort(arr, arr+n, greater<int>());
    printf("%d", rec(num, arr, 0, arr[0]));
}

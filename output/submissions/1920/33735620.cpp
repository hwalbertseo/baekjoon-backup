#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int arr[100001];

void Solution(int n, int key){

    int strt = 0;
    int fin = n-1;
    int mid;

    while(fin - strt >= 0){
        mid = (strt + fin)/2;

        if(arr[mid] == key){
            printf("1\n");
            return;
        }else if(arr[mid] > key){
            fin = mid-1;
        }
        else{
            strt = mid+1;
        }
    }
    printf("0\n");
    return;
}

int main()
{
    int n, m, tmp;

    scanf("%d", &n);

    for(int i = 0;i < n;i++){
        scanf("%d",&arr[i]);
    }

    sort(arr, arr+n);

    scanf("%d", &m);

    for(int i = 0;i < m;i++){
        scanf("%d",&tmp);
        Solution(m, tmp);
    }

    return 0;
}

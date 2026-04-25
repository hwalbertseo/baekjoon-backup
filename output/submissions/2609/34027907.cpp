#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
    vector<int> v;
    vector<int> vn;
    vector<int> vm;
    int n, m, big, sml;
    int G, L;
    scanf("%d %d", &n, &m);
    if(n<m) {big = m; sml = n;}
    else {big = n;sml = m;}

    for(int i = 2;i <= sml;i++){
        if(big % i == 0 && sml % i == 0){
            big = big / i;
            sml = sml / i;
            v.push_back(i);
            i = i - 1;
        }
    }
    G=1;
    for(int i = 0;i < v.size();i++){
        G *= v.at(i);
    }

    if(n<m) {big = m; sml = n;}
    else {big = n;sml = m;}
    for(int i = 2;i <= big;i++){
        //printf("%d", i);
        if(big % i == 0 && sml % i == 0){
            big = big / i;
            sml = sml / i;
            i = i - 1;
            continue;
        }else{
            int flag = 0;
            if(big % i == 0){
                big = big / i;
                vn.push_back(i);
                flag = 1;
            }
            if(sml % i == 0){
                sml = sml / i;
                vm.push_back(i);
                flag = 1;
            }
            if(flag == 1) i = i - 1;
        }
    }
    L=1;
    /*
    printf("\nv: ");
    for(int i = 0;i < v.size();i++){
        printf("%d ", v.at(i));
    }
    printf("\nvn: ");
    for(int i = 0;i < vn.size();i++){
        printf("%d ", vn.at(i));
    }
    printf("\nvm: ");
    for(int i = 0;i < vm.size();i++){
        printf("%d ", vm.at(i));
    }

    */
    for(int i = 0;i < v.size();i++){
        L *= v.at(i);
    }
    for(int i = 0;i < vn.size();i++){
        L *= vn.at(i);
    }
    for(int i = 0;i < vm.size();i++){
        L *= vm.at(i);
    }
    //printf("\n");

    printf("%d %d", G, L);

}

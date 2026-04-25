#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
    int cnt[26] = {0,};
    //a == 97, A == 65
    string inp;
    getline(cin, inp);
    for(int i = 0;i < inp.size();i++){
        int temp = (int)inp[i];
        if(temp >= 97){
            temp = temp - 32;
        }
        cnt[temp - 65]++;
    }
    int maxi, alph;
    maxi=0;
    int flag = 0;
    for(int i = 0;i < 26;i++){
        //printf("%d ", cnt[i]);
        if(cnt[i] > maxi){
            maxi = cnt[i];
            alph = i+65;
            flag = 0;
        }
        else if(cnt[i] == maxi) {
            flag = 1;
        }

    }
    if(flag == 1) printf("?");
    else printf("%c", alph);
}

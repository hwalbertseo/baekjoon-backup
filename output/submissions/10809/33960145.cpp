#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    string inp;
    getline(cin, inp);
    int num[26];
    for(int i = 0;i < 26;i++) num[i] = -1;
    for(int i = 0;i < inp.size();i++){
        int temp = (int)inp[i] - 97;
        if(num[temp] == -1) num[temp] = i;
    }
    for(int i = 0;i < 26;i++) printf("%d ", num[i]);
}

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
    string inp;
    getline(cin,inp);
    //cout << inp << endl;
    int length = inp.size();
    //printf("%d\n", length);
    int spaces = 1;
    for(int i = 0;i < length;i++){
        if(inp[i] == ' '){
            spaces++;
        }
    }
    if(inp[0] == ' ') spaces--;
    if(inp[length-1] == ' ') spaces--;
    printf("%d", spaces);
}

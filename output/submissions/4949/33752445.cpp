#include <iostream>
#include <stdio.h>
#include <stack>
#include <algorithm>

using namespace std;

int main()
{
    string inp[10001];
    int inpLen = 0;
    for(int i = 0;;i++){
        getline(cin, inp[i]);
        if(inp[i] == ".") {
            //printf("%d\n", i);
            inpLen = i;
            break;
        }
    }
    //printf("%d\n", inpLen);
    for(int j = 0;j < inpLen;j++){
        int flag = 0;

        stack<char> s;
        for(int i = 0;i < inp[j].size();i++){

            if(inp[j][i] == '(' || inp[j][i] == '[') {
                s.push(inp[j][i]);
            }
            if(inp[j][i] == ')') {
                if(s.empty()==true ){
                    printf("no\n");
                    flag = 1;
                    break;
                }
                char temp = s.top();
                //printf("%c", temp);
                if(temp == '(') {
                    s.pop();
                    continue;
                }
                else {
                    printf("no\n");
                    flag = 1;
                    break;
                }
            }
            if(inp[j][i] == ']') {
                if(s.empty()==true ){
                    printf("no\n");
                    flag = 1;
                    break;
                }
                char temp = s.top();
                if(temp == '[') {
                    s.pop();
                    continue;
                }
                else {
                    printf("no\n");
                    flag = 1;
                    break;
                }
            }
        }
        if(flag == 0 && s.empty() == true) printf("yes\n");
    }
}

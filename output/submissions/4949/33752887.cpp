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
            inpLen = i;
            break;
        }
    }
    for(int j = 0;j < inpLen;j++){
        int flag = 0;

        stack<char> s;
        for(int i = 0;i < inp[j].size();i++){

            if(inp[j][i] == '(' || inp[j][i] == '[') {
                s.push(inp[j][i]);
            }
            else if(inp[j][i] == ')') {
                if(s.empty()){
                    printf("no\n");
                    flag = 1;
                    break;
                }
                char temp = s.top();
                if(temp == '(') {
                    s.pop();
                }
                else {
                    printf("no\n");
                    flag = 1;
                    break;
                }
            }
            else if(inp[j][i] == ']') {
                if(s.empty()){
                    printf("no\n");
                    flag = 1;
                    break;
                }
                char temp = s.top();
                if(temp == '[') {
                    s.pop();
                }
                else {
                    printf("no\n");
                    flag = 1;
                    break;
                }
            }
        }

        if(flag == 0) {
            if(s.empty()) printf("yes\n");
            else printf("no\n");
        }
    }
}

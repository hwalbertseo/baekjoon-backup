#include <iostream>
#include <stack>

using namespace std;

stack<char> s;

int main()
{
    string str;
    cin >> str;
    int bef = -1;
    for(int i = 0;i < str.size();i++){
        char cur = str[i];
        if(cur >= 'A' && cur <= 'Z'){
            cout << cur;
        }
        else{
            if(s.empty()){
                s.push(cur);
                continue;
            }
            if(cur == '('){
                s.push(cur);
            }
            else if(cur == ')'){
                while(s.top() != '('){
                    cout << s.top();
                    s.pop();
                }
                s.pop();
            }
            else if(cur == '*' || cur == '/'){
                while(s.top() != '+' && s.top() != '-' && s.top() != '('){
                    cout << s.top();
                    s.pop();
                    if(s.empty()){
                        break;
                    }
                }
                s.push(cur);
            }
            else{
                while(s.top() != '('){
                    cout << s.top();
                    s.pop();
                    if(s.empty()){
                        break;
                    }
                }
                s.push(cur);
            }
        }
    }
    while(!s.empty()){
        cout << s.top();
        s.pop();
    }
}

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    int num;
    cin >> num;
    string arr[num];
    //getline(cin);
    for(int i = 0;i < num;i++){
        cin >> arr[i];
    }

    for(int i = 0;i < num;i++){
        int flag = 0;
        stack<int> s;
        for(int j = 0;j < arr[i].size();j++){
            if(arr[i][j] == '('){
                s.push(0);
            }
            else if(arr[i][j] == ')'){
                if(s.empty()) {
                    cout << "NO" << "\n";
                    flag = 1;
                    break;
                }
                s.pop();
            }
        }
        if(s.empty() && flag == 0){
            cout << "YES" << "\n";
        }
        else if(!s.empty() && flag == 0)
            cout << "NO" << "\n";
    }
}

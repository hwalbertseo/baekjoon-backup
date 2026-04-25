#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int num;
    cin >> num;
    stack<int> s;
    for(int i = 0;i < num;i++){
        int temp;
        cin >> temp;
        if(temp == 0){
            s.pop();
        }
        else{
            s.push(temp);
        }
    }
    int sum = 0;
    while(!s.empty()){
        sum += s.top();
        s.pop();
    }
    cout << sum;
}

#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int num, turn;
    cin >> num >> turn;
    queue<int> q;
    for(int i = 1;i<= num;i++){
        q.push(i);
    }
    cout << "<";
    while(!q.empty()){
        for(int i = 1;i < turn;i++){
            q.push(q.front());
            q.pop();
        }
        cout << q.front();
        q.pop();
        if(!q.empty()) cout << ", ";
    }
    cout << ">";
}

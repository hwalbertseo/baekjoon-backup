#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main()
{
    int num;
    cin >> num;
    stack<int> rising; //오름차순으로 정리한거.
    stack<int> s; //넣을 거.
    queue<char> q;
    bool ver = true;
    int arr[num];
    for(int i = num;i > 0;i--){
        rising.push(i);
    }
    for(int i = 0;i<num;i++){
        cin >> arr[i];
    }
    int j = 1;
    int arrn = 0;
    while(s.empty() && arrn < num){
        //cout << "in\n";
        for(;j <= arr[arrn];j++){
                s.push(rising.top());
                q.push('+');
                rising.pop();
        }
        s.pop();
        q.push('-');
        arrn++;
        //cout << arrn << " arrn \n";
    }
    for(int i = arrn;i < num && !s.empty();i++){
        //cout << "h\n";
        if(arr[i] < s.top()){
            //cout << "1\n";
            ver = false;
            break;
        }
        else if(arr[i] == s.top()){
            //cout << "2\n";
            s.pop();
            q.push('-');
        }
        else if(arr[i] > s.top()){
            //cout << "3\n";
            for(;j <= arr[i];j++){
                //cout << "4\n";
                s.push(rising.top());
                q.push('+');
                rising.pop();
            }
            s.pop();
            q.push('-');
        }
    }
    if(!ver) cout << "NO";
    else{
        while(!q.empty()){
            cout << q.front() << "\n";
            q.pop();
        }
    }
}

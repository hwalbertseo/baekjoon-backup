#include <iostream>
#include <stack>

using namespace std;

int arr[500005];

int main()
{
    int n;
    cin >> n;
    stack<pair<int, int>> s;
    arr[0] = 2147483647;
    for(int i = 1;i <= n;i++){
        cin >> arr[i];
    }
    for(int i = 0;i <= n;i++){
        s.push({i, arr[i]});
    }
    int i = n-1;
    while(s.size() > 1){
        stack<pair<int, int>> temp;
        temp = s;
        temp.pop();
        while(temp.size() > 0){
            if(temp.top().second > s.top().second){
                arr[i--] = temp.top().first;
                break;
            }
            temp.pop();
        }
        s.pop();
    }

    for(i = 0;i < n;i++){
        cout << arr[i] << " ";
    }
}

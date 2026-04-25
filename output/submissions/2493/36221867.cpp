#include <iostream>
#include <stack>

using namespace std;

int arr[500005];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    stack<int> s;
    s.push(2147483647);
    for(int i = 1;i <=n;i++){
        int temp;
        cin >> temp;
        stack<int> t = s;
        int j = i-1;
        while(t.size() != 0){
            if(t.top() >= temp){
                arr[i-1] = j;
                break;
            }
            t.pop();
            j--;
        }
        s.push(temp);
    }
    for(int i = 0;i < n;i++){
        cout << arr[i] << " ";
    }
}

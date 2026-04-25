#include <iostream>
#include <stack>

using namespace std;

int arr[500005];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    stack<pair<int, int>> s;
    for(int i = 1;i <= n;i++){
        int temp;
        cin >> temp;
        while(s.size() >= 0){
            //cout << s.size();
            if(s.empty()) {
                arr[i] = 0;
                //cout << temp <<endl;
                break;
            }
            else if(s.top().second >= temp){
                arr[i] = s.top().first;
                break;
            }
            else{
                s.pop();
            }
        }
        s.push({i, temp});
    }
    for(int i = 1;i <= n;i++){
        cout << arr[i] << " ";
    }
}

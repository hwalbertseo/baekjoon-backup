#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    string arr[n];
    map<string, int> index;
    for(int i = 0;i < n;i++){
        cin >> arr[i];
        index.insert(pair<string, int>(arr[i], i));
    }
    for(int i = 0;i < m;i++){
        string temp;
        cin >> temp;
        if(temp[0] >= '0' && temp[0] <= '9'){
            int k = stoi(temp);
            cout << arr[k-1] << "\n";
        }
        else{
            cout << index[temp]+1 << "\n";
        }

    }
}

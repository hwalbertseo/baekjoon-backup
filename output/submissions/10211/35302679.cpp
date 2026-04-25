#include <iostream>

using namespace std;

int arr[1005];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int num;
    cin >> num;
    int maxnum = -1;
    for(int i = 0;i<num;i++){
        //cout << "hello\n";
        int len;
        cin >> len;
        maxnum = -1;
        for(int j = 1;j <= len;j++){
            int temp;
            cin >> temp;
            arr[j] = arr[j-1] + temp;
            for(int k = 0;k < j;k++){
                int h = arr[j] - arr[k];
                if(h > maxnum) maxnum = h;
            }
        }
        cout << maxnum << "\n";
    }
}

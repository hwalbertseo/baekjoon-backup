#include <iostream>

using namespace std;

int arr[1001];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int num;
    cin >> num;
    for(int i = 0;i<num;i++){
        //cout << "hello\n";
        int len;
        int maxnum = -1;
        cin >> len;
        for(int j = 1;j <= len;j++){
            int temp;
            cin >> temp;
            arr[j] = arr[j-1] + temp;
            if(arr[j] > maxnum){
                maxnum = arr[j];
                //cout << "maxnum" << maxnum << "\n";
            }
        }
        for(int j = 1;j <= len;j++){
            int temp;
            temp = maxnum-arr[j-1];
            if(temp > maxnum){
                maxnum = temp;
                //cout << "maxnum" << maxnum << "\n";
            }
        }
        cout << maxnum << "\n";
    }
}

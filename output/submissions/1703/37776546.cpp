#include <iostream>
#include <algorithm>

using namespace std;

int arr[100005];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    while(1){
        int n;
        cin >> n;
        if(n == 0){
            break;
        }
        else{
            int leaves = 1;
            for(int i = 0;i < n;i++){
                int p, q;
                cin >> p >> q;
                leaves *= p;
                leaves -= q;
            }
            cout << leaves << "\n";
        }
    }
}

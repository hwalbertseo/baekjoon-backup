#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int m = 0;
    int n = 0;
    int tell = -1;
    cin >> m;
    for(int i = 1;i < 8;i++){
        cin >> n;
        if(tell == -1){
            if(n > m){
                tell = 1;
            }
            else{
                tell = 0;
            }
        }
        else{
            if(tell == 2){
                continue;
            }
            else if(tell == 1){
                if(n < m){
                    tell = 2;
                }
            }
            else{
                if(n > m){
                    tell = 2;
                }
            }
        }
        m = n;
    }
    if(tell == 2){
        cout << "mixed";
    }
    else if(tell == 1){
        cout << "ascending";
    }
    else if(tell==0){
        cout << "descending";
    }
}

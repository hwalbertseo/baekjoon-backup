#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int BIT = 0;
    string str;
    int num;
    cin >> num;
    for(int i = 0;i < num;i++){
        cin >> str;
        int n;
        if(str == "add"){
            cin >> n;
            BIT |= (1 << n);
        }
        else if(str == "remove"){
            cin >> n;
            BIT &= ~(1 << n);
        }
        else if(str == "check"){
            cin >> n;
            if((1 << n) & BIT){
                cout << 1 << "\n";
            }
            else{
                cout << 0 << "\n";
            }
        }
        else if(str == "toggle"){
            cin >> n;
            BIT ^= (1 << n);
        }
        else if(str == "all"){
            BIT |= ~0;
        }
        else if(str == "empty"){
            BIT &= 0;
        }
    }
    // 0001 ^ 1011 == 1010
}

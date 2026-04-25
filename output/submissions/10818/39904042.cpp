#include <iostream>
 
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    int mi = 1e9, ma= -1e9;
    cin >> n;
    for(int i = 0;i < n;i++){
        int p;
        cin >> p;
        if(p > ma){
            ma = p;
        }
        if(p < mi){
            mi = p;
        }
    }
    cout << mi << " " << ma;
}
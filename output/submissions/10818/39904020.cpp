#include <iostream>
 
using namespace std;

int main(){
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
#include <iostream>

using namespace std;

int main(){
    int p, q;
    cin >> p >> q;
    if(p > 0){
        if(q > 0){
            cout << 1;
        }
        else{
            cout << 4;
        }
    }
    else{
        if(q > 0){
            cout << 2;
        }
        else{
            cout << 3;
        }
    }
    
}
#include <iostream>
#include <cstdio>

using namespace std;

int selectBest(){

}

int main()
{
    int h, m;
    cin >> h >> m;
    if(m >= 45){
        cout << h << " " << m-45;
    }
    else{
        if(h != 0){
            cout << h-1 << " " << 15+m;
        }
        else{
            cout << 23 << " " << 15+m;
        }
    }
}

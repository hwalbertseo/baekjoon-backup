#include <iostream>

using namespace std;

int add(int p){
    int temp = (p+1)*p;
    temp = temp/2;
    return temp;
}

int main()
{
    int n;
    cin >> n;
    int time = 0;
    for(int i = 1;n > 0;i++){
        //cout << "i: " << i << " " << n << endl;
        if(n < i){
            i = 0;
            continue;
        }
        n = n-i;
        time++;
    }
    cout << time;
}

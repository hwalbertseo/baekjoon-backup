#include <iostream>

using namespace std;

int arr[500];
int n;
int maxscore = 0;

void step(int x, int s, int cont){
    if(cont >= 3){
        return;
    }
    if(x >= n){
        return;
    }
    int price;
    if(x == 0){
        price = arr[0];
    }
    else{
        price = s+arr[x];
    }
    if(price > maxscore){
        maxscore = price;
    }
    step(x+1, price, cont+1);
    step(x+2, price, 1);
}

int main()
{
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    step(0, 0, 1);
    cout << maxscore;
}

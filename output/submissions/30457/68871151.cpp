#include <iostream>

using namespace std;

int arr[10000];

int main(){
    int n;
    cin >> n;
    int total = n;
    for(int i = 0;i < n;i++){
        int p;
        cin >> p;
        arr[p] += 1;
        if(arr[p] > 2){
            total -= 1;
        }
    }
    cout << total;
}
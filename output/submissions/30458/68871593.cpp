#include <iostream>
#include <stdio.h>

using namespace std;

int arr[200];

int main(){
    int n;
    string s;
    cin >> n;
    cin >> s;
    for(int i = 0;i < n;i++){
        char c = s[i];
        arr[c] += 1;
    }
    int odd = 0;
    for(int i = 'a';i <= 'z';i++){
        //cout << arr[i] << " ";
        if(arr[i] % 2 == 1){
            odd += 1;
        }
    }
    if(odd > 1){
        cout << "No";
    }
    else{
        cout << "Yes";
    }
}
#include <iostream>

using namespace std;

long long arr[50005];

int main()
{
    int num;
    cin >> num;
    int largest = 0;
    for(int i = 1;i <= num;i++){
        int ps;
        cin >> ps;
        arr[i] = arr[i-1] + ps;
        for(int j = 0;j < i;j++){
            long long h = arr[i]-arr[j];
            if(h%7 == 0 && h != 0){
                if(i-j > largest){
                    largest = i-j;
                }
            }
        }
    }
    cout << largest;
}

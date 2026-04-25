#include <iostream>
#include <algorithm>

using namespace std;

int arr[10];

int main()
{
    for(int i = 0;i < 9;i++){
        cin >> arr[i];
    }
    int idx;
    int m = 0;
    for(int i = 0;i < 9;i++){
        if(m < arr[i]){
            idx = i;
            m = arr[i];
        }
    }
    cout << m << "\n";
    cout << idx+1;
}

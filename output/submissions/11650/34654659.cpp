#include <iostream>
#include <algorithm>

using namespace std;

struct coo{
    int x;
    int y;
};

bool compare(coo a, coo b){
    if(a.x == b.x){
        return a.y < b.y;
    }
    else {
        return a.x < b.x;
    }
}

int main()
{
    int num;
    cin >> num;
    coo arr[num];
    for(int i = 0;i < num;i++){
        cin >> arr[i].x >> arr[i].y;
    }
    sort(arr, arr+num, compare);
    for(int i = 0;i < num;i++){
        cout << arr[i].x << " " << arr[i].y << "\n";
    }
}

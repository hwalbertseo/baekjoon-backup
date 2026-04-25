#include <iostream>

using namespace std;

unsigned int arr[272145][20];
int n = 10;
int tpow[19];

void press(int i, int j, int r){
    if(arr[i][j-1] & (1<<(r))){
        arr[i][j-1] &= ~(1<<(r));
    }
    else{
        arr[i][j-1] |= (1<<(r));
    }
    if(r > 0){
    //j, r-1
        if(arr[i][j] & (1<<(r-1))){
            arr[i][j] &= ~(1<<(r-1));
        }
        else{
            arr[i][j] |= (1<<(r-1));
        }
    }
    //j, r
    if(arr[i][j] & (1<<(r))){
        arr[i][j] &= ~(1<<(r));
    }
    else{
        arr[i][j] |= (1<<(r));
    }
    //j, r+1
    if(arr[i][j] & (1<<(r+1))){
        arr[i][j] &= ~(1<<(r+1));
    }
    else{
        arr[i][j] |= (1<<(r+1));
    }
    //j+1, r
    if(j < n-1){
        if(arr[i][j+1] & (1<<(r))){
            arr[i][j+1] &= ~(1<<(r));
        }
        else{
            arr[i][j+1] |= (1<<(r));
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    tpow[0] = 1;
    for(int i = 1;i < 19;i++){
        tpow[i] = tpow[i-1]*2;
    }
    cin >> n;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            int p = 0;
            cin >> p;
            if(p == 0){
                for(int r = 0;r < tpow[n]+1;r++) arr[r][i] &= ~(1<<j);
            }
            else{
                for(int r = 0;r < tpow[n]+1;r++) arr[r][i] |= (1<<j);
            }
        }
    }
    /*
    for(int i = 0;i < 24;i++){
        cout << arr[i][0] << endl;
    }
    */
    //cout << "cont";
    int ans = 2e9;
    for(int i = 0;i < tpow[n];i++){
        int changed = 0;
        for(int j = 0;j < n;j++){
            if(i & (1<<j)){
                changed += 1;
                press(i, 0, j);

            }
        }
        //cout << i << endl;
/*
        if(i == 0)
        for(int j = 0;j < n;j++){
            for(int r = 0;r < n;r++){
                cout << bool(arr[i][j] & (1<<r)) << " ";
            }
            cout << endl;
        }
        cout << endl;
*/

        for(int j = 1;j < n;j++){
            for(int r = 0;r < n;r++){
                if (arr[i][j-1] & (1<<r)){
                    changed += 1;
                    press(i, j, r);
                }
/*
                if(i == 683){

        for(int j = 0;j < n;j++){
            for(int r = 0;r < n;r++){
                cout << bool(arr[i][j] & (1<<r)) << " ";
            }
            cout << endl;
        }
        cout << endl;}
*/
            }
        }
        bool done = true;
        //if(i == 1)
        for(int j = 0;j < n;j++){
            for(int r = 0;r < n;r++){
                //cout << bool(arr[i][j] & (1<<r)) << " ";
                if(arr[i][j] & (1<<r)){
                    done = false;
                }
            }
            //cout << endl;
        }
        if(done){
            if(changed < ans){
                //cout << i << "\n";
                ans = changed;
            }
        }
        //cout << done << " " << i << " " << changed << endl;
    }
    if(ans == 2e9){
        ans = -1;
    }
    cout << ans;
}

/*
18
1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
*/

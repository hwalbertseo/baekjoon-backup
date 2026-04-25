#include <iostream>
#include <string.h>

using namespace std;

int df[10000][10000];
string a, b;

string dfs(int i, int j){
    if(i == 0 || j == 0){
        return "";
    }
    //cout << df[i][j] << "\n";
    
    if(df[i][j] == df[i-1][j]){
        return dfs(i-1, j);
    }
    else if(df[i][j] == df[i][j-1]){
        return dfs(i, j-1);
    }
    else{
        return dfs(i-1, j-1) + a[i-1];
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> a;
    cin >> b;
    for(int i = 1;i <= a.length();i++){
        for(int j = 1;j <= b.length();j++){
            //cout << a[i-1] << " " << b[j-1] << "\n";
            if(a[i-1] == b[j-1]){
                df[i][j] = df[i-1][j-1]+1;
            }
            else{
                df[i][j] = max(df[i-1][j], df[i][j-1]);
            }
        }
    }
    /*
    for(int i = 1;i <= a.length();i++){
        for(int j = 1;j <= b.length();j++){
            cout << df[i][j] << " ";
        }
        cout << "\n";
    }
    */
    cout << df[a.length()][b.length()] << "\n" << dfs(a.length(), b.length());
}
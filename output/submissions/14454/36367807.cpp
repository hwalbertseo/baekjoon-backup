#include <iostream>
#include <string>

long long a;

using namespace std;

long long maximize(string inp){
    int len = inp.size();
    while(len <= a){
        len = len*2;
    }
    return len;
}

long long reduce(int l, long long maxed){
    int len = maxed;
    int n = a;
    while(n >= l){
        if(n!= len/2){
            long long sub = len-n;
            n = len/2 - sub - 1;
        }
        else{
            n--;
        }
        len /= 2;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    string inp;
    cin >> inp >> a;
    a--;
    long long maxed = maximize(inp);
    int ans = reduce(inp.size(), maxed);
    cout << inp[ans];
}

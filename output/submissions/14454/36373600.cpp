#include <iostream>
#include <string>

using namespace std;

long long a;

long long maximize(string inp){
    long long len = inp.size();
    while(len <= a){
        //cout << "doubling" << endl;
        len = len << 1;
        //cout << len << "\n";
    }
    //cout << "comp1" << endl;
    return len;
}

long long reduce(int l, long long maxed){
    int len = maxed;
    int n = a;
    while(n >= l){
        //cout << n << " " << len << endl;
        if(n != len/2){
            long long sub = len-n;
            n = len/2 - sub - 1;
        }
        else{
            n--;
        }
        while(n < len){
            len /= 2;
        }
        len *= 2;
    }
    //cout << "comp2" << endl;
    return n;
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

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a;
    getline(cin, a);
    string s = a.substr(4);
    if(s == "hello"){
        cout << "YES";
    }
    else {
        cout << "NO";
    }
}

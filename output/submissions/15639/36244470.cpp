#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a;
    getline(cin, a);
    if(a == "Give you up"){
        cout << "NO";
    }
    else if(a == "Let you down"){
        cout << "NO";
    }
    else if(a == "Run around and desert you"){
        cout << "NO";
    }
    else if(a == "Make you cry"){
        cout << "NO";
    }
    else if(a == "Say goodbye"){
        cout << "NO";
    }
    else if(a == "Tell a lie and hurt you"){
        cout << "NO";
    }
    else{
        cout << "YES";
    }
}

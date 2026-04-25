#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int k = 0;
    vector<int> arr;
    for(int i = 0;;i++){
        stringstream sstream;
        sstream << i;
        string temp = sstream.str();
        //cout << temp << endl;
        for(int j = 2;j < temp.length();j++){
            //cout << typeid(temp.at(j-1)).name() << endl;
            if(temp.at(j-2) == '6' && temp.at(j-1) == '6' && temp.at(j) == '6'){
                //cout << "p";
                arr.push_back(i);
                break;
            }
        }
        //cout << arr.size();
        if(arr.size() == n){
            break;
        }
    }
    cout << arr.at(n-1);
}

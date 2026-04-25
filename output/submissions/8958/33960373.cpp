#include <iostream>
#include <cstdio>

using namespace std;

int score(string x){
    int sum = 0;
    int add = 0;
    for(int i = 0;i < x.size();i++){
        if(x[i] == 'X') {
            add = 0;
            continue;
        }
        else if(x[i] == 'O'){
            add++;
            sum += add;
        }
    }
    return sum;
}

int main()
{
    int num = 0;
    scanf("%d", &num);
    string inp;
    for(int i = -1;i < num;i++){
        getline(cin, inp);
        printf("%d\n", score(inp));

    }


}

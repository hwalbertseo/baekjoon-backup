#include <iostream>

using namespace std;

int main()
{
    int b1, b2;
    int d1, d2;
    int j1, j2;

    cin >> b1 >> b2;
    cin >> d1 >> d2;
    cin >> j1 >> j2;

    int turn1 = 0;
    while(!(j1 == b1 && j2 == b2)){
        if(j1 == b1){
            if(b2 < j2){
                b2++;
                turn1++;
            }
            else{
                b2--;
                turn1++;
            }
        }
        else if(j2 == b2){
            if(b1 < j1){
                b1++;
                turn1++;
            }
            else{
                b1--;
                turn1++;
            }
        }
        else{
            if(j1 > b1 && j2 > b2){
                b1++;
                b2++;
                turn1++;
            }
            else if(j1 > b1 && j2 < b2){
                b1++;
                b2--;
                turn1++;
            }
            else if(j1 < b1 && j2 > b2){
                b1--;
                b2++;
                turn1++;
            }
            else if(j1 < b1 && j2 < b2){
                b1--;
                b2--;
                turn1++;
            }
        }
    }
    int turn2 = 0;
    while(!(j1 == d1 && j2 == d2)){
        if(j1 == d1){
            if(d2 < j2){
                d2++;
                turn2++;
            }
            else{
                d2--;
                turn2++;
            }
        }
        else if(j2 == d2){
            if(d1 < j1){
                d1++;
                turn2++;
            }
            else{
                d1--;
                turn2++;
            }
        }
        else{
            if(j1 > d1){
                d1++;
                turn2++;
            }

            else if(j1 < d1){
                d1--;
                turn2++;
            }
        }
    }
    if(turn1 == turn2){
        cout << "tie";
    }
    else if(turn1 < turn2){
        cout << "bessie";
    }
    else{
        cout << "daisy";
    }
}

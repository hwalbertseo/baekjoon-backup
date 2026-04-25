#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int num;
    cin >> num;
    int sumH[100005] = {0,};
    int sumS[100005] = {0,};
    int sumP[100005] = {0,};
    for(int i = 1;i <= num;i++){
        char temp;
        cin >> temp;
        if(temp == 'S') {
            sumH[i] = sumH[i-1] + 1;
            sumS[i] = sumS[i-1];
            sumP[i] = sumP[i-1];
        }
        else if(temp == 'P') {
            sumH[i] = sumH[i-1];
            sumS[i] = sumS[i-1] + 1;
            sumP[i] = sumP[i-1];
        }
        else if(temp == 'H') {
            sumH[i] = sumH[i-1];
            sumS[i] = sumS[i-1];
            sumP[i] = sumP[i-1] + 1;
        }
    }
    int maxsum = 0;
    maxsum = (sumH[num] > sumS[num]) ? sumH[num] : sumS[num];
    //cout << sumP[0];
    maxsum = (sumP[num] > maxsum) ? sumP[num] : maxsum;
    for(int i = 1;i < num;i++){
        int temp1, temp2;
        int chH, chS, chP;
        chH = sumH[num] - sumH[i+1];
        chP = sumP[num] - sumP[i+1];
        chS = sumS[num] - sumS[i+1];
        temp1 = (sumH[i] > sumS[i]) ? sumH[i] : sumS[i];
        temp1 = (sumP[i] > temp1) ? sumP[i] : temp1;
        temp2 = (sumH[num] - sumH[i] > sumS[num] - sumS[i]) ? sumH[num] - sumH[i] : sumS[num] - sumS[i];
        temp2 = (sumP[num] - sumP[i] > temp2) ? sumP[num] - sumP[i] : temp2;
        //cout << temp1 << " " << temp2 << endl;
        maxsum = (maxsum > temp1+temp2) ? maxsum : temp1+temp2;
    }
    cout << maxsum;
}

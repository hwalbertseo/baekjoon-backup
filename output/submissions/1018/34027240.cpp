#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int main()
{
    string ex1[8] = {
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
    };
    string ex2[8] = {
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
    };
    int n, m;
    scanf("%d %d", &n, &m);
    char arr[n][m];
    cin >> ws;
    for(int i = 0;i < n;i++){
        string temp;
        getline(cin, temp);
        for(int j = 0;j < m;j++){
            arr[i][j] = temp[j];
        }
    }
    int minCnt = 999999;
    for(int i = 0;i <= n-8;i++){
        for(int j = 0;j <= m-8;j++){
            int cnt1 = 0;
            int cnt2 = 0;
            for(int p = 0;p < 8;p++){
                for(int q = 0;q < 8;q++){
                    if(arr[i+p][j+q] != ex1[p][q]){
                        cnt1++;
                    }
                    if(arr[i+p][j+q] != ex2[p][q]){
                        cnt2++;
                    }
                }
            }
            if(cnt1 <= cnt2 && cnt1 < minCnt){
                minCnt = cnt1;
            }
            else if(cnt2 <= cnt1 && cnt2 < minCnt){
                minCnt = cnt2;
            }
        }
    }
    printf("%d", minCnt);
}

/*
8 8
WBWBWBWB
BWBWBWBW
WBWBWBWB
BWBBBWBW
WBWBWBWB
BWBWBWBW
WBWBWBWB
BWBWBWBW
*/

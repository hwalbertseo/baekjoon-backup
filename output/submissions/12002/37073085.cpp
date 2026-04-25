#include <iostream>
#include <algorithm>

using namespace std;

struct coo{
    int x;
    int y;
};

coo arr[50005];
int coox[50005];
int cooy[50005];

int main()
{
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        int p, q;
        cin >> p >> q;
        arr[i] = {p, q};
        coox[i] = p;
        cooy[i] = q;
    }
    sort(coox, coox+n);
    sort(cooy, cooy+n);
    int mincoo = 2e9;
    for(int i = 0;i <= 3;i++){
        for(int j = 0;j <= 3;j++){
            for(int r = n-1;r > n-4;r--){
                for(int w = n-1;w>n-4;w--){
                    int x1 = coox[i];
                    int y1 = cooy[j];
                    int x2 = coox[r];
                    int y2 = cooy[w];
                    if(x1 >= x2 || y1 >= y2){
                        continue;
                    }
                    int outsidecnt = 0;
                    for(int k = 0;k < n;k++){
                        if(arr[k].x < x1){
                            outsidecnt++;
                        }
                        else if(arr[k].x > x2){
                            outsidecnt++;
                        }
                        else if(arr[k].y < y1){
                            outsidecnt++;
                        }
                        else if(arr[k].y > y2){
                            outsidecnt++;
                        }
                    }
                    if(outsidecnt <= 3){
                        int area = (x2-x1) * (y2-y1);
                        if(area < mincoo){
                            mincoo = area;
                        }
                    }
                }
            }
        }
    }
    cout << mincoo;
}

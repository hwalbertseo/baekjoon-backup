#include <iostream>
#include <algorithm>

using namespace std;

int ft[250005];
int fb[250005];
int n, h;

int crash(int mid){
    if(mid < 0 || mid >= h) return 2147483647;
    int l = upper_bound(&fb[0], &fb[n/2], mid) - &fb[0];
    int h = lower_bound(&ft[0], &ft[n/2], mid) - &ft[0]-1;
    //cout << mid << " " << n/2 - lind << " " << fb[lind] << " " << hind<<  " " << ft[hind] << "\n";
    int minnum = (n/2 - l) + (h+1);
    return minnum;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n >> h;
    for(int i = 0;i < n;i++){
        if(i%2 == 0){
            cin >> fb[i/2];
        }
        else{
            cin >> ft[i/2];
            ft[i/2] = h-1-ft[i/2];
        }
    }
    sort(fb, fb+(n/2));
    sort(ft, ft+(n/2));

    int cnt = 0;
    int minnum = 2147483647;
    for(int i = 0;i < h;i++){
        int temp = crash(i);
        if(minnum > temp){
            cnt = 1;
            minnum = temp;
            //cout << "i: " << i << "\n";
        }
        else if(minnum == temp){
            cnt++;
            //cout << "i: "<< i << "\n";
        }
    }
    cout << minnum << " " << cnt;
    /*
    for(int i = 0;i < n/2;i++){
        cout << fb[i] << " ";
    }
    cout << endl;
    for(int i = 0;i < n/2;i++){
        cout << ft[i] << " ";
    }
    cout << endl;


    int top;
    int bot;
    //both cases
    top = h-1;
    bot = fb[n/2];
    int minnum = 2147483647;
    while(bot < top){
        int mid = (top + bot)/2;

    }
    */
}

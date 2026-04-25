#include <iostream>
#include <algorithm>

using namespace std;

int n;
int maxarr[100005];
int minarr[100005];
long long possible = 0;
long long ascending = 0;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    int minlen = 0;
    int maxlen = 0;
    for(int i = 0;i < n;i++){
        int len;
        cin >> len;
        int maxnum = -1;
        int minnum = 2147483647;
        int minind;
        bool isAsc = false;
        for(int j = 0;j < len;j++){
            int temp;
            cin >> temp;
            if(temp < minnum){
                minnum = temp;
                minind = j;
            }
            if(temp >= maxnum){
                maxnum = temp;
            }
            if(temp > minnum && j > minind){
                isAsc = true;
            }
        }
        //cout << "len: " << len << " max: " << maxnum << " min: " << minnum << " ";
        //cout << maxind << " " << minind << endl;
        if(isAsc){
            ascending++;
            continue;
        }
        else {
            maxarr[maxlen++] = maxnum;
            minarr[minlen++] = minnum;
        }
    }
    //cout << ascending << endl;
    possible += ascending*(2*n - 1) - (ascending*(ascending-1));
    //cout << "possible: " << possible << endl;
    sort(maxarr, maxarr+maxlen);
    for(int i = 0;i < minlen;i++){
        int next = minarr[i];
        int ub = upper_bound(&maxarr[0], &maxarr[maxlen], next) - &maxarr[0];
        //cout << "next: " << next << " maxlen: " << maxlen << " ub: " << ub << endl;
        possible += maxlen- ub;
    }
    cout << possible;
}

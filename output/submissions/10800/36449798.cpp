#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

struct ball{
    int index;
    int c;
    int s;
};

ball arr[200002];
int cnt[200002];
int edible[200002];
int stacksize[200002];

bool comp(ball a, ball b){
    return a.s < b.s;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> arr[i].c >> arr[i].s;
        arr[i].index = i;
    }
    sort(arr, arr+n, comp);
    edible[arr[0].index] = 0;
    cnt[arr[0].c] += arr[0].s;
    stacksize[0] = arr[0].s;
    for(int i = 1;i < n;){
        int jcnt = 0;
        int cumulstacksize = 0;
        map<int, int> cumulcolor;
        for(int j = i;;j++){
            edible[arr[j].index] += stacksize[i-1] - cnt[arr[i].c];
            jcnt++;
            cumulstacksize += arr[j].s;
            cumulcolor[arr[j].c] += arr[i].s;
            stacksize[j] = stacksize[j-1] + arr[j].s;
            if(arr[j].s < arr[j+1].s || j == n-1) {
                for(auto it = cumulcolor.begin();it != cumulcolor.end();it++){
                    cnt[it->first] += it->second;
                }
                i+=jcnt;
                break;
            }
        }

    }
    for(int i = 0;i < n;i++){
        cout << edible[i] << "\n";
    }
}

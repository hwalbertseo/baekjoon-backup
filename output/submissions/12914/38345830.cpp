#include <iostream>
#include <set>
#include <algorithm>
#define ll long long

using namespace std;

int want[1005];
int ans[1005];
set<pair<int, int>> s;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, d;
    cin >> n >> d;
    for(int i = 0;i < n;i++){
        cin >> want[i];
    }
    for(int i = 0;i < n;i++){
        bool passed = true;
        int befend = 0;
        int w = want[i];
        int least = -1;
        for(pair<int, int> temp: s){
            int beg = temp.first;
            int fin = temp.second;
            if(w >= beg && w <= fin){
                passed = false;
            }
            if(beg > befend+1){
                if(befend+1 >= want[i]){
                    least = befend+1;
                }
            }
            befend = fin;
        }
        if(passed){
            ans[i] = want[i];
            int dif = d-1;
            s.insert({want[i]-dif, want[i]+dif});
        }
        else{
            if(least != -1){
                ans[i] = least;
                int dif = d-1;
                s.insert({ans[i]-dif, ans[i]+dif});
            }
            else{
                auto temp = s.end();
                temp--;
                ans[i] = (temp->second) + 1;
                int dif = d-1;
                s.insert({ans[i]-dif, ans[i]+dif});
            }
        }
        cout << ans[i] << " ";
    }
}

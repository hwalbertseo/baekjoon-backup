#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

struct cow{
    int s;
    int a;
    int t;
};

bool comp1(cow a, cow b){
    if(a.a == b.a){
        return a.s < b.s;
    }
    else{
        return a.a < b.a;
    }
}

bool comp2(cow a, cow b){
    return a.s < b.s;
}

cow s1[100005];

int main()
{
    //ios_base::sync_with_stdio(false); cin.tie(0);
    int ind = 0;
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        cow p;
        p.s = i;
        cin >> p.a >> p.t;
        s1[i] = p;
    }
    /*
    for(auto it = s.begin();it != s.end();it++){
        cow temp = *it;
        cout << temp.s << " " << temp.a << " " << temp.t << "\n";
    }
    */
    sort(s1, s1+n, comp1);
    set<cow, decltype(&comp2)> s2(&comp2);
    long long maxwait = -1;
    long long enttime = 0;
    long long endtime = 0;

    while(!s2.empty() || ind < n){
        //cout<< "size: " << s1.size() << "\n";
        enttime = endtime;
        if(s2.empty()){
            s2.insert(s1[ind]);
            ind++;
            enttime = s2.begin()->a;
        }
        //cout << "2";
        cow temp = *(s2.begin());
        s2.erase(s2.begin());
        endtime = enttime + temp.t;
        long long time = enttime - temp.a;
        if(time > maxwait){
            //cout << temp.s << "\n";
            maxwait = time;
        }
        //cout << "3";
        for(;ind < n;){
            //cout << "loop";
            if(s1[ind].a < endtime){
                s2.insert(s1[ind]);
                ind++;
            }
            else{
                break;
            }
        }
        //cout << "4\n";
    }
    cout << maxwait;
}

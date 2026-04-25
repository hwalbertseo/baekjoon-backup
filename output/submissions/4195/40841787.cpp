#include <iostream>
#include <map>

using namespace std;

int n;
int m[200005];
int sz[200005];
map<string, int> idxes;

void init(){
    for(int i = 0;i < 100005;i++){
        m[i] = i;
        sz[i] = 1;
    }
    idxes.clear();
}

int srch(int cur){
    if(m[cur] == cur){
        return cur;
    }
    m[cur] = srch(m[cur]);
    return m[cur];
}

void comb(int a, int b){
    int p = srch(a);
    int q = srch(b);

    if(a == b){
        return;
    }

    m[p] = q;
    sz[q] += sz[p];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int tc;
    cin >> tc;
    int idx = 0;
    for(int ii = 0;ii < tc;ii++){
        init();
        idx = 0;
        cin >> n;
        for(int i = 0;i < n;i++){
            string p, q;
            cin >> p >> q;
            if(idxes.count(p) == 0){
                idxes[p] = idx;
                idx++;
            }
            if(idxes.count(q) == 0){
                idxes[q] = idx;
                idx++;
            }
            int a = idxes[p];
            int b = idxes[q];
            //cout << srch(a) << " " << srch(b) << endl;
            comb(a, b);
            cout << sz[srch(a)] << "\n";
        }
    }
}

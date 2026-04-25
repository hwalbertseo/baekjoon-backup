#include <iostream>

using namespace std;

int n, m, leaf = 1;
int tree[400005];

void construct(){
    for(int i = leaf-1;i > 0;i--){
        tree[i] = tree[i*2] + tree[i*2+1];
    }
}

void update(int place, int num){
    place += leaf-1;
    tree[place] = num;
    for(int i = place/2;i > 0;i /= 2){
        tree[i] = tree[i*2] + tree[i*2+1];
    }
}

int sum(int L, int R, int cur, int Lnode, int Rnode){
    if(R<Lnode || L > Rnode){
        return 0;
    }
    else if(L <= Lnode && Rnode <= R){
        return tree[cur];
    }
    int mid = (Lnode+Rnode)/2;
    return sum(L, R, cur*2, Lnode, mid) + sum(L, R, cur*2+1, mid+1, Rnode);
}

void printtree(){
    cout << "pt: ";
    for(int i = 1;i <= leaf*2;i++){
        cout << tree[i] << " ";
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    while(leaf < n) (leaf <<= 1);
    //cout << leaf <<"\n";
    for(int i = 0;i < n;i++){
        cin >> tree[leaf+i];
    }
    construct();
    for(int i = 0;i < m;i++){
        //printtree();
        int p, q, r, s;
        cin >> p >> q >> r >> s;
        cout << sum(p+leaf-1, q+leaf-1, 1, leaf, leaf*2-1) << "\n";
        update(r, s);
    }
}

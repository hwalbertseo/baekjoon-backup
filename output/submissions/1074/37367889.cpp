#include <iostream>
#define ll long long

using namespace std;

ll n, r, c;
ll quad = 0;

ll pow(ll p, ll q){
    ll num = 1;
    for(ll i = 0;i < q;i++){
        num *= p;
    }
    return num;
}

void num(ll ni, ll qx, ll qy){
    ios_base::sync_with_stdio(false); cin.tie(0);
    if(ni < 1){
        return;
    }
    else{
        ll div = pow(2, ni-1);
        //cout << div << "\n";
        if(r <= qx + div && c <= qy + div){
            num(ni-1, qx, qy);
            return;
        }
        else if(r <= qx + div && c <= qy + div*2){
            quad = quad + div*div;
            num(ni-1, qx, qy + div);
            return;
        }
        else if(r <= qx + div*2 && c <= qy + div){
            quad = quad + div*div*2;
            num(ni-1, qx + div, qy);
            return;
        }
        else{
            quad = quad + div*div*3;
            num(ni-1, qx + div, qy + div);
            return;
        }
    }
}

int main()
{
    //cout << pow(2, 3);
    cin >> n >> r >> c;
    r++; c++;
    num(n, 0, 0);
    cout << quad;
}

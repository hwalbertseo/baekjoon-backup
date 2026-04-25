#include <iostream>
#include <vector>
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;

void print_mat(vector<vector<ll>> inp){
    for(ll i = 0;i < inp.size();i++){
        for(ll j = 0;j < inp[i].size();j++){
            cout << inp[i][j] << " ";
        }
        cout << "\n";
    }
    return;
}

vector<ll> subtract_row(vector<ll> v1, vector<ll> v2){
    // Subtract v1 from v2 and return the results
    // cout << "subtract\n";
    vector<ll> ans;
    for(ll i = 0;i < v1.size();i++){
        ans.push_back(v1[i] - v2[i]);
    }
    return ans;
}

vector<ll> multiply_row(vector<ll> v, ll c){
    // cout << "multiply \n";
    for(ll i = 0;i < v.size();i++){
        v[i] = v[i] * c;
    }
    return v;
}

vector<ll> divide_row(vector<ll> v, ll c){
    // cout << "multiply \n";
    for(ll i = 0;i < v.size();i++){
        v[i] = v[i] / c;
    }
    return v;
}

vector<ll> row_reduce(vector<ll> v1, vector<ll> v2, ll idx){
    // Row-reduce the idx-th number of v2, based on v1.
    ll num_v1 = v1[idx]; ll num_v2 = v2[idx];
    vector<ll> new_v1 = multiply_row(v1, num_v2);
    vector<ll> new_v2 = multiply_row(v2, num_v1);
    vector<ll> new_v3 = subtract_row(new_v1, new_v2);
    return new_v3;
}

vector<vector<ll>> gaussian_elim(vector<vector<ll>> im){
    // Lower triangle
    ll mat_size = im.size();
    for(ll i = 0;i < mat_size;i++){
        vector<ll> base_row = im[i];
        for(ll j = mat_size-1;j > i;j--){
            vector<ll> target_row = im[j];
            vector<ll> new_target = row_reduce(base_row, target_row, i);
            im[j] = new_target;
        }
    }

    // Upper triangle
    for(ll i = mat_size-1;i > 0;i--){
        vector<ll> base_row = im[i];
        for(ll j = 0;j < i;j++){
            vector<ll> target_row = im[j];
            vector<ll> new_target = row_reduce(base_row, target_row, i);
            im[j] = new_target;
        }
    }

    // Divide
    for(ll i = 0;i < mat_size;i++){
        im[i] = divide_row(im[i], im[i][i]);
    }
    // print_mat(im);
    return im;
}

int main(){
    // ios_base::sync_with_stdio(false); cin.tie(0);
    vector<vector<ll>> mat;
    ll tc;
    cin >> tc;
    for(ll i = 0;i < tc;i++){
        vector<ll> v;
        for(ll j = 0;j < tc + 1;j++){
            ll temp; cin >> temp;
            v.push_back(temp);
        }
        mat.push_back(v);
    }

    // prll_mat(mat);

    mat = gaussian_elim(mat);
    for(ll i = 0;i < tc;i++){
        cout << mat[i][tc] << " ";
    }
}
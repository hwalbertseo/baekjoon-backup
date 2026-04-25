#include <iostream>
#include <vector>
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;

void print_mat(vector<vector<int>> inp){
    for(int i = 0;i < inp.size();i++){
        for(int j = 0;j < inp[i].size();j++){
            cout << inp[i][j] << " ";
        }
        cout << "\n";
    }
    return;
}

int gcd(int a, int b){
    if(b==0){
        return a;
    }
    return gcd(b, a%b);
}

int find_gcd(vector<int> v){
    int ans = v[0];
    for(int i = 1;i < v.size();i++){
        ans = gcd(ans, v[i]);
    }
    return ans;
}

vector<int> subtract_row(vector<int> v1, vector<int> v2){
    // Subtract v1 from v2 and return the results
    // cout << "subtract\n";
    vector<int> ans;
    for(int i = 0;i < v1.size();i++){
        ans.push_back(v1[i] - v2[i]);
    }
    return ans;
}

vector<int> multiply_row(vector<int> v, int c){
    // cout << "multiply \n";
    for(int i = 0;i < v.size();i++){
        v[i] = v[i] * c;
    }
    return v;
}

vector<int> divide_row(vector<int> v, int c){
    // cout << "multiply \n";
    for(int i = 0;i < v.size();i++){
        v[i] = v[i] / c;
    }
    return v;
}

vector<int> row_reduce(vector<int> v1, vector<int> v2, int idx){
    // Row-reduce the idx-th number of v2, based on v1.
    int num_v1 = v1[idx]; int num_v2 = v2[idx];
    vector<int> new_v1 = multiply_row(v1, num_v2);
    vector<int> new_v2 = multiply_row(v2, num_v1);
    vector<int> new_v3 = subtract_row(new_v1, new_v2);
    int gcd = find_gcd(new_v3);
    // cout << gcd << "\n";
    new_v3 = divide_row(new_v3, gcd);
    // for(int i = 0;i < new_v3.size();i++){
    //     cout << new_v3[i] << " ";
    // }
    // cout << "\n";
    return new_v3;
}

vector<vector<int>> gaussian_elim(vector<vector<int>> im){
    // Lower triangle
    int mat_size = im.size();
    for(int i = 0;i < mat_size;i++){
        vector<int> base_row = im[i];
        for(int j = mat_size-1;j > i;j--){
            vector<int> target_row = im[j];
            vector<int> new_target = row_reduce(base_row, target_row, i);
            im[j] = new_target;
        }
    }

    // Upper triangle
    for(int i = mat_size-1;i > 0;i--){
        vector<int> base_row = im[i];
        for(int j = 0;j < i;j++){
            vector<int> target_row = im[j];
            vector<int> new_target = row_reduce(base_row, target_row, i);
            im[j] = new_target;
        }
    }

    // Divide
    for(int i = 0;i < mat_size;i++){
        im[i] = divide_row(im[i], im[i][i]);
    }
    // print_mat(im);
    return im;
}

int main(){
    // ios_base::sync_with_stdio(false); cin.tie(0);
    vector<vector<int>> mat;
    int tc;
    cin >> tc;
    for(int i = 0;i < tc;i++){
        vector<int> v;
        for(int j = 0;j < tc + 1;j++){
            int temp; cin >> temp;
            v.push_back(temp);
        }
        mat.push_back(v);
    }

    // print_mat(mat);

    mat = gaussian_elim(mat);
    for(int i = 0;i < tc;i++){
        cout << mat[i][tc] << " ";
    }
}
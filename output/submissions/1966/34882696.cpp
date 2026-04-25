#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

bool great(int i, int j){
    return i>j;
}

int main()
{
    int num;
    cin >> num;
    for(int i = 0;i < num;i++){
        int n, m;
        queue<int> imp, q;
        cin >> n >> m;
        int ord[n];
        for(int j = 0;j < n;j++){
            cin >> ord[j];
            q.push(ord[j]);
        }
        sort(ord, ord+n, great);
        for(int j = 0;j < n;j++){
            imp.push(ord[j]);
        }

        //pop most important
        int index = m;
        int cnt = 1;
        while(!q.empty()){
            //cout << "index: " << index << "\n";
            if(index == 0 && q.front() == imp.front()){
                cout << cnt <<"\n";
            }
            if(q.front() == imp.front()){
                cnt++;
                q.pop();
                imp.pop();
                index--;
            }
            else{
                q.push(q.front());
                q.pop();
                if(index != 0){
                    index--;
                }
                else{
                    index = q.size()-1;
                }
            }
        }
    }
}

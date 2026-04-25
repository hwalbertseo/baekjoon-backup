#include <iostream>
#include <queue>
#include <vector>
#define ll long long

using namespace std;

ll k, n, a, b, c, d;

struct cmp{
    bool operator()(pair<char, int> p, pair<char, int> q){
        ll ta = a;
        ll tb = b;
        ll tc = c;
        ll td = d;
        ll arp, arq;
        switch(p.first){
        case 'A':
            arp = (a+p.second)*b*c*d;
            break;
        case 'B':
            arp = (b+p.second)*a*c*d;
            break;
        case 'C':
            arp = (c+p.second)*a*b*d;
            break;
        case 'D':
            arp = (d+p.second)*a*c*b;
            break;
        }
        switch(q.first){
        case 'A':
            arq = (a+q.second)*b*c*d;
            break;
        case 'B':
            arq = (b+q.second)*a*c*d;
            break;
        case 'C':
            arq = (c+q.second)*a*b*d;
            break;
        case 'D':
            arq = (d+q.second)*a*c*b;
            break;
        }
        return arp < arq;
    }
};

int main()
{
    cin >> n >> k;
    cin >> a >> b >> c >> d;
    priority_queue<pair<char, int>, vector<pair<char, int>>, cmp> pq;
    for(int i = 0;i < n;i++){
        char p;
        int q;
        cin >> p >> q;
        pq.push({p, q});
    }
    for(int i = 0;i < k;i++){
        cout << pq.top().first << " " << pq.top().second << "\n";
        switch(pq.top().first){
        case 'A':
            a += pq.top().second;
            break;
        case 'B':
            b += pq.top().second;
            break;
        case 'C':
            c += pq.top().second;
            break;
        case 'D':
            d += pq.top().second;
            break;
        }
        pq.pop();
    }
}

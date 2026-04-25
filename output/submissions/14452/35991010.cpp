#include <iostream>
#include <set>
#include <queue>

using namespace std;

int n, t;

int func(queue<int> q, int mid){
  multiset<int> s;
  int arr[mid];
  for(int i = 0;i < mid;i++){
    s.insert(q.front());
    q.pop();
  }
  int temp = 0;
  //cout << "mid: " << mid << endl;
  while(q.size() != 0){
    /*
    for(auto it = s.begin();it != s.end();it++){
      cout << *it << " ";
    }
    cout << endl;
    */
    temp = *(s.begin()) - temp;
    s.erase(s.begin());
    s.insert(q.front() + temp);
    q.pop();
  }
  /*
  for(auto it = s.begin();it != s.end();it++){
      cout << *it << " ";
    }
    cout << endl;
    */
  return *(s.rbegin());
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cin >> n >> t;
  queue<int> realq;
  for(int i = 0;i < n;i++){
    int temp;
    cin >> temp;
    realq.push(temp);
  }
  //cout << "hello" << endl;
  int lo = 1;
  int hi = n;
  while(lo < hi){
    int mid = (lo+hi)/2;
    queue<int> q = realq;
    int num = func(q, mid);
    //cout << "mid: " << mid << " num: " << num << endl;
    if(num > t){
      lo = mid+1;
    }
    else{
      hi = mid;
    }
    //cout << "loop";
  }
  cout << lo;
}
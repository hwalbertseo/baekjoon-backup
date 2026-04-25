#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <map>

using namespace std;

#define MAXN 100010
#define INF 1000000010

int main() {

  int N; cin >> N;
  vector<pair<int, char> > A(N);
  for(int i = 0; i < N; i++) {
    cin >> A[i].first >> A[i].second;
  }
  sort(A.begin(), A.end());

  int ps = 0; /* Tracks the prefix sum of the array. */
  int result = 0;
  vector<pair<int, int> > V[2];
  for(int i = 0; i < N; i++) {
    /* Record the current (prefix, position) if 
    if (V[ps & 1].empty() || V[ps & 1].back().first < ps) {
      V[ps & 1].push_back(make_pair(ps, A[i].first));
    }

    /* Update the prefix sum with the current cow. */
    ps += A[i].second == 'W' ? -1 : 1;

    /* Find the farthest starting position that has prefix sum no larger
     * than the current prefix (and therefore starting there gives us more
white cows). */
    if (!V[ps & 1].empty() && ps <= V[ps & 1].back().first) {
      result = max(result, A[i].first -
                           lower_bound(V[ps & 1].begin(), V[ps & 1].end(),
                                       make_pair(ps, -INF))->second);
    }
  }
  cout << result << endl;
  return 0;
}

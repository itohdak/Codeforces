#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REPL(i,0,n)
#define all(v) v.begin(), v.end()
template<class t, class u>
ostream& operator<<(ostream& os, const pair<t, u>& p) {
  return os << "{" << p.first << ", " << p.second << "}";
}
template<class t> ostream& operator<<(ostream& os, const vector<t>& v) {
  os << "{";
  rep(i, v.size()) { if(i) os << ", "; os << v[i]; }
  return os << "}";
}
// template<class t> ostream& operator<<(ostream& os, const set<t>& se) {
//   os << "{";
//   auto itr = se.begin();
//   rep(i, se.size()) { if(i) os << ", "; os << *itr; itr++; }
//   return os << "}";
// }
// template<class t, class u>
// ostream& operator<<(ostream& os, const map<t, u>& mp) {
//   os << "{";
//   auto itr = mp.begin();
//   rep(i, mp.size()) { if(i) os << ", "; os << *itr; itr++; }
//   return os << "}";
// }
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

void solve() {
  int N;
  cin >> N;
  vector<int> A(N);
  rep(i, N) cin >> A[i];
  set<int> se;
  int mn=inf, mx=-1;
  set<pair<int, int> > ansTmp;
  rep(i, N) {
    mn = min(A[i], mn);
    mx = max(A[i], mx);
    se.insert(A[i]);
    if(se.size() == i+1 && mn == 1 && mx == i+1) ansTmp.insert(make_pair(i+1, N-i-1));
  }
  se = set<int>();
  mn = inf, mx = -1;
  set<pair<int, int> > ans;
  rrep(i, N) {
    mn = min(A[i], mn);
    mx = max(A[i], mx);
    se.insert(A[i]);
    if(se.size() == N-i && mn == 1 && mx == N-i && ansTmp.count(make_pair(i, N-i))) ans.insert(make_pair(i, N-i));
  }
  cout << ans.size() << endl;
  for(auto a: ans) cout << a.first << ' ' << a.second << endl;
}
int main() {
  int T;
  cin >> T;
  rep(t, T) solve();
  return 0;
}

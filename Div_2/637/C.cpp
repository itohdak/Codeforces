#include <bits/stdc++.h>
// #include "/home/itohdak/Codeforces/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REPL(i,0,n)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

void solve() {
  int N;
  cin >> N;
  vector<int> P(N);
  rep(i, N) cin >> P[i];
  int l=0;
  int mx = N;
  while(l < N) {
    int tmp = P[l];
    bool ok = true;
    rep(i, mx-tmp+1) if(P[l+i] != tmp+i) ok = false;
    if(ok) {
      l += mx-tmp+1;
      mx = tmp-1;
    } else {
      cout << "No" << endl;
      return;
    }
  }
  cout << "Yes" << endl;
}
int main() {
  int T;
  cin >> T;
  rep(t, T) solve();
  return 0;
}

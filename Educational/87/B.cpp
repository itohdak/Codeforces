#include <bits/stdc++.h>
#include "/home/itohdak/Codeforces/000/print.hpp"
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
  string S;
  cin >> S;
  int N = S.size();
  vector<vector<int>> next(N+1, vector<int>(3));
  next[N][0] = N;
  next[N][1] = N;
  next[N][2] = N;
  rrep(i, N) {
    rep(j, 3) {
      if(int(S[i]-'1')==j) next[i][j] = i;
      else next[i][j] = next[i+1][j];
    }
  }
  // cout << next << endl;
  int ans = N+1;
  rep(i, N) {
    int res = i;
    rep(j, 3) res = max(next[i][j], res);
    if(res == N) continue;
    ans = min(res-i+1, ans);
  }
  cout << (ans==N+1 ? 0 : ans) << endl;
}
int main() {
  int T;
  cin >> T;
  rep(t, T) solve();
  return 0;
}

#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,(n)-1,0)
#define all(v) v.begin(), v.end()
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

void solve() {
  int n, m; cin >> n >> m;
  int q; cin >> q;
  vector<string> S(n); rep(i, n) cin >> S[i];
  vector<vector<vector<int>>> cnt(4, vector<vector<int>>(n+1, vector<int>(m+1)));
  map<char, int> mp = {{'R', 0}, {'G', 1}, {'B', 2}, {'Y', 3}};
  rep(i, n) rep(j, m) cnt[mp[S[i][j]]][i+1][j+1]++;
  rep(i, n+1) rep(j, m) rep(k, 4) cnt[k][i][j+1] += cnt[k][i][j];
  rep(j, m+1) rep(i, n) rep(k, 4) cnt[k][i+1][j] += cnt[k][i][j];
  // rep(k, 4) cout << cnt[k] << endk;
  rep(_, q) {
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}

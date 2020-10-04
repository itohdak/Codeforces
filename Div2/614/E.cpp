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
  int n; cin >> n;
  vector<vector<int>> G(n);
  rep(i, n-1) {
    int u, v; cin >> u >> v;
    u--; v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  auto calc = [&](int s) {
    vector<int> nChild(n);
    vector<int> parent(n);
    auto dfs = [&](auto dfs, int cur, int par) -> int {
      parent[cur] = par;
      for(int ne: G[cur]) {
        if(ne != par) nChild[cur] += dfs(dfs, ne, cur);
      }
      return nChild[cur]+1;
    };
    dfs(dfs, s, -1);
    ll mx = 0;
    rep(t, n) {
      vector<int> child(n, -1);
      int cur = t;
      while(parent[cur] != -1) {
        child[parent[cur]] = cur;
        cur = parent[cur];
      }
      ll ret = 0;
      int depth = 0;
      auto dfs2 = [&](auto dfs2, int cur) -> void {
        if(cur == t) return;
        ret += (nChild[cur]-nChild[child[cur]]) * (depth+1);
        depth++;
        dfs2(dfs2, child[cur]);
      };
      dfs2(dfs2, s);
      cout << s << ' ' << t << ' ' << ret << endk;
      chmax(mx, ret);
    }
    return mx;
  };
  ll ans = 0;
  rep(i, n) chmax(ans, calc(i));
  cout << ans << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}

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
  vector<int> W(n);
  map<int, int> cnt;
  rep(i, n) {
    cin >> W[i];
    cnt[W[i]]++;
  }
  ll ans = 0;
  rep(i, 2*n+1) {
    ll tmp = 0;
    rep(j, n+1) {
      if(j > i-j) break;
      if(!cnt.count(j) || !cnt.count(i-j)) continue;
      if(j != i-j) {
        tmp += min(cnt[j], cnt[i-j]);
      } else {
        tmp += cnt[j] / 2;
      }
    }
    chmax(ans, tmp);
  }
  cout << ans << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}

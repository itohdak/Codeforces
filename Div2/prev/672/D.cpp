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
const ll mod = 998244353;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

#define MAX_N 2000005
ll inv[MAX_N], fac[MAX_N], finv[MAX_N];
void make() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for(int i=2; i<MAX_N; i++) {
    inv[i] = mod - inv[mod%i] * (mod/i) % mod;
    fac[i] = fac[i-1] * (ll)i % mod;
    finv[i] = finv[i-1] * inv[i] % mod;
  }
}
ll perm(ll n, ll r) {
  if(n < 0)       return 0;
  else if(n < r)  return 0;
  else            return (fac[n] * finv[n-r]) % mod;
}
ll comb(ll n, ll r) {
  ll ans = 1;
  ans = perm(n, r);
  ans = (ans * finv[r]) % mod;
  return ans;
}
void solve() {
  int n, k; cin >> n >> k;
  vector<ll> L(n), R(n);
  vector<ll> X;
  rep(i, n) {
    cin >> L[i] >> R[i];
    L[i]--; R[i]--;
    X.push_back(L[i]);
    X.push_back(R[i]);
  }
  sort(all(X));
  X.erase(unique(all(X)), end(X));
  vector<int> l(n), r(n);
  rep(i, n) {
    l[i] = lower_bound(all(X), L[i]) - begin(X);
    r[i] = lower_bound(all(X), R[i]) - begin(X) + 1;
  }
  vector<int> id(n);
  rep(i, n) id[i] = i;
  sort(all(id), [&](int i, int j) {
    return l[i] < l[j];
  });
  vector<int> sum(X.size()+1);
  rep(i, n) {
    sum[l[i]]++;
    sum[r[i]]--;
  }
  rep(i, X.size()) sum[i+1] += sum[i];
  // cout << sum << endk;
  ll ans = 0;
  int i = 0;
  while(i < n) {
    int tmp = l[id[i]];
    int cnt = 0;
    while(i < n && l[id[i]] == tmp) {
      i++;
      cnt++;
    }
    REP(j, 1, min(cnt, k)+1) {
      (ans += comb(sum[tmp]-cnt, k-j) * comb(cnt, j) % mod) %= mod;
    }
  }
  cout << ans << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  make();
  int T = 1;
  while(T--) solve();
  return 0;
}
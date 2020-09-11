#include <bits/stdc++.h>
#include "/home/itohdak/Codeforces/000/print.hpp"
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
  vector<ll> A(n); rep(i, n) cin >> A[i];
  ll ans = 0;
  int l = 0, r = n-1;
  while(l < r) {
    ll tmp = 0;
    while(l < n && A[l]+tmp >= 0) {
      tmp += A[l];
      l++;
    }
    if(l == n) break;
    A[l] += tmp;
    tmp = 0;
    while(r >= 0 && A[r]+tmp <= 0) {
      tmp += A[r];
      r--;
    }
    if(r == -1) break;
    A[r] += tmp;
    if(l >= r) break;
    ll mn = min(-A[l], A[r]);
    ans += mn;
    A[l] += mn;
    A[r] -= mn;
  }
  cout << ans << endl;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
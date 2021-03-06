#include <bits/stdc++.h>
#include "/home/itohdak/Codeforces/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<ll> A(n);
  vector<int> cnt(20);
  rep(i, n) {
    cin >> A[i];
    rep(j, 20) {
      cnt[j] += (A[i]>>j&1);
    }
  }
  vector<ll> B(n);
  rep(j, 20) {
    rep(i, cnt[j]) {
      B[i] += (1<<j);
    }
  }
  ll ans = 0;
  rep(i, n) {
    ans += B[i] * B[i];
  }
  cout << ans << endl;
  return 0;
}

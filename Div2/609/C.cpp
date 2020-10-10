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
  int n, k; cin >> n >> k;
  string s; cin >> s;
  string t = s.substr(0, k);
  auto test = [&]() {
    rep(i, n) {
      if(s[i] == t[i%k]) continue;
      else if(s[i] > t[i%k]) return false;
      else return true;
    }
    return true;
  };
  if(!test()) {
    rrep(i, k) {
      if(t[i] != '9') {
        t[i]++;
        break;
      }
      t[i] = '0';
    }
  }
  cout << n << endk;
  rep(i, n) cout << t[i%k];
  cout << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}

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
  ll K;
  cin >> N >> K;
  ll i = 1;
  while(i<=N) {
    if(i*(i-1)/2<K && K<=(i+1)*i/2) break;
    i++;
  }
  vector<char> ans(N, 'a');
  ans[N-1-i] = ans[N-(K-i*(i-1)/2)] = 'b';
  rep(i, N) cout << ans[i];
  cout << endl;
}
int main() {
  int T;
  cin >> T;
  rep(t, T) solve();
  return 0;
}

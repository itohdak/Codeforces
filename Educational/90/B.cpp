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

void solve() {
  string s;
  cin >> s;
  int n = s.size();
  deque<char> q;
  int ans = 0;
  rep(i, n) {
    if(q.size() > 0 && q.back() != s[i]) {
      ans++;
      q.pop_back();
    } else {
      q.push_back(s[i]);
    }
  }
  cout << (ans%2==0 ? "NET" : "DA") << "\n";
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  rep(t, T) solve();
  return 0;
}

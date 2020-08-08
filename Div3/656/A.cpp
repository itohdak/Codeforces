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
  ll x, y, z;
  cin >> x >> y >> z;
  if(x == y && y == z) {
    cout << "YES" << "\n";
    cout << x << ' ' << x << ' ' << x << "\n";
  } else if(x == y && x > z) {
    cout << "YES" << "\n";
    cout << x << ' ' << z << ' ' << z << "\n";
  } else if(y == z && y > x) {
    cout << "YES" << "\n";
    cout << x << ' ' << x << ' ' << y << "\n";
  } else if(z == x && z > y) {
    cout << "YES" << "\n";
    cout << y << ' ' << z << ' ' << y << "\n";
  } else {
    cout << "NO" << "\n";
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}

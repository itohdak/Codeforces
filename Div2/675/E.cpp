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
  string s; cin >> s;
  int n = s.size();
  string ans;
  int l = 0, r = 0;
  vector<int> removed(n, 0);
  while(l < n) {
    while(l == n-1 || (l < n && s[l] != s[l+1])) {
      ans += s[l];
      l++;
    }
    r = l;
    while(r < n && s[r] == s[l]) r++;
    if(r < n && s[l] < s[r]) {
      ans += string(r-l, s[l]);
      l = r;
      continue;
    }
    if((r-l)%2) {
      int tmp = 1;
      for(int i=l+1; i<r; i++) {
        removed[i] = tmp;
        tmp = 3-tmp;
      }
      ans += s[l];
    } else {
      int tmp = 1;
      for(int i=l; i<r; i++) {
        removed[i] = tmp;
        tmp = 3-tmp;
      }
    }
    l = r;
  }
  // cout << removed << endk;
  // cout << ans << endk;
  int begin = 0;
  int sz = ans.size();
  rep(i, n) {
    int tmpsz = (sz-begin) + (removed[i]==2);
    cout << tmpsz << ' ';
    if(tmpsz > 10) {
      if(removed[i]==2) cout << s[i];
      rep(j, 5-(removed[i]==2)) cout << ans[begin+j];
      cout << "...";
      cout << ans[sz-2] << ans[sz-1] << endk;
    } else {
      if(removed[i]==2) cout << s[i];
      REP(j, begin, sz) cout << ans[j];
      cout << endk;
    }
    if(removed[i]==0) begin++;
    // if(removed[i]!=2) begin++;
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}

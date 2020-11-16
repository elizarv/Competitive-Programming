#include <bits/stdc++.h>
using namespace std;
void debug() {cout<<endl;}
template<typename T,typename... Args>
void debug(T a,Args... args) {cout<<a<<" ";debug(args...);}
#define forn(i,a,b) for(int i=a;i<b;++i)
#define SZ(x) int(x.size())
#define pb push_back
#define F first
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;

string s;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> s;
  vector<int> ans;
  forn (i, 0, SZ(s) - 2) {
    if (s[i] == s[i + 1]) {
      ans.pb(i + 2);
      if (SZ(ans) == SZ(s) / 3) break;
      s[i + 1] = (s[i + 1] == '0'? '1' : '0');
      s[i + 2] = (s[i + 2] == '0'? '1' : '0');
      i++;
    }
  }
  cout << SZ(ans) << endl;
  forn (i, 0, SZ(ans)) {
    cout << ans[i] << " \n"[i + 1 == SZ(ans)];
  }
}
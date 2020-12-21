#include <bits/stdc++.h>
using namespace std;
void debug() { cout << endl; }
template <typename T, typename... Args>
void debug(T a, Args... args) { cout << a << " "; debug(args...);}
#define forn(i, a, b) for (int i = a; i < b; ++i)
#define SZ(x) int(x.size())
#define pb push_back
#define F first
#define S second
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while(t--){
    int n; cin >> n;
    string s, so; cin >> so;
    s.resize(n, '.');
    forn(i, 0, n){
      if(so[i] == '*'){
        if(i)s[i-1] = '*';
        s[i] = '*';
        if(i+1 < n)s[i+1] = '*';
      }
    }
    int cnt = 0, ans = 0;
    forn(i, 0, n){
      if(s[i] == '*'){
        ans += (cnt+2)/3;
        cnt = 0;
      }else{
        cnt++;
      }
    }
    ans += (cnt+2)/3;
    cout << ans << endl;
  }
  
}

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

  int n;
  cin >> n;
  bool f = n&1;
  ll ans = 0;
  forn(i, 0, n){
    int x;
    cin >> x;
    if(f)ans += x;
    else ans -= x;
    f = !f;
  }

  int m;
  cin >> m;

  f = n&1;

  forn(i, 0, m){
    int l, r, x;
    cin >> l >> r >> x;
    if(f)l--, r--;
    int tot = r-l+1;
    if(tot&1){
      if(l&1)ans -= x;
      else ans += x;
    }
    cout << ans << endl;
  }
  
}

/*
g++ -pthread -Wall -Wshadow -std=c++17 -o main main.cpp && ./main < main.txt
freopen("input.in", "r" , stdin);
freopen("output.out", "w", stdout);
*/
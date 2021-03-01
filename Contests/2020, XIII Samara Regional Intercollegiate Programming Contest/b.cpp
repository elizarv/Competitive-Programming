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
  ll t;
  cin >> n >> t;

  vector<int> rg, lf;

  forn(i, 0, n){
    int x; cin >> x;
    if(x < 0)lf.pb(-x);
    else rg.pb(x);
  }

  reverse(lf.begin(), lf.end());

  int ans = 0;

  for(int i = 0; i < lf.size(); i++){
    if(lf[i] > t)break;
    ll x = t-lf[i]-lf[i];
    int pos = upper_bound(rg.begin(), rg.end(), x)-rg.begin();
    ans = max(ans, pos+i+1);
  }

  for(int i = 0; i < rg.size(); i++){
    if(rg[i] > t)break;
    ll x = t-rg[i]-rg[i];
    int pos = upper_bound(lf.begin(), lf.end(), x)-lf.begin();
    ans = max(ans, pos+i+1);
  }

  cout << ans << endl;

  
}

/*
g++ -pthread -Wall -Wshadow -std=c++17 -o main main.cpp && ./main < main.txt
freopen("input.in", "r" , stdin);
freopen("output.out", "w", stdout);
*/
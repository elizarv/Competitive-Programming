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

const int N = 2e5+5;
int dp[N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n;
  cin >> n;
  vector<ll> v(n);
  forn(i, 0, n){
    cin >> v[i];
  }
  sort(v.rbegin(), v.rend());

  ll cur = 1;
  ll ans = 0;
  for(auto x: v){
    if(x > cur){
      ans += x - cur;
      cur++;
    }
  }

  cout << ans << endl;
  
  
}

/*
g++ -pthread -Wall -Wshadow -std=c++17 -o main main.cpp && ./main < main.txt
freopen("input.in", "r" , stdin);
freopen("output.out", "w", stdout);
*/
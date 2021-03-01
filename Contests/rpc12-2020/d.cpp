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
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;

map<int, pii> pos;
vector<pii> v;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n;
  cin >> n;
  
  forn(i, 0, n) {
    int x;
    cin >> x;
    if (!pos.count(x)) pos[x] = {i, i};
    else pos[x].F = i;
  }
  for(auto &x: pos) {
    v.pb(x.S);
  }
  
  sort(v.begin(), v.end());
  int ans = 0;
  int cur = 0;
  n = v.size();
  forn(i, 0, n){
    if(v[i].S >= cur){
      ans++;
      cur = v[i].F;
    }
  }
  cout << n-ans << endl;
}

/*
g++ -pthread -Wall -Wshadow -std=c++17 -o main d.cpp && ./main < d.txt
freopen("input.in", "r" , stdin);
freopen("output.out", "w", stdout);
*/
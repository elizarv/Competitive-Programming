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
vector<int> pos[N], order[N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n;
  cin >> n;
  int mx = 0;
  forn(i, 0, n){
    int x, y;
    cin >> x >> y;
    pos[y].pb(x);
    order[y].pb(x);
    mx = max(mx, y);
  }

  bool ans = true;

  forn(i, 0, mx+1){
    sort(order[i].begin(), order[i].end());
    if(order[i] != pos[i])ans = false;
  }
  if(ans) cout << "YES" << endl;
  else cout << "NO"<< endl;

}

/*
g++ -pthread -Wall -Wshadow -std=c++17 -o main main.cpp && ./main < main.txt
freopen("input.in", "r" , stdin);
freopen("output.out", "w", stdout);
*/
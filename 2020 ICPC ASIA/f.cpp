#include <bits/stdc++.h>
using namespace std;
void print() {cout<<endl;}
template<typename T,typename... E>
void print(T t,E... e) {cout<<t<<(sizeof...(e)?" ":"");print(e...);}
#define forn(i,x,n) for(int i=int(x);i<int(n);++i)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define F first
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5+5, inf = 1e9;
vector<int> g[N];
int dp[N][2][2];
int n;
int w[N][2];

int f(int u, bool prev){
  int &ans = dp[u][prev][0];
  if(ans != -1)return ans;
  ans = 1; // lo pinto
  int ans2 = prev ? 0 : 1e9; // no lo pinto
  for(int &v: g[u]){
    if(v < n)continue;
    if(prev)ans2 += f(v, 0);
    ans += f(v, 1);
  }
  ans = min(ans, ans2);
  return ans;
}

int go(int u, bool prev, int f){
  if(u == n - 1) {
    if(!f || !prev)return w[u][1];
    return min(w[u][0], w[u][1]);
  }
  int &ans = dp[u][prev][f];
  if(ans != -1)return ans;
  ans = inf;
  if(prev)ans = min(ans, go(u + 1, 0, f) + w[u][0]);
  ans = min(ans, go(u + 1, 1, f) + w[u][1]);
  return ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int m;
  cin >> n >> m;

  forn(i, 0, n + m){
    int u, v;
    cin >> u >> v;
    if(v < u)swap(u, v);
    if(v < n)continue;
    g[u].pb(v);
  }

  memset(dp, -1, sizeof dp);

  forn(u, 0, n){
    for(int &v: g[u]){
      w[u][0] += f(v, 0);
      w[u][1] += f(v, 1);
    }
    w[u][1]++;
  }

  cout << min(go(1, 0, 0) + w[0][0], go(1, 1, 1) + w[0][1]) << endl;
  
}


/*
g++ -pthread -Wall -Wshadow -std=c++17 -o main f.cpp && ./main < f.txt
freopen("input.in", "r" , stdin);
freopen("output.out", "w", stdout);
*/
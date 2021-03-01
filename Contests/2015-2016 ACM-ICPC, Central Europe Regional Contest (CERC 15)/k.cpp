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
int g[N], in[N];
bitset<N> vis;
vector<int> ans;

void dfs(int u, bool f){
    if(f)ans.pb(u+1);
    vis[u] = true;
    int v = g[u];
    if(!vis[v])dfs(v, !f);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  n *= 2;
  forn(i, 0, n){
      int x;
      cin >> x;
      x--;
      in[x]++;
      g[i] = x;
  }

  queue<int> q;
  
    forn(i, 0, n){
        if(!in[i]){
            q.push(i);
        }
    }

    while(q.size()){
        int u = q.front();
        q.pop();
        vis[u] = true;
        ans.pb(u+1);
        int v = g[u];
        if(vis[v])continue;
        vis[v] = true;
        in[g[v]]--;
        if(!in[g[v]])q.push(g[v]);
    }

    forn(i, 0, n){
        if(!vis[i]){
            dfs(i, true);
        }
    }

  for(auto x: ans){
      cout << x << " ";
  }cout << endl;


  
}

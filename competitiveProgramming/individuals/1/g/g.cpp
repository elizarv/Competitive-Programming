#include <bits/stdc++.h>
using namespace std;
void debug() {cout<<endl;}
template<typename T,typename... Args>
void debug(T x,Args... args) {cout<<x<<" ";debug(args...);}
#define forn(i,a,b) for(int i=a;i<b;++i)
#define pb push_back
#define F first
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;


const int MAX = 200005;
vector<int> g[MAX];
int nxt[MAX];
string name[MAX];
int ans;
string ilove = "I_love_";
int times;

int dfs(int u, int mx){
    int id = lower_bound(g[u].begin(), g[u].end(), mx)-g[u].begin();
    if(id == g[u].size())return u;
    int ed = g[u][id];
    times++;
    return dfs(nxt[ed], ed);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int n;
  cin >> n;
  forn(i, 0, n){
      cin >> name[i];
  }

  int m, u, v;
  cin >> m;
  for(int i = m; i > 0; i--){
      cin >> u >> v;
      u--, v--;
      nxt[i] = v;
      g[u].pb(i);
  }

  for(auto &x: g){
      sort(x.begin(), x.end());
  }

  int ans = dfs(0, 0);


  while(times--){
      cout << ilove;
  }
  cout << name[ans] << endl;
    
  
}


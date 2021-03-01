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

const int N = 15, M = 27;
bool g[N][N];
bool dp[N][1 << N], vis[N][1<<N];
int target, n, last, fst;
map<char, int> mapa;
map<int, char> back;

int f(int u, int mask){
  if(mask == target && u == last) return true;
  bool &ans = dp[u][mask];
  if(vis[u][mask])return ans;
  vis[u][mask] = true;
  forn(v, 0, n){
    if(!g[u][v] || (mask >> v & 1))continue;
    int nxtmask = mask ^ (1 << v);
    if(f(v, nxtmask)){
      ans = true;
      break;
    }
  }
  return ans;
}

string ans;

void build(int u, int mask){
  ans.pb(back[u]);
  if(mask == target)return;
  forn(v, 0, M){
    if(!g[u][v] || (mask >> v & 1))continue;
    int nxtmask = mask ^ (1 << v);
    if(f(v, nxtmask)){
      build(v, nxtmask);
      return;
    }
  }
}

void init(){
  forn(i, 0, n){
    forn(j, 0, n){
      g[i][j] = 0;
    }
    forn(mask, 0, 1 << n){
      dp[i][mask] = vis[i][mask] = 0;
    }
  }
  mapa.clear();
  back.clear();
  ans.clear();
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  
  int t, test = 1;
  cin >> t;
  while(t--){
    cout << "Case " << test++ << ": ";
    int m;
    cin >>n >> m;
    init();
    target = (1 << n)-1;
    vector<char> let(n);
    char aux, aux2;
    forn(i, 0, n){
      cin >> let[i];
      if(!i)aux2 = let[i];
      aux = let[i];
    }
    sort(let.begin(), let.end());
    forn(i, 0, n){
      char c = let[i];
      int u = c-'A';
      mapa[c] = i;
      back[i] = c;
    }
    last = mapa[aux];
    fst = mapa[aux2];
    forn(i, 0, m){
      char x, y;
      cin >> x >> y;
      int u = mapa[x];
      int v = mapa[y];
      g[u][v] = g[v][u] = true;
    }

    int mask = 0;
    bool flag = false;
    mask = mask ^ (1 << fst);
    if(f(fst, mask)){
      build(fst, mask);
      flag = true;
    }

    if(flag)cout << ans << endl;
    else cout << "impossible" << endl;

  }



}
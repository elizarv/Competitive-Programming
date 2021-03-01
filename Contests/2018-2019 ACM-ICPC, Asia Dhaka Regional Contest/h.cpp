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

const int N = 205, mod = 78294349;
int mat[N][N];
int g[N*N], pos[N*N];
bitset<N*N> vis;
int n, m;
vector<ll> sz;


void init(){
  sz.clear();
  vis = 0;
  int p = 0;
  forn(i, 0, n+1){
    forn(j, 0, m+1){
      mat[i][j] = 0;
      g[p] = pos[p] = 0;
      p++;
    }
  }
}

void goright(){
  forn(i, 0, n){
    int j = m-1, nxtj = j;
    while(j >= 0 && !mat[i][j])j--;
    if(j == nxtj)continue;
    while(j >= 0){
      mat[i][nxtj] = mat[i][j];
      mat[i][j] = 0;
      j--;
      nxtj--;
    }
  }
}

void goup(){
  forn(j, 0, m){
    int i = 0, nxti = i;
    while(i < n && !mat[i][j])i++;
    if(i == nxti)continue;
    while(i < n){
      mat[nxti][j] = mat[i][j];
      mat[i][j] = 0;
      i++;
      nxti++;
    }
  }
}

void goleft(){
  forn(i, 0, n){
    int j = 0, nxtj = j;
    while(j < m && !mat[i][j])j++;
    if(j == nxtj)continue;
    while(j < m){
      mat[i][nxtj] = mat[i][j];
      mat[i][j] = 0;
      j++, nxtj++;
    }
  }
}

void godown(){
  forn(j, 0, m){
    int i = n-1, nxti = i;
    while(i >= 0 && !mat[i][j])i--;
    if(i == nxti)continue;
    while(i >= 0){
      mat[nxti][j] = mat[i][j];
      mat[i][j] = 0;
      i--, nxti--;
    }
  }
}

void getcycle(){
  forn(i, 0, n){
    forn(j, 0, m){
      int nxt = mat[i][j];
      if(nxt){
        int u = pos[nxt];
        int v = i*m+j;
        g[u] = v;
      }
    }
  }
  
}

ll dfs(int u){
  ll ans = 1;
  vis[u] = true;
  int v = g[u];
  if(!vis[v])ans += dfs(v);
  return ans;
}

ll gcd(ll a, ll b){
  if(!b)return a;
  return gcd(b, a%b);
}

ll lcm(ll a, ll b){
  return a*b/gcd(a, b);
}

int getans(){
  map<ll, int> pot;
  for(auto &x: sz){
    for(ll i = 2; i*i <= x; i++){
      int cnt = 0;
      while(x%i == 0){
        x/= i;
        cnt++;
      }
      pot[i] = max(pot[i], cnt);
    }
    if(x > 1)pot[x] = max(pot[x], 1);
  }

  ll ans = 1;
  for(auto &x: pot){
    forn(i, 0, x.S){
      ans = (x.F * ans) % mod;
    }
  }
  return ans;
}

void print(){
  forn(i, 0, n){
    forn(j, 0, m)cout << mat[i][j] << " ";
    debug();
  }debug();
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  
  int t, caso = 1;
  cin >> t;

  while(t--){
    cin >> n >> m;
    init();
    int cnt = 1;
    forn(i, 0, n){
      forn(j, 0, m){
        char ch;
        cin >> ch;
        if(ch == '#'){
          mat[i][j] = cnt;
          pos[cnt] = i*m+j;
          cnt++;
        }
      }
    }

    goright();
    goup();
    goleft();
    godown();
    getcycle();

    ll ans = 1;

    forn(i, 0, n){
      forn(j, 0, m){
        if(!mat[i][j])continue;
        int u = i*m+j;
        if(!vis[u]){
          sz.pb(dfs(u));
        }
      }
    }

    cout << "Case " << caso++ << ": " << getans() << endl;

  }

}

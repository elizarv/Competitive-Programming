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

const int N = 3005, M = 4505;
vector<pii> g[N];
bitset<M> e, vis;
int cnt, n;
int ans[N][N], col[N];


void fill(int u, int num){
    col[u] = num;
    vis[u] = 1;
    for(auto &ed: g[u]){
        int v = ed.F;
        if(vis[v] || e[ed.S])continue;
        fill(v, num);
    }
}

void color(){
	forn(i, 0, n)col[i] = 0;
	cnt = 1;
	vis = 0;
	forn(u, 0, n){
			if(!col[u]){
					fill(u, cnt);
					cnt++;
			}
  }
}

void update(int x){
	forn(u, 0, n){
      forn(v, u+1, n){
          if(ans[u][v] == 3 && col[u] != col[v]){
              ans[u][v] = x;
          }
      }
  }
}



int low[N], num[N], bg, cont;

void pre(){
    cont = bg = 0;
    forn(i, 0, n){
        num[i] = -1;
        low[i] = 0;
    }
}

queue<int> bridges;

void dfs(int u = 0, int p = -1){
    low[u] = num[u] = cont++;
    for(auto &ed: g[u]){
        int v = ed.F;
        if(e[ed.S])continue;
        if(num[v] == -1){
            dfs(v, u);
            if(low[v] > num[u]){
                e[ed.S] = 1;
								bridges.push(ed.S);
            }
            low[u] = min(low[u], low[v]);
        }else if(v != p && num[v] < num[u]){
            low[u] = min(low[u], num[v]);
        }
    }
}

inline int add(int a, int b, const int &mod) { return a+b >= mod ? a+b-mod : a+b; }
inline int sbt(int a, int b, const int &mod) { return a-b < 0 ? a-b+mod : a-b; }
inline int mul(int a, int b, const int &mod) { return 1ll*a*b % mod; }

const int X = 257;
const int MOD = 1e9+7;
vector<int> xpow;

void calc_xpow(int mxlen = N) {
		xpow.resize(mxlen+1, 1);
		for (int i = 1; i <= mxlen; ++i) {
				xpow[i] = mul(xpow[i-1], X, MOD);
		}
}

int h[N];

void update_hash(){
	forn(i, 0, n){
		h[i] = add(mul(h[i], X, MOD), col[i], MOD);
	}
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

	calc_xpow();

  int m;
  cin >> n >> m;

  forn(i, 0, m){
      int u, v;
      cin >> u >> v;
      u--, v--;
      g[u].pb({v, i});
      g[v].pb({u, i});
  }

  forn(i, 0, n){
      forn(j, 0, n){
          ans[i][j] = 3;
      }
  }

	color();
  update(0);
  pre();
  forn(u, 0, n) if (num[u] == -1)dfs(u);
	color();
  update(1);

  forn(i, 0, m){
      if(e[i])continue;
      e[i] = 1;
      pre();
      forn(u, 0, n){
          if(num[u] == -1)dfs(u);
      }
			color();
			update_hash();
			while(bridges.size()){
				e[bridges.front()] = 0;
				bridges.pop();
			}
      e[i] = 0;
  }

	forn(u, 0, n){
      forn(v, u+1, n){
          if(ans[u][v] == 3 && h[u] != h[v]){
              ans[u][v] = 2;
          }
      }
  }

  int r = 0;
  forn(u, 0, n){
      forn(v, u+1, n){
          r += ans[u][v];
      }
  }

  cout << r << endl;
}

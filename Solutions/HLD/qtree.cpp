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

const int N = 1e4+5;
vector<pii> g[N];
vector<pii> edges;
int par[N], dep[N], sz[N];
int pos[N], top[N], val[N];
vector<int> arr;
int idx;

typedef int T;
T neutro = 0;

struct segtree {
    vector<T> st;
    int n;

		segtree(){}

    segtree(int _n){
        n = _n;
        st.assign(n*4, neutro);
        build(1, 0, n-1);
    }

    void build(int p, int L, int R){
        if(L == R)st[p] = arr[L];
        else{
            int m = (L+R)/2, l = p*2, r = l+1;
            build(l, L, m);
            build(r, m+1, R);
            st[p] = max(st[l], st[r]);
        }
    }

    T query(int i, int j){
        return query(1, 0, n-1, i, j);
    }

    T query(int p, int L, int R, int i, int j){
        if(i > R || j < L)return neutro;
        if(i <= L && j >= R)return st[p];
        int m = (L+R)/2, l = p*2, r = l+1;
        int lf = query(l, L, m, i, j);
        int rg = query(r, m+1, R, i, j);
        return max(lf, rg);
    }

    void upd(int i, int val){ upd(1, 0, n-1, i, val); }

    void upd(int p, int L, int R, int i, int val){
        if(i > R || i < L)return;
        if(L == R)st[p] = val;
        else{
            int m = (L+R)/2, l = p*2, r = l+1;
            upd(l, L, m, i, val);
            upd(r, m+1, R, i, val);
            st[p] = max(st[l], st[r]);
        }
    }
};

void pre(int u, int p, int d){
    par[u] = p;
    dep[u] = d;
    sz[u] = 1;
    for(auto &nx: g[u]){
        int v = nx.F;
        int w = nx.S;
				if(v == p)continue;
        val[v] = w;
        pre(v, u, d+1);
        sz[u] += sz[v];
    }
}

void hld(int u, int p, int t){
    arr[idx] = val[u];
    top[u] = t;
    pos[u] = idx++;
    int bigid = -1, mx = 0;
    for(auto &nx: g[u]){
        int v = nx.F;
        if(v == p)continue;
        if(mx < sz[v]){
            mx = sz[v];
            bigid = v;
        }
    }
    if(bigid != -1)hld(bigid, u, t);
    for(auto &nx: g[u]){
        int v = nx.F;
        if(v == p || v == bigid)continue;
        hld(v, u, v);
    }
}

segtree st;

void updt(int u, int val){
    st.upd(pos[u], val);
}

T query(int u, int v){
    T ans = neutro;
    while(top[u] != top[v]){
        if(dep[top[v]] < dep[top[u]])swap(u, v); // v queda abajo
        ans = max(ans, st.query(pos[top[v]], pos[v]));// query de top[v] - v
        v = par[top[v]];// subir a v
    }
    if(dep[u] > dep[v])swap(u, v);// poner u primero
    ans = max(ans, st.query(pos[u]+1, pos[v]));// query u-v
    return ans;
}

void init(int n){
    forn(i, 0, n){
        g[i].clear();
    }
		idx = 0;
    arr.assign(n, 0);
		edges.clear();
}


int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int t;
  cin >> t;
  while(t--){
      int n, u, v, w;
      cin >> n;
      init(n);
      forn(i, 0, n-1){
          cin >> u >> v >> w;
					u--, v--;
					edges.pb({u, v});
          g[u].pb({v, w});
          g[v].pb({u, w});
      }
      pre(0, -1, 0);
      hld(0, -1, 0);
      st = segtree(n);
      string q;
      cin >> q;
      while(q != "DONE"){
          if(q == "CHANGE"){
          	int it, x;
						cin >> it >> x;
						it--;
						u = edges[it].F, v = edges[it].S;
						if(dep[u] < dep[v])swap(u, v);
						updt(u, x);
          }else{
						cin >> u >> v;
            u--, v--;
            cout << query(u, v) << endl;
          }
          cin >> q;
      }
  }


  
}
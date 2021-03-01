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

typedef ll T;

inline T add(int a, int b, const int &mod) { return a+b >= mod ? a+b-mod : a+b; }
inline T sbt(int a, int b, const int &mod) { return a-b < 0 ? a-b+mod : a-b; }
inline T mul(int a, int b, const int &mod) { return 1ll*a*b % mod; }

const int X = 257;
const int MOD = 1e9+7;
vector<int> xpow;

void calc_xpow(int mxlen) {
    xpow.resize(mxlen+1, 1);
    for (int i = 1; i <= mxlen; ++i) {
        xpow[i] = mul(xpow[i-1], X, MOD);
    }
}

struct node {
    T hs, inv;
    int n;
};

node merge(node a, node b){
    int n = a.n, m = b.n;
    T hsa = a.hs, hsb = b.hs;
    T inva = a.inv, invb = b.inv;
    T ans = add(hsa, mul(hsb, xpow[n], MOD), MOD);
    T inv = add(invb, mul(inva, xpow[m], MOD),MOD);
    node nx = {ans, inv, n+m};
    return nx;
}

struct segtree {
    vector<node> st;
    int n;
    node neutro = {0, 0, 0};

    segtree(){}

    segtree(const string &v) {
        n = v.size();
        st.resize(n*4);
        build(1, 0, n-1, v);
    }

    void build(int p, int L, int R, const string &v) {
        if (L == R) st[p] = {v[L], v[L], 1};
        else {
            int m = (L+R)/2, l = p*2, r = l+1;
            build(l, L, m, v);
            build(r, m+1, R, v);
            st[p] = merge(st[l], st[r]);
        }
    }
    
    node query(int i, int j) { return query(1, 0, n-1, i, j); }
    void upd(int i, T val) { upd(1, 0, n-1, i, i, val); }
    
    node query(int p, int L, int R, int i, int j) {
        if (i > R || j < L) return neutro;
        if (i <= L && j >= R) return st[p];
        int m = (L+R)/2, l = p*2, r = l+1;
        node lf = query(l, L, m, i, j);
        node rg = query(r, m+1, R, i, j);
        return merge(lf, rg);
    }

    void upd(int p, int L, int R, int i, int j, T val) {
        if (i > R || j < L) return;
        if (i <= L && j >= R) st[p] = {val, val, 1};
        else {
            int m = (L+R)/2, l = p*2, r = l+1;
            upd(l, L, m, i, j, val);
            upd(r, m+1, R, i, j, val);
            st[p] = merge(st[l], st[r]);
        }
    }
};

const int MX = 1e5+5;
vector<int> g[MX];
int par[MX], dep[MX], sz[MX];
int pos[MX], top[MX];
string arr;
string value;
int idx;

int pre(int u, int p, int d) {
    par[u] = p; dep[u] = d;
    int aux = 1;
    for (auto &v : g[u]) {
        if (v != p) {
            aux += pre(v, u, d+1);
            if (sz[v] >= sz[g[u][0]]) swap(v, g[u][0]);
        }
    }
    return sz[u] = aux;
}

void hld(int u, int p, int t) {
    arr[idx] = value[u];
    pos[u] = idx++;
    top[u] = t < 0 ? t = u : t;
    for (auto &v : g[u]) {
        if (v != p) {
            hld(v, u, t);
            t = -1;
        }
    }
}

segtree st;

void build(int n, int root) {
    idx = 0;
    arr.resize(n);
    pre(root, root, 0);
    hld(root, root, -1);
    st = segtree(arr);
}

bool query(int u, int v) {
    node hashU = {0, 0, 0}, hashV = {0, 0, 0};
    while (top[u] != top[v]) {
        if (dep[top[u]] > dep[top[v]]){
            swap(u, v);
            swap(hashU, hashV);
        }
        hashV = merge(st.query(pos[top[v]], pos[v]), hashV);
        v = par[top[v]];
    }
    if (dep[u] > dep[v]){
        swap(u, v);
        swap(hashU, hashV);
    }
    hashV = merge(st.query(pos[u], pos[v]), hashV);
    swap(hashU.hs, hashU.inv);
    node ans = merge(hashU, hashV);
    return (ans.hs == ans.inv);
}

void upd(int u, T val) {
    st.upd(pos[u], val);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);


    int n, m;
    cin >> n >> m;
  calc_xpow(n);
    cin >> value;

    forn(i, 0, n-1){
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }

    build(n, 0);

    forn(i, 0, m){
        int t; cin >> t;
        if(t == 1){
            int u, v;
            cin >> u >> v;
            u--, v--;
            if(query(u, v))cout << "Yes" << endl;
            else cout << "No" << endl;
        }else{
            int u;
            char x;
            cin >> u >> x;
            u--;
            upd(u, x);
        }
    }

}

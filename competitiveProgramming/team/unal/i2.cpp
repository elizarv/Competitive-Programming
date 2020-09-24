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

typedef int T;
struct SegTree {
  int n;
  vector<T> st;
  T neutro = 0;

  SegTree(int _n){
    n = _n;
    st.assign(n*4, 0);
  }

  T query(int i, int j) { return query(1, 0, n-1, i, j); }

  T query(int p, int L, int R, int i, int j){
    if(i > R|| j < L)return neutro;
    if(i <= L && j >= R)return st[p];
    int m = (L+R)/2, l = p*2, r = l+1;
    T lf = query(l, L, m, i, j);
    T rg = query(r, m+1, R, i, j);
    return max(lf, rg);
  }

  void update(int i, T val){ return update(1, 0, n-1, i, val); }

  void update(int p, int L, int R, int i, T val){
    if(i > R || i < L)return;
    if(L == R)st[p] = val;
    else{
      int m = (L+R)/2, l = p*2, r = l+1;
      update(l, L, m, i, val);
      update(r, m+1, R, i, val);
      st[p] = max(st[l], st[r]);
    }
  }

};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int n, x;
  cin >> n;
  
  map<int, vector<int>> H;
  forn(i, 0, n){
    cin >> x;
    H[-x].pb(i);
  }

  SegTree st(n);

  for(auto x: H){
    int h = x.F;
    for(auto id: x.S){
      int l = 0, r = id-1;
      // debug(id, "query", st.query(l, r));
      if(st.query(l, r)){
        while(l <= r){
          int m = (l+r)/2;
          int mx = st.query(l, r);
          int q = st.query(m, r);
          // debug(id, l, m, r, q, mx);
          if(q && q < mx)l = m;
          else r = m-1;
        }
      }
        r++;
        debug(id, r);

    }
    for(auto id: x.S)st.update(id, -h);
  }

  


  
}
#include <bits/stdc++.h>
using namespace std;
void debug() {cout<<endl;}
template<typename T,typename... arribargs>
void debug(T a,arribargs... args) {cout<<a<<" ";debug(args...);}
#define forn(i,a,b) for(int i=a,gon=b;i<gon;++i)
#define pb push_back
#define F first
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;


const int N = 100005;
map<int, vector<int>> mapa;

struct SegmentTree {
    vector<int> st;
    int n, neutro = 0;

    SegmentTree(vector<int> &arr) {
        n = arr.size();
        st.assign(n << 2, 0);
        build(1, 0, n - 1, arr);
    }

    int query(int i, int j) { return query(1, 0, n - 1, i, j); }
    void update(int i, int j, int val) { update(1, 0, n - 1, i, j, val); }

    int left (int p) { return p << 1; }
    int right (int p) { return (p << 1) | 1; }

    void build(int p, int L, int R, vector<int> &arr) {
        if (L == R) st[p] = arr[L];
        else {
            int m = (L+R)/2, l = left(p), r = right(p);
            build(l, L, m, arr);
            build(r, m+1, R, arr);
            st[p] = __gcd(st[l], st[r]);
        }
    }
    
    int query(int p, int L, int R, int i, int j) {
        if (i > R || j < L) return neutro;
        if (i <= L && j >= R) return st[p];
        int m = (L+R)/2, l = left(p), r = right(p);
        l = query(l, L, m, i, j);
        r = query(r, m+1, R, i, j);
        return __gcd(l, r);
    }

    void update(int p, int L, int R, int i, int j, int val) {
        if (i > R || j < L) return;
        if (i <= L && j >= R) st[p] = val;
        else {
            int m = (L+R)/2, l = left(p), r = right(p);
            update(l, L, m, i, j, val);
            update(r, m+1, R, i, j, val);
            st[p] = __gcd(st[l], st[r]);
        }
    }
};




int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int n, m, x, y;

  cin >> n;

  vector<int> v(n);

  forn(i, 0, n){
      cin >> v[i];
      if(!mapa.count(v[i]))mapa[v[i]] = vector<int>();
      mapa[v[i]].pb(i);
  }

  SegmentTree st = SegmentTree(v);

  cin >> m;

  forn(i, 0, m){
      cin >> x >> y;
      x--, y--;
      int g = st.query(x, y);
      int l = lower_bound(mapa[g].begin(), mapa[g].end(), x)-mapa[g].begin();
      int r = upper_bound(mapa[g].begin(), mapa[g].end(), y)-mapa[g].begin();
      int div = 0;
	  div = r-l;
      cout << (y-x+1)-div << endl;
  }



}


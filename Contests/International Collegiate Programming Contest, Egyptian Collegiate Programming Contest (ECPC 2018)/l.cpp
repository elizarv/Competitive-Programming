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
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;

typedef int T;

struct segtree {
  vector<T> st;
  vector<bool> lazy;
  int n;
  T neutro = 0;

  segtree(const int &v) {
    n = v;
    st.assign(n * 4, neutro);
    lazy.assign(n * 4, 0);
    build(1, 0, n - 1);
  }
  
  void build(int p, int L, int R) {
    if (L == R) st[p] = (L != 0);
    else {
      int m = (L + R) / 2, l = p * 2, r = l + 1;
      build(l, L, m);
      build(r, m + 1, R);
      st[p] = (st[l] + st[r]);
    }
  }

  void propagate (int p, int L, int R, bool val) {
    if (val == false) return;
    st[p] *= -1;
    lazy[p] = false;
    if (L == R) return;
    int l = p * 2, r = l + 1;
    lazy[l] = !lazy[l];
    lazy[r] = !lazy[r];
  }
  
  T query (int i, int j) {return query(1, 0, n - 1, i, j);}

  void upd(int i, int j, T val) {return upd(1, 0, n - 1, i, j, val);}

  T query(int p, int L, int R, int i, int j) {
    if (i > R || j < L) return neutro;
    propagate(p, L, R, lazy[p]);
    if (i <= L && j >= R) return st[p];
    int m = (L + R) / 2, l = p * 2, r = l + 1;
    T lf = query(l, L, m, i, j);
    T rg = query(r, m + 1, R, i, j);
    return (lf + rg);
  }
  
  void upd(int p, int L, int R, int i, int j, bool val) {
    if (i > R || j < L) return;
    propagate(p, L, R, lazy[p]);
    if (i <= L && j >= R) propagate(p, L, R, val);
    else {
      int m = (L + R) / 2, l = p * 2, r = l + 1;
      upd(l, L, m, i, j, val);
      upd(r, m + 1, R, i, j, val);
      st[p] = (st[l] + st[r]);
    }
  }
};

const int N = 1e5+5;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
	freopen("reflection.in", "r" , stdin);

	int t;
	cin >> t;
	while(t--){
		int q;
		cin >> q;
		segtree st(N);

		while(q--){
			int x;
			cin >> x;
			cout << st.query(0, x) << endl;
			st.upd(x+1, N, true);
		}
	}
  
}
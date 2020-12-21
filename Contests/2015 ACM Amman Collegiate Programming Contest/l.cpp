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

const int N = 1005, inf = 1e9;
int n, k;
string s;

typedef int T;

struct segtree {
    vector<T> st;
    int n; T neutro = inf;

    segtree(const int& sz) {
        n = sz;
        st.assign(n*4, 0);
    }

    T query(int i, int j) { return query(1, 0, n-1, i, j); }
    void upd(int i, int j, T val) { upd(1, 0, n-1, i, j, val); }
    
    T query(int p, int L, int R, int i, int j) {
        if (i > R || j < L) return neutro;
        if (i <= L && j >= R) return st[p];
        int m = (L+R)/2, l = p*2, r = l+1;
        T lf = query(l, L, m, i, j);
        T rg = query(r, m+1, R, i, j);
        return min(lf, rg);
    }

    void upd(int p, int L, int R, int i, int j, T val) {
        if (i > R || j < L) return;
        if (i <= L && j >= R) st[p] = val;
        else {
            int m = (L+R)/2, l = p*2, r = l+1;
            upd(l, L, m, i, j, val);
            upd(r, m+1, R, i, j, val);
            st[p] = min(st[l], st[r]);
        }
    }

};


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while(t--){
    cin >> n >> k >> s;

    segtree st(n+1);
    int alt = n;

    vector<int> dp(n+1);
    dp[n] = 0;

    for(int i = n-1; i >= 0; i--){
      dp[i] = inf;
      dp[i] = min(dp[i], dp[i+1] + 1);
      int lim = min(n, i+k);
      if(alt < lim)dp[i] = min(dp[i], st.query(alt+1, lim)+1);
      st.upd(i, i, dp[i]);
      if(i && s[i] == s[i-1])alt = i;
    }

    cout << st.query(0, 0)-1 << endl;

  }
  
}

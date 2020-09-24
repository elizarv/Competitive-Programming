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

const int N = 26;

struct SegmentTree {
    vector<int> st, lazy;
    int n, neutro = -1;
    
    SegmentTree(){}

    SegmentTree(vector<int> &arr) {
        n = arr.size();
        st.assign(n << 2, 0);
        lazy.assign(n << 2, neutro);
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
            st[p] = st[l] + st[r];
        }
    }
    
    void propagate(int p, int L, int R, int val) {
        if (val == neutro) return;
        st[p] = val*(R-L+1);
        lazy[p] = neutro;
        if (L != R) {
            lazy[left(p)] = val;
            lazy[right(p)] = val;
        }
    }
    
    int query(int p, int L, int R, int i, int j) {
        propagate(p, L, R, lazy[p]);
        if (i > R || j < L) return 0;
        if (i <= L && j >= R) return st[p];
        int m = (L+R)/2, l = left(p), r = right(p);
        l = query(l, L, m, i, j);
        r = query(r, m+1, R, i, j);
        return l+r;
    }

    void update(int p, int L, int R, int i, int j, int val) {
        propagate(p, L, R, lazy[p]);
        if (i > R || j < L) return;
        if (i <= L && j >= R) propagate(p, L, R, val);
        else {
            int m = (L+R)/2, l = left(p), r = right(p);
            update(l, L, m, i, j, val);
            update(r, m+1, R, i, j, val);
            st[p] = st[l] + st[r];
        }
    }
};


vector<SegmentTree> segs(N);

void f(int& i, int& l, int& r, int& ini){
    int cnt = segs[i].query(l, r);
    segs[i].update(l, r, 0);
    if(!cnt)return;
    segs[i].update(ini, ini+cnt-1, 1);
    ini += cnt;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int n, q, l, r, k;

  cin >> n >> q;

  string s;
  cin >> s;


  forn(i, 0, N){
      vector<int> arr(n, 0);
      forn(j, 0, n)if(s[j]-'a' == i)arr[j] = 1;
      segs[i] = SegmentTree(arr);
  }


// 0 : 26 -> 0
// 1 : 0 -> 26
  forn(i, 0, q){
      cin >> l >> r >> k;
      l--, r--;
      if(k){
          int ini = l;
          forn(j, 0, N){ 
              f(j, l, r, ini);
          }
      }else {
          int ini = l;
          for(int j = N-1; j >= 0; j--){
              f(j, l, r, ini);
          }
      }
  }

  forn(i, 0, n){
      forn(j, 0, N){
          int let = segs[j].query(i, i);
          if(let){
              s[i] = j+'a';
              break;
          }
      }
  }

  cout << s << endl;



  

}

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


struct node{
  int sz;

  vector<int> vals;
  node(){
  	sz = 0;
  }
  void updt(int p){
    vals.pb(p);
    sz++;
  }

};

struct segTree {
  int n;
  vector<node> st;
  int neutro = 0;

  segTree(vector<pii>& arr){
    n = arr.size();
    st.assign(4*n, node());
    build(1, 0, n-1, arr);
  }

  void build(int p, int L, int R, vector<pii>& arr){
    if(L == R){
      st[p].updt(arr[L].S);
    }else{
      int m = (L+R)/2, l = p*2, r = l+1;
      build(l, L, m, arr);
      build(r, m+1, R, arr);
      merge(p, l, r);
    }
  }

  void merge(int p, int l, int r){
    node &L = st[l];
    node &R = st[r];
  	int a  = L.sz;
  	int b = R.sz;
    int i = 0, j = 0;
    while(i < a && j < b){
      if(st[l].vals[i] < st[r].vals[j]){
        st[p].updt(L.vals[i]);
        i++;
      }else{
        st[p].updt(R.vals[j]);
        j++;
      }
    }
    while(i < a){
      st[p].updt(L.vals[i]);
      i++;
    }
    while(j < b){
      st[p].updt(R.vals[j]);
        j++;
    }
  }
  

  // ll getSum(int p, int val){
  //   auto &arr = st[p].vals;
  //   int x = upper_bound(arr.begin(), arr.end(), val)-arr.begin();
  //   return st[p].getsum(x);
  // }

  ll query(int i, int j, int val){ return query(1, 0, n-1, i, j, val); }

  ll query(int p, int L, int R, int i, int j, int val){
    if(j < L || i > R)return neutro;
    if (i <= L && j >= R) return 0;
    int m = (L+R)/2, l = 2*p, r = l+1;
    ll lf = query(l, L, m, i, j, val);
    ll rg = query(r, m+1, R, i, j, val);
    return lf + rg;
  }

  
};

const int N = 1e5+5, inf = 1e9+1;
ll bit[N];

void add(int k, int val) {
	    for (; k <= N; k += k&-k) bit[k] += val;
	}
	
	ll rsq(int k) {
	    ll sum = 0;
	    for (; k >= 1; k -= k&-k) sum += bit[k];
	    return sum;
	}
	
	ll rsq(int i, int j) { return rsq(j) - rsq(i-1); }

int main() {
  // g++ -pthread -Wall -Wshadow -std=c++17 -o main k.cpp && ./main < k.txt
  ios::sync_with_stdio(0); cin.tie(0);

  int n, x, y;
  cin >> n;
  vector<pii> v(n);
  vector<int> Y(n+1);
  Y.pb(-1);
  forn(i, 0, n){
    cin >> v[i].F >> v[i].S;
    Y[i] = v[i].S;
  }

  sort(v.begin(), v.end());
  sort(Y.begin(), Y.end());


  vector<int> cnt(n, 0);
  
  for(int i = n-1; i >= 0; i--){
  	int y = v[i].S;
    int pos = lower_bound(Y.begin(), Y.end(), v[i].S-1)-Y.begin();
    add(pos, 1);
  	cnt[i] = rsq(pos+1, n+1);
  }
  
  segTree st(v);
  
  ll ans = 0;

  forn(i, 1, n){
  	ans += st.query(0, i-1, v[i].S);
    int pos = upper_bound(v.begin(), v.end(), make_pair(v[i].F, inf))-v.begin();
  }
  
  cout << ans << endl;




}
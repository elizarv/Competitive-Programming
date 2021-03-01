//Problem H from https://codeforces.com/gym/102318
#include <bits/stdc++.h>
using namespace std;
void debug() {cout<<endl;}
template<typename T,typename... Args>
void debug(T a,Args... args) {cout<<a<<" ";debug(args...);}
#define forn(i,a,b) for(int i=a,gon=b;i<gon;++i)
#define pb push_back
#define F first
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 997;
const int N = 50001;

namespace fft {
  typedef long long ll;
  const double PI = acos(-1.0);
  vector<int> rev;
  struct pt {
    double r, i;
    pt(double r = 0.0, double i = 0.0) : r(r), i(i) {}
    pt operator + (const pt & b) { return pt(r + b.r, i + b.i); }
    pt operator - (const pt & b) { return pt(r - b.r, i - b.i); }
    pt operator * (const pt & b) { return pt(r * b.r - i * b.i, r * b.i + i * b.r); }
  };
  void fft(vector<pt> &y, int on) {
    int n = y.size();
    for(int i = 1; i < n; i++) if(i < rev[i]) swap(y[i], y[rev[i]]);
    for(int m = 2; m <= n; m <<= 1) {
      pt wm(cos(-on * 2 * PI / m), sin(-on * 2 * PI / m));
      for(int k = 0; k < n; k += m) {
        pt w(1, 0);
        for(int j = 0; j < m / 2; j++) {
          pt u = y[k + j];
          pt t = w * y[k + j + m / 2];
          y[k + j] = u + t;
          y[k + j + m / 2] = u - t;
          w = w * wm;
        }
      }
    }
    if(on == -1)
      for(int i = 0; i < n; i++) y[i].r /= n;
  }
  vector<ll> mul(vector<ll> &a, vector<ll> &b) {
    int n = 1, la = a.size(), lb = b.size(), t;
    for(n = 1, t = 0; n <= (la+lb+1); n <<= 1, t++); t = 1<<(t-1);
    vector<pt> x1(n), x2(n);
    rev.assign(n, 0);
    for(int i = 0; i < n; i++) rev[i] = rev[i >> 1] >> 1 |(i & 1 ? t : 0);
    for(int i = 0; i < la; i++) x1[i] = pt(a[i], 0);
    for(int i = 0; i < lb; i++) x2[i] = pt(b[i], 0);
    fft(x1, 1); fft(x2, 1);
    for(int i = 0; i < n; i++) x1[i] = x1[i] * x2[i];
    fft(x1, -1);
    vector<ll> sol(N);
    for(int i = 0; i < N; i++){
      sol[i] = x1[i].r + 0.5;
      sol[i] %= MOD;
    }
    return sol;
  }
}

vector<ll> fastpow(vector<ll> b, ll e){
  vector<ll> aux(N, 0);
  aux[0] = 1;
  if(!e)return aux;
  if(e&1){
    aux = fastpow(b, e-1);
    return fft::mul(aux, b);
  }
  b = fastpow(b, e>>1);
  return fft::mul(b, b);
}


int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int t, n, x, y;
  scanf("%d", &t);

  while(t--){
    scanf("%d", &n);
    vector<ll> a(N);
    forn(i, 0, n){
      scanf("%d.%d", &x, &y);
      x = x*100+y;
      a[x] += 1;
    }
    int k, q;
    scanf("%d %d", &k, &q);
    vector<ll> ans = fastpow(a, k);

    forn(i, 0, q){
      scanf("%d.%d", &x, &y);
      x = x*100+y;
      printf("%lld\n", ans[x]);
    }
     printf("\n");
  }


}

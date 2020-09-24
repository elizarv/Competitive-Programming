//https://codeforces.com/group/j1UosVRZar/contest/287404/problem/F
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

const double PI = acos(-1.0);
double eps = 1e-6;

  struct pt {
    double r, i;
    pt(double r = 0.0, double i = 0.0) : r(r), i(i) {}
    pt operator + (const pt & b) { return pt(r + b.r, i + b.i); }
    pt operator - (const pt & b) { return pt(r - b.r, i - b.i); }
    pt operator * (const pt & b) { return pt(r * b.r - i * b.i, r * b.i + i * b.r); }
  };

namespace fft {
  typedef long long ll;
  vector<int> rev;
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
  int mul(vector<pt> &a, vector<pt> &b, int wc) {
    int n = 1, la = a.size(), lb = b.size(), t;
    for(n = 1, t = 0; n <= (la+lb+1); n <<= 1, t++); t = 1<<(t-1);
    vector<pt> x1(n), x2(n);
    rev.assign(n, 0);
    for(int i = 0; i < n; i++) rev[i] = rev[i >> 1] >> 1 |(i & 1 ? t : 0);
    for(int i = 0; i < la; i++) x1[i] = a[i];
    for(int i = 0; i < lb; i++) x2[i] = b[i];
    fft(x1, 1); fft(x2, 1);
    for(int i = 0; i < n; i++) x1[i] = x1[i] * x2[i];
    fft(x1, -1);
    int ans = 0;
    for(int i = lb-1; i < la; i++) ans += (abs(real(x1[i].r)-(lb-wc)) < eps);
    return ans;
  }
}


double val[27];

void precalc(){
  forn(i, 0, 26){
    val[i] = 2*PI*i/26;
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

int n, m;
string s, t;

precalc();

while(cin >> s >> t){
  n = s.size();
  m = t.size();

  vector<pt> a(n), b(m);
  forn(i, 0, n){
    a[i] = pt(cos(val[s[i]-'a']), sin(val[s[i]-'a']));
  }
  int wc = 0;
  forn(i, 0, m){
    if(t[i] == '?'){
      b[i] = pt(0, 0);
      wc++;
    }else b[i] =  pt(cos(val[t[i]-'a']), -sin(val[t[i]-'a']));
  }
  reverse(b.begin(), b.end());

  int ans = fft::mul(a, b, wc);
  cout << ans << endl;
  
}
  
  
}

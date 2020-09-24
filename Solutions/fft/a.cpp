//https://www.spoj.com/problems/ADAMATCH/en/

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
 
namespace fft {
    struct pt {
        double r, i;
        pt(double r = 0.0, double i = 0.0) : r(r), i(i) {}
        pt operator + (const pt &b) { return pt(r+b.r, i+b.i); }
        pt operator - (const pt &b) { return pt(r-b.r, i-b.i); }
        pt operator * (const pt &b) { return pt(r*b.r - i*b.i, r*b.i + i*b.r); }
    };
    vector<int> rev;
 
    void fft(vector<pt> &y, int on) {
        int n = y.size();
        for (int i = 1; i < n; i++)
            if (i < rev[i]) swap(y[i], y[rev[i]]);
        for (int m = 2; m <= n; m <<= 1) {
            double ang = -on * 2 * PI / m;
            pt wm(cos(ang), sin(ang));
            for (int k = 0; k < n; k += m) {
                pt w(1);
                for (int j = 0; j < m / 2; j++) {
                    pt u = y[k + j];
                    pt t = w * y[k + j + m / 2];
                    y[k + j] = u + t;
                    y[k + j + m / 2] = u - t;
                    w = w * wm;
                }
            }
        }
        if (on == -1) for (int i = 0; i < n; i++) y[i].r /= n;
    }
 
    void mul(vector<ll> &a, vector<ll> &b, vector<ll> &ans) {
        int n = 1, t = 0, la = a.size(), lb = b.size();
        for (; n <= (la+lb+1); n <<= 1, t++); t = 1<<(t-1);
        vector<pt> x1(n), x2(n);
        rev.assign(n, 0);
        for (int i = 0; i < n; i++) rev[i] = rev[i >> 1] >> 1 | (i & 1 ? t : 0);
        for (int i = 0; i < la; i++) x1[i] = pt(a[i], 0);
        for (int i = 0; i < lb; i++) x2[i] = pt(b[i], 0);
        fft(x1, 1); fft(x2, 1);
        for (int i = 0; i < n; i++) x1[i] = x1[i] * x2[i];
        fft(x1, -1);
        for (int i = lb-1; i < la; i++) ans[i] += round(x1[i].r);
    }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  string s, t;
  cin >> s >> t;

  ll n, m;
  n = s.size();
  m = t.size();

    vector<char> let = {'A', 'C', 'T', 'G'};

    vector<ll> ans(n, 0);

    forn(i, 0, 4){
        vector<ll> a(n, 0), b(m, 0);
        forn(j, 0, n){
            if(s[j] == let[i]) a[j] = 1;
        }
        forn(j, 0, m){
            if(t[j] == let[i]) b[j] = 1;
        }
        reverse(b.begin(), b.end());
        fft::mul(a, b, ans);
    }

    ll mx = 0;
    forn(i, m-1, n){
        mx = max(mx, ans[i]);
    }

    cout << m-mx << endl;

  
}

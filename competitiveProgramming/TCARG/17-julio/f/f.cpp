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

ll x, y, n;

ll f(ll t){
    ll tot = t*(t+1)*2+1;
    ll arriba = x-t;
    ll abajo = x+t-n+1;
    ll izq = y-t;
    ll der = y+t-n+1;
    if(izq < 0)tot -= izq*izq;
    if(der > 0)tot -= der*der;
    //debug(t, tot, arriba, abajo, der, izq);
    if(arriba < 0){
        tot -= arriba*arriba;
        arriba = abs(arriba);
        ll d1 = arriba-y-1;
        ll d2 = arriba-n+y;
        if(d1 > 0)tot += d1*(d1+1)/2;
        if(d2 > 0)tot += d2*(d2+1)/2;
    }
    if(abajo > 0){
        tot -= abajo*abajo;
        ll d1 = abajo-y-1;
        ll d2 = abajo-n+y;
        if(d1 > 0)tot += d1*(d1+1)/2;
        if(d2 > 0)tot += d2*(d2+1)/2;
    }
    return tot;
}


int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  ll c;

  cin >> n >> x >> y >> c;
  x--, y--;

  ll l = 0, r = 2*n+2;


  while(l < r){
      ll m = (l+r)/2;
      ll ans = f(m);
      if(ans >= c)r = m;
      else l = m+1;
  }

  cout << l << endl;




}


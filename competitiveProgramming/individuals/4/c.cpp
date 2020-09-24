#include <bits/stdc++.h>
using namespace std;
void debug() {cout<<endl;}
template<typename T,typename... Args>
void debug(T x,Args... args) {cout<<x<<" ";debug(args...);}
#define forn(i,a,b) for(int i=a;i<b;++i)
#define pb push_back
#define F first
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;


int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int t;
  cin >> t;
  while(t--){
    ll a, b, n, m;
    cin >> a >> b >> n >> m;
    bool ans = true;
    int dif = abs(n-m);
    if(n > m){
      if(a > b){
        if(a < dif)ans = false;
        a -= dif;
      }else{
        if(b < dif)ans = false;
        b -= dif;
      }
      n -= dif;
    }else if(m > n){
      if(a > b){
        if(b < dif)ans = false;
        b -= dif;
      }else{
        if(a < dif)ans = false;
        a -= dif;
      }
      m -= dif;
    }
    if(b < n)ans = false;
    if(a < m)ans = false;
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
  }

    
  
}


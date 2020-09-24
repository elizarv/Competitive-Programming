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

  int n;
  cin >> n;

  vector<ll> pot(n);
  pot[0] = 1;
  forn(i, 1, n){
    pot[i] = pot[i-1]*4;
  }
  
  int x = n-2;

  ll ans = 0;
  ans = 2*4*3*pot[x-1];

  if(x > 1){
    ans += (x-1)*4*3*3*pot[x-2];
  }

  cout << ans << endl;

    
  
}


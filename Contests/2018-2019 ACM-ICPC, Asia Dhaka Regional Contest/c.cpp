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
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;

const int MX = 1e6;
const ll mod = 1e7+7;
bool marked[MX+1];
vector<int> primes;

void sieve() {
  marked[0] = marked[1] = true;
  forn(i, 2, MX+1){
    if(marked[i])continue;
    primes.pb(i);
    for(ll j = 1ll*i*i; j <= MX; j += i){
      marked[j] = true;
    }
  }
}

ll sum(int n){
  ll ans = 1ll*n*(n+1)/2;
  return ans%mod;
}

ll getdiv(int p, int n){
  ll ans = 0;
  while(n){
    ans += n/p;
    n /= p;
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  sieve();

  int n;
  while(cin >> n){
    if(!n)break;
    ll ans = 1;
    for(auto &p: primes){
      ll div = getdiv(p, n) + 1;
      ans = ans*sum(div)%mod;
    }
    cout << ans << endl;
  }
 
}

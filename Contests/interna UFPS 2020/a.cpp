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

const int MX = 1e6+5;
int prime[MX+1];
bool isprime[MX+1];
ll cnt = 0;

void sieve(int n) {
    for (int i = 2; i <= n; i++) {
        if (prime[i]) continue;
        prime[i] = i;
        cnt++;
        isprime[i] = true;
        for (ll j = 1ll*i*i; j <= MX; j += i) {
            if (!prime[j]) prime[j] = i;
        }
    }
}

int subs(ll x, ll y, int mod){
  if(x-y < 0)return x-y+mod;
  return x-y;
}

int add(ll x, ll y, int mod){
  if(x+y < mod)return x+y;
  return x+y-mod;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, s, p, c;
  ll t;
  cin >> n >> t >> s >> p >> c;
  sieve(n);

  int r = t/n;

  ll movesS = 0, movesP = 0, movesC = 0;

  if(t >= n){
    movesP = r*cnt;
    movesC = r*(n-cnt-1);
  }

  movesS = t%n;
  movesP %= n;
  movesC %= n;

  p = (p-movesP+n)%n;
  c = (c+movesC)%n;

  forn(i, 0, movesS){
    s = subs(s, 1, n);
    int aux = !s ? n : s;
    if(isprime[aux])p = subs(p, 1, n);
    else if(aux != 1)c = add(c, 1, n);
  }

  s = !s ? n : s;
  p = !p ? n : p;
  c = !c ? n : c;

  cout << s <<  " " <<  p << " " << c << endl;




  
}

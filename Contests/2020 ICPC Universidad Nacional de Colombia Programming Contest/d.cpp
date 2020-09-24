//https://codeforces.com/gym/102700
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

const int M = 1e9+7;

int m;
vector<int> mult(vector<int> &a, vector<int> &b){
    vector<int> ans(m, 0);
    forn(i, 0, m){
        forn(j, 0, m){
            ans[(i+j)%m] = (ans[(i+j)%m]+(1ll*a[i]*b[j]) % M) % M;
        }
    }

    return ans;
}


int add(int x, int y){
  if(x+y > M)return 1ll*x+y-M;
  return x+y;
}

int expmod(int b, int e){
  int ans = 1;
  while(e){
    if(e&1) ans = (1ll*ans*b)%M;
    b = (1ll*b*b)%M;
    e /= 2;
  }
  return ans;
}

vector<int> exp(vector<int> &b, int e){
  vector<int> ans(m, 0);
  ans[0] = 1;
  while(e){
    if(e&1)ans = mult(ans, b);
    b = mult(b, b);
    e /= 2;
  }
  return ans;
}

ll mulmod(ll a, ll b, ll m = M){
  ll r = a*b-(ll)((long double)a*b/m+.5)*m;
  return r < 0 ? r+m : r;
}


int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  // g++ -pthread -Wall -Wshadow -std=c++17 -o main d.cpp
  //./main < d.txt

  int n, k;

  cin >> n >> k >> m;

  int mult = 0;
  vector<int> b(m, 0);
  forn(i, 1, k+1){
    if((i % m) != 0)b[i%m]++;
    else mult++;
  }

  vector<int> ans = exp(b, n);
  /*
  forn(i, 0, SZ(ans)){
    debug(i, ans[i]);
  }
  */
  ll p = ans[0];

  ll q = expmod(k-mult, n);

  //debug(p, q);

  cout << mulmod(p, expmod(q, M-2)) << endl;



  
}
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

int add(int a, int b, int mod){
  if(a+b >= mod)return a+b-mod;
  return a+b;
}

int subs(int a, int b, int mod){
  if(a-b < 0)return a-b+mod;
  return a-b;
}

int mult(int a, int b, int mod){
  return (1ll*a*b)%mod;
}

const int P[] = {257, 359};
const int M[] = {(int)1e9+7,(int)1e9+9};

vector<int> pot[2];

void pre(int n){
  forn(i, 0, 2){
    pot[i] = vector<int>(n+1, 1);
    forn(j, 1, n+1){
      pot[i][j] = mult(pot[i][j-1], P[i], M[i]);
    }
  }
}

struct Hashing {
  vector<int> h[2];
  Hashing(string& s){
    int n = s.size();
    forn(i, 0, 2){
      h[i] = vector<int>(n+1, 0);
      forn(j, 1, n+1){
        h[i][j] = add(s[j-1], mult(h[i][j-1], P[i], M[i]), M[i]);
      }
    }
  }

  ll getHash(int l, int r){
    int val[2];
    forn(i, 0, 2){
      val[i] = subs(h[i][r], mult(h[i][l], pot[i][r-l], M[i]), M[i]);
    }
    return ((1ll*val[0]) << 32)+ val[1];
  }
};

set<ll> dif;

int manacher(string s){
  int n = s.size();
  vector<int> P(n, 0);
  Hashing h(s);
  int c = 0, R = 0;
  forn(i, 1, n-1){
    int L = c-i+c;
    if(R > i)P[i] = min(R-i, P[L]);
    while(s[i-1-P[i]] == s[i+1+P[i]]){
      P[i]++;
      if(i%2 == 0 && P[i] > 1 && (P[i]&1)){
        dif.insert(h.getHash(i-P[i], i+1+P[i]));
      }
    }
    if(P[i]+i > R){
      c = i;
      R = i+P[i];
    }
  }
  return dif.size();
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int n; cin >> n;
  string s = "%";
  char c;
  forn(i, 0, n){
    cin >> c;
    s += "#";
    s += c;
  }
  s += "#$";
  pre(s.size());
  cout << manacher(s) << endl;
  
}
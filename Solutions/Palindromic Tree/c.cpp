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

const int alfa = 26;
const char L = 'a';
const int mod = 51123987;

struct node {
  map<char, int> next;
  int link, len, cnt, occ;
  node(int x, int l = 0, int c = 0): len(x), link(l), cnt(c), occ(c){}
};

int add(int a, int b){
  if(a + b < mod)return a + b;
  return a + b - mod;
}

int subs(int a, int b){
  if(a - b < 0)return a - b + mod;
  return a - b;
}

int mul(int a, int b){
  if(1ll * a * b < mod)return a * b;
  return (1ll * a * b) % mod;
}

int sum(int a){
  a = mul(a, subs(a, 1));
  return a;
}

const int N = 1e7;
int ans[2][N];

bool good(char c){
  if(c == '%' || c == '$' || c == '#')return false;
  return true;
}

int manacher(string& s) {
    int n = s.size();
    int tot = 0;
    vector<int> p(n, 0);
    int c = 0, r = 0;
    for (int i = 1; i < n-1; i++) {
        int j = c - (i-c) ;
        if (r > i) p[i] = min(r-i , p[j]);
        while (s[i+1+p[i]] == s[i-1-p[i]]){
            p[i] = add(p[i], 1);
        }
        if (i+p[i] > r) {
            c = i;
            r = i+p[i];
        }
    }
    forn(i, 0, n){
      cout << p[i] << " ";
    }debug();
    return tot;
}


ll invmod() {
    int inv1 = 1;
    int inv2 = mod - (mod/2) * (inv1) % mod;
    return inv2;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int n;
  string s = "%#";
  cin >> n;
  char c;
  forn(i, 0, n){
    cin >> c;
    s = s + c + '#';
  }
  s += "$";
  n = s.size();

  int tot = sum(manacher(s));

  int pre = 0, non = 0;

  forn(j, 0, 2){
    for(int i = 2; i < n-1; i += 2){
      cout << ans[j][i] <<" ";
    }  debug();
  }

  for(int i = 2; i < n-1; i += 2){
    int aux = mul(pre, ans[0][i]);
    non = add(non, aux);
    debug(i, s[i], pre, aux, non);
    pre = add(pre, ans[1][i]);
  }

  non = mul(2, non);
  non = subs(tot, non);
  non = mul(non, invmod());
  cout << non << endl;


}
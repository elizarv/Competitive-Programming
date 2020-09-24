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


long long p[] = {257, 359};
long long mod[] = {1000000007, 1000000009};
long long X = 1000000010;

struct hashing {
	vector<long long> h[2], pot[2];
	int n;

	hashing(string s) {
		n = s.size();
		for (int i = 0; i < 2; ++i) {
			h[i].resize(n + 1);
			pot[i].resize(n + 1, 1);
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j < 2; ++j) {
				h[j][i] = (h[j][i-1] * p[j] + s[i-1]) % mod[j];
				pot[j][i] = (pot[j][i-1] * p[j]) % mod[j];
			}
		}
	}
	//Hash del substring en el rango [i, j)
	long long hashValue(int i, int j) {
		long long a = (h[0][j] - (h[0][i] * pot[0][j-i] % mod[0]) + mod[0]) % mod[0];
		long long b = (h[1][j] - (h[1][i] * pot[1][j-i] % mod[1]) + mod[1]) % mod[1];
		return a*X + b;
	}
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  
  string s;
  cin >> s;
  s = s+s;
  
  int m;
  map<ll, int> mapa;
  cin >> m;
  forn(i, 0, m) {
    string p;
    cin >> p;
    hashing w(p);
    mapa[w.hashValue(0, k)] = i+1;
  }

  hashing H(s);


  forn(i, 0, k){
      set<ll> cnt;
      for(int j = i, it = 0; it < n; j+=k,it++){
          ll cur = H.hashValue(j, j+k);
          if(mapa.count(cur))cnt.insert(mapa[cur]);
      }
      
      if(cnt.size() == n){
          cout << "YES" << endl;
          for(int j = i, it = 0; it < n; j += k, it++){
              ll cur = H.hashValue(j, j+k);
              cout << mapa[cur] << " \n"[it+1 == n];
          }
          return 0;
      }
      
  }
  

  cout << "NO"<< endl;
  

}

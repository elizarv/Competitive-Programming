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


const int MAX = 200005;

ll p[] = {257, 359};
ll mod[] = {1000000007, 1000000009};
ll X = 1000000010;


ll add(ll a, ll b, ll& mod){
    return (a+b)%mod;
}


ll mul(int a, int b, ll& mod){
    return 1ll*a*b%mod;
}

ll sub(ll a, ll b, ll& mod){
    return add(a-b,mod, mod)%mod;
}

int pot[2][MAX];
void precalc(){
    forn(j, 0, 2){
        pot[j][0] = 1;
        forn(i, 1, MAX){
            pot[j][i] = mul(pot[j][i-1], p[j], mod[j]);
        }
    }
}

struct hashing {
	vector<ll> h[2];
	int n;

	hashing(string s) {
		n = s.size();
		for (int i = 0; i < 2; ++i) {
			h[i].resize(n + 1);
		}
        forn(j, 0, 2){
            for (int i = 1; i <= n; ++i) {
                h[j][i] = add(mul(h[j][i-1], p[j], mod[j]), s[i-1], mod[j]);
            }
        }
	}
	ll hashVal(int i, int j) {
		ll a = sub(h[0][j], mul(h[0][i], pot[0][j-i], mod[0]), mod[0]);
        ll b = sub(h[1][j], mul(h[1][i], pot[1][j-i], mod[1]), mod[1]);
		return a*X+b;
	}
};


int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  string s, t = "happiness";
  int k = t.size();
  cin >> s;
  int n = s.size();

  precalc();

  hashing h1 = hashing(s);
  hashing h2 = hashing(t);

    vector<int> occ;

  forn(i, 0, n-k+1){
      if(h1.hashVal(i, i+k) == h2.hashVal(0, k))occ.pb(i+1);
  }

  if(occ.size() > 2)cout << "NO" << endl;
  else{
      cout << "YES" << endl;
      if(!occ.size()){
          vector<int> C[26];
          forn(i, 0, n){
              C[s[i]-'a'].pb(i+1);
              if(C[s[i]-'a'].size() > 1){
                  cout << C[s[i]-'a'][0] << " " << C[s[i]-'a'][1] << endl;
                  return 0;
              }
          }
        cout << "1 2"<< endl;
      }else if(occ.size() == 1)cout << occ[0] << " " << occ[0]+1 << endl;
      else{
          cout << occ[0] << " " << occ[1]+1 << endl;
      }
      
  }

    
  
}


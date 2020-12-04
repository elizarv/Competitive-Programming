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


int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int n;
  cin >> n;
  string tot;
	vector<int> ini;
	int pos = 0;
  forn(i, 0, n){
    string s;
    ini.pb(pos);
    cin >> s;
    pos += s.size();
    for(auto x: s){
        tot.pb(x);
    }
  }

  int q;
  cin >> q;
  q--;

  int m = tot.size();

  int st = q/m;

  int mod = q%m;

  q = (ini[st] + mod) % m;

  cout << tot[q] << endl;

  
}
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

  int n, m, x;
  cin >> n >> m;
  int gcd = 0;
  forn(i, 0, n){
      cin >> x;
      gcd = __gcd(gcd, x);
  }
    if(x%gcd == 0)cout << "YES" << endl;
    else cout << "NO" << endl;
  
}


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
  // g++ -pthread -Wall -Wshadow -std=c++17 -o main m.cpp && ./main < m.txt

  int t;
  cin >> t;
  while(t--){
    int n, x;
    cin >> n;
    vector<int> v(n);
    map<int, vector<int>> mapa;
    forn(i, 0, n){
      cin >> x;
      v[i] = x;
      mapa[x].pb(i);
    }

ll ans = 0;
    forn(i, 0, n){
      forn(k, i+2, n){
        x = v[i]+v[k];
        if(x&1)continue;
        x /= 2;
        if(!mapa.count(x))continue;
        auto &mp = mapa[x];
        int j1 = upper_bound(mp.begin(), mp.end(), i)-mp.begin();
        int j2 = lower_bound(mp.begin(), mp.end(), k)-mp.begin();
        if(j1 == mp.size())continue;
        if(mp[j1] >= k)continue;
        j2--;
        if(mp[j2] <= i)continue;
        ans += (j2-j1+1);
      }
    }

    cout << ans << endl;
    
  }


}
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

int gcd(int a, int b){
  if(!b)return a;
  return gcd(b, a%b);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int x, y;

  while(cin >> x >> y){
    vector<pii> p;
    if(!x && !y)break;
    p.pb({x, y});
    while(cin >> x >> y){
      if(!x && !y)break;
      p.pb({x, y});
    }

    sort(p.begin(), p.end());

    int n = p.size();

    map<pii, set<int>> mapa;
    set<set<int>> ans;

    forn(i, 0, n){
      forn(j, 0, n){
        if(i == j)continue;
        int sx = p[i].F - p[j].F;
        int sy = p[i].S - p[j].S; 
        int g = gcd(sx, sy);
        sx /= g;
        sy /= g;
        mapa[{sx, sy}].insert(i);
        mapa[{sx, sy}].insert(j);
      }
    for(auto &x: mapa){
      if(x.S.size() > 2){
        ans.insert(x.S);
      }
    }
    mapa.clear();
    }

    if(!ans.size()){
      cout << "No lines were found"<< endl;
    }else{
      cout << "The following lines were found:" << endl;
      for(auto &st: ans){
        for(auto &x: st){
          cout  << "(" << setw(4) << p[x].F << "," << setw(4) << p[x].S << ")";
        }
        cout << endl;
      }

    }

  }


}
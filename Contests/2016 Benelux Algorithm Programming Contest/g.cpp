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

struct pt {
    int x, y, d;

    vector<pt> getCorner(){
        vector<pt> ans;
        ans.pb({x+d, y, 0});
        ans.pb({x-d, y, 0});
        ans.pb({x, y+d, 0});
        ans.pb({x, y-d, 0});
        return ans;
    }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  

  int n; cin >> n;
  vector<pt> p;
  int x, y, d;
  forn(i, 0, n){
      cin >> x >> y >> d;
      x *= 2;
      y *= 2;
      d *= 2;
      p.pb({x, y, d});
  }
  set<pt> st;
  for(auto pto: p[0].getCorner()){
      st.insert(pto);
  }
  
  forn(i, 1, n){
      
  }
  




}
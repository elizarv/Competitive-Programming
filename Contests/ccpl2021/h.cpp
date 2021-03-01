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

typedef int T;
struct pt {
  T x, y;
  pt operator + (pt p) { return {x+p.x, y+p.y}; }
  pt operator - (pt p) { return {x-p.x, y-p.y}; }
  pt operator * (pt p) { return {x*p.x-y*p.y, x*p.y+y*p.x}; }
  pt operator * (T d) { return {x*d, y*d}; }
  bool operator == (pt b) { return x == b.x && y == b.y; }
  bool operator != (pt b) { return !(*this == b); }
  bool operator < (const pt &o) const { return y < o.y || (y == o.y && x < o.x); }
  bool operator > (const pt &o) const { return y > o.y || (y == o.y && x > o.x); }
};


T cross(pt a, pt b) { return a.x*b.y - a.y*b.x; }
T orient(pt a, pt b, pt c) { return cross(b-a,c-a); }

bool validate(pt a, pt b, pt c){
  if(orient(a, b, c) > 0)return true;
  return false;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int n;
  while(cin >> n){
    if(!n)break;
    vector<pt> p;
    forn(i, 0, n){
      T x, y;
      cin >> x >> y;
      p.pb({x, y});
    }
    p.pb(p[0]);
    p.pb(p[1]);
    bool ori = validate(p[0], p[1], p[2]);

    forn(i, 0, n){
      debug(orient(p[i], p[i+1], p[i+2]));
    }

    bool ans = true;
    
    forn(i, 1, n){
      bool nxt = validate(p[i], p[i+1], p[i+2]);
      if(ori == nxt){
        ans = false;
        break;
      }
    }
    cout << ans << endl;
  }

}
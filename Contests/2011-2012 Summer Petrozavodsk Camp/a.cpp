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

typedef ll T;
struct pt {
	T x, y;
	pt operator + (pt p) { return {x+p.x, y+p.y}; }
	pt operator - (pt p) { return {x-p.x, y-p.y}; }
	pt operator * (pt p) { return {x*p.x-y*p.y, x*p.y+y*p.x}; }
	pt operator * (T d) { return {x*d, y*d}; }
	bool operator == (pt p) { return x == p.x && y == p.y; }
	bool operator != (pt p) { return x != p.x || y != p.y; }
	bool operator < (const pt &o) const { return y < o.y || (y == o.y && x < o.x); }
  bool operator > (const pt &o) const { return y > o.y || (y == o.y && x > o.x); }
	
};

T cross(pt a, pt b){ return a.x*b.y - a.y*b.x; }

T orient(pt a, pt b, pt c){ return cross(b-a, c-a); }

vector<pt> p, ch1;
void convex_hull() {
    sort(p.begin(), p.end());
    vector<pt> ch;
    ch.reserve(p.size()+1);
    for(int it = 0; it < 2; it++) {
      int start = ch.size();
      for(auto &a : p) {
        while(ch.size() >= start+2 && orient(ch[ch.size()-2], ch.back(), a) <= 0)
          ch.pop_back();
        ch.push_back(a);
      }
      ch.pop_back();
      reverse(p.begin(), p.end());
    }
    if(ch.size() == 2 && ch[0] == ch[1]) ch.pop_back();
    ch1.swap(ch);
  }

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  
  // freopen("average.in", "r", stdin);
  // freopen("average.out", "w", stdout);

  int n, x, y;
  cin >> n;
  forn(i, 0, n){
	  cin >> x >> y;
	  p.pb({x, y});
  }

  convex_hull();
  vector<pt> p2;
  forn(i, 0, n){
	  
  }



  
}
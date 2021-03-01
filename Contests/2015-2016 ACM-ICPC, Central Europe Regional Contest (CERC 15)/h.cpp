#include <bits/stdc++.h>
using namespace std;
void debug() { cout << endl; }
template <typename T, typename... Args>
void debug(T a, Args... args) { cout << a << " "; debug(args...);}
#define forn(i, a, b) for (int i = a; i < b; ++i)
#define SZ(x) int(x.size())
#define pb push_back
#define F first
#define S second
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;

typedef float lf;
typedef lf T;
struct pt {
  T x, y;
  pt operator + (pt p) { return {x+p.x, y+p.y}; }
  pt operator - (pt p) { return {x-p.x, y-p.y}; }
  pt operator * (pt p) { return {x*p.x-y*p.y, x*p.y+y*p.x}; }
  pt operator * (T d) { return {x*d, y*d}; }
  pt operator / (lf d) { return {x/d, y/d}; }
  bool operator == (pt b) { return x == b.x && y == b.y; }
  bool operator != (pt b) { return !(*this == b); }
  bool operator < (const pt &o) const { return y < o.y || (y == o.y && x < o.x); }
  bool operator > (const pt &o) const { return y > o.y || (y == o.y && x > o.x); }
};

T dot(pt a, pt b) { return a.x*b.x + a.y*b.y; }
T cross(pt a, pt b) { return a.x*b.y - a.y*b.x; }
T orient(pt a, pt b, pt c) { return cross(b-a,c-a); }

struct line {
  pt v; T c;
  line(pt v, T c) : v(v), c(c) {}
  line(T a, T b, T c) : v({b,-a}), c(c) {}
  line(pt p, pt q) : v(q-p), c(cross(v,p)) {}
  T side(pt p) { return cross(v,p)-c; }
};

bool inter_ll(line l1, line l2, pt &out) {
  T d = cross(l1.v, l2.v);
  if (d == 0) return false;
  out = (l2.v*l1.c - l1.v*l2.c) / d;
  return true;
}

enum {IN, OUT, ON};
struct polygon {
  vector<pt> p;
  polygon(int n) : p(n) {}
  int top = -1, bottom = -1;
  
  lf area(bool s = false) {
    lf ans = 0;
    for (int i = 0, n = p.size(); i < n; i++)
      ans += cross(p[i], p[(i+1)%n]);
    ans /= 2.0;
    return s ? ans : fabs(ans);
  }
  
  polygon cut(pt a, pt b) {
    line l(a, b);
    polygon new_polygon(0);
    for(int i = 0, n = p.size(); i < n; ++i) {
      pt c = p[i], d = p[(i+1)%n];
      lf abc = cross(b-a, c-a), abd = cross(b-a, d-a);
      if(abc >= 0) new_polygon.p.push_back(c);
      if(abc*abd < 0) {
        pt out; inter_ll(l, line(c, d), out);
        new_polygon.p.push_back(out);
      }
    }
    return new_polygon;
  }
  pt& operator[] (int i){ return p[i]; }

  void print(){
    for(auto x: p){
      debug(x.x, x.y);
    }debug();
  }
};

lf inf = 10.0f;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  polygon pol(4);

  forn(i, 0, 4){
      cin >> pol[i].x >> pol[i].y;
  }

  lf coor = 0.5;

  pair<pt, pt> planes[4];
  int val[5];
  planes[0] = {{inf, -coor}, {-inf, -coor}};
  val[0] = 1;
  planes[1] = {{coor, inf}, {coor, -inf}};
  val[1] = 3;
  planes[2] = {{-inf, coor}, {inf, coor}};
  val[2] = 6;
  planes[3] = {{-coor, -inf}, {-coor, inf}};
  val[3] = 4;

  lf tot = 124.0f;
  lf ans = 500.0f/tot;
  lf h = 5.0f;

  forn(i, 0, 4){
      polygon p = pol.cut(planes[i].F, planes[i].S);
      lf aux = (p.area()*h)/tot * (double)val[i];
      ans += aux;
  }
  
  cout << fixed << setprecision(10) << ans << endl;

}

#include <bits/stdc++.h>
using namespace std;
void debug() {cout<<endl;}
template<typename T,typename... Args>
void debug(T a,Args... args) {cout<<a<<" ";debug(args...);}
#define forn(i,a,b) for(int i=a;i<b;++i)
#define pb push_back
#define F first
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;

typedef double lf;
typedef int T;
const lf eps = 1e-6;
struct pt {
  T x, y;
  pt operator + (pt p) { return {x+p.x, y+p.y}; }
  pt operator - (pt p) { return {x-p.x, y-p.y}; }
  pt operator * (pt p) { return {x*p.x-y*p.y, x*p.y+y*p.x}; }
  pt operator * (T d) { return {x*d, y*d}; }
  pair<lf, lf> operator / (lf d) { return {(lf)x/d, (lf)y/d}; }
  bool operator == (pt b) { return x == b.x && y == b.y; }
  bool operator != (pt b) { return !(*this == b); }
  bool operator < (const pt &o) const { return y < o.y || (y == o.y && x < o.x); }
  bool operator > (const pt &o) const { return y > o.y || (y == o.y && x > o.x); }
};
int cmp (lf a, lf b) { return (a + eps < b ? -1 :(b + eps < a ? 1 : 0)); }
T norm(pt a) { return a.x*a.x + a.y*a.y; }
lf abs(pt a) { return sqrt(norm(a)); }
T dot(pt a, pt b) { return a.x*b.x + a.y*b.y; }
T cross(pt a, pt b) { return a.x*b.y - a.y*b.x; }

struct line {
  pt v; lf c;
  line(pt v, lf c) : v(v), c(c) {}
  line(T a, T b, T c) : v({b,-a}), c(c) {}
  line(pt p, pt q) : v(q-p), c(cross(v,p)) {}
  T side(pt p) { return cross(v,p)-c; }
  lf dist(pt p) { return abs(side(p)) / abs(v); }
  lf sq_dist(pt p) { return side(p)*side(p) / (lf)norm(v); }
  bool cmp_proj(pt p, pt q) { return dot(v,p) < dot(v,q); }
  line translate(pt t) { return {v, c + cross(v,t)}; }
  line shift_left(double d) { return {v, c+d*abs(v)}; }
};

lf line_to_seg(pt a, pt b, pt c, pt d){
  line l(a, b);
  if(l.side(c)*l.side(d) <= 0)return 0;
  return min(l.dist(c), l.dist(d));
}

lf seg_to_pt(pt a, pt b, pt p) {
  if(a != b) {
    line l(a,b);
    if (l.cmp_proj(a,p) && l.cmp_proj(p,b)) /// if closest to  projection
      return l.dist(p); /// output distance to line
  }
  return min(abs(p-a), abs(p-b)); /// otherwise distance to A or B
}

T orient(pt a, pt b, pt c) { return cross(b-a,c-a); }

bool proper_inter(pt a, pt b, pt c, pt d, pair<lf, lf> &out) {
  T oa = orient(c,d,a),
  ob = orient(c,d,b),
  oc = orient(a,b,c),
  od = orient(a,b,d);
  if (oa*ob < 0 && oc*od < 0) {
    out = (a*ob - b*oa) / (ob-oa);
    return true;
  }
  return false;
}

lf seg_to_seg(pt a, pt b, pt c, pt d) {
  pair<lf, lf> dummy;
  if (proper_inter(a,b,c,d,dummy)) return 0;
  return min({seg_to_pt(a,b,c), seg_to_pt(a,b,d),
              seg_to_pt(c,d,a), seg_to_pt(c,d,b)});
}

lf ray_to_pt(pt a, pt b, pt p){
  line l(a, b);
  if(dot(a, p) >= 0)return l.dist(p);
  return abs(p-a);
}

lf ray_to_seg(pt a, pt b, pt c, pt d){
  if(cross(a-b, c)*cross(a-b, d) < 1)return 0;
  return line_to_seg(a, b, c, d);
}

bool inter_ll(line l1, line l2) {
  T d = cross(l1.v, l2.v);
  if (d == 0) return false;
  return true;
}

lf ray_to_ray(pt a, pt b, pt c, pt d){
  return 0;
}

lf line_to_ray(pt a, pt b, pt c, pt d){
  return 0;
}

lf line_to_line(pt a, pt b, pt c, pt d){
  if(inter_ll({a, b}, {c, d}))return 0;
  line l(a, b);
  return l.dist(c);
}

const int inf = 1e4;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  pt A, B, C, D;
  cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y;

//The distance from the point A to the point C.
  pt aux = C-A;
  cout << abs(aux) << endl;
// The distance from the point A to the segment CD.
  cout << seg_to_pt(C, D, A) << endl;
// The distance from the point A to the half-infinite ray CD.
  cout << ray_to_pt(C, D, A) << endl;
// The distance from the point A to the line CD.
  line CD(C, D);
  cout << CD.dist(A) << endl;
// The distance from the segment AB to the point C.
  cout << seg_to_pt(A, B, C) << endl;
// The distance from the segment AB to the segment CD.
  cout << seg_to_seg(A, B, C, D) << endl;
// The distance from the segment AB to the half-infinite ray CD.
  cout << ray_to_seg(C, D, A, B) << endl;
// The distance from the segment AB to the line CD.
  cout << line_to_seg(C, D, A, B) << endl;
// The distance from the half-infinite ray AB to the point C.
  cout << ray_to_pt(A, B, C) << endl;
// The distance from the half-infinite ray AB to the segment CD.
  cout << ray_to_seg(A, B, C, D) << endl;
// The distance from the half-infinite ray AB to the half-infinite ray CD.
  cout << ray_to_ray(A, B, C, D) << endl;
// The distance from the half-infinite ray AB to the line CD.
  cout << line_to_ray(C, D, A, B) << endl;
// The distance from the line AB to the point C.
  line AB(A, B);
  cout << AB.dist(C) << endl;
// The distance from the line AB to the segment CD.
  cout << line_to_seg(A, B, C, D) << endl;
// The distance from the line AB to the half-infinite ray CD.
  cout << line_to_ray(A, B, C, D) << endl;
// The distance from the line AB to the line CD.
  cout << line_to_line(A, B, C, D) << endl;
  

}
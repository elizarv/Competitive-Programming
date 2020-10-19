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

typedef double T;
struct pt {
  T x, y;
  pt operator + (pt p){
    return {x+p.x, y+p.y};
  }
  pt operator - (pt p){
    return {x-p.x, y-p.y};
  }
  pt operator * (pt p){
    return {x*p.x-y*p.y, x*p.y+y*p.x};
  }
  pt operator * (T p){
    return {x*p, y*p};
  }
  pt operator / (double p){
    return {x/p, y/p};
  }
  bool operator < (const pt &o) const {
    return y < o.y || (y == o.y && x < o.x);
  }
};

T dot(pt a, pt b){
  return a.x*b.x + a.y*b.y;
}

T cross(pt a, pt b){
  return a.x*b.y - a.y*b.x;
}

T orient(pt a, pt b, pt c){
  return cross(b-a, c-a);
}

bool in_disk(pt a, pt b, pt p){
  return dot(a-p, b-p) <= 0;
}

bool on_segment(pt a, pt b, pt p){
  return orient(a, b, p) == 0 && in_disk(a, b, p);
}

bool proper_inter(pt a, pt b, pt c, pt d, pt &out){
  T oa = orient(c, d, a),
  ob = orient(c, d, b),
  oc = orient(a, b, c),
  od = orient(a, b, d);
  if(oa*ob < 0 && oc*od < 0){
    out = (a*ob - b*oa) / (ob-oa);
    return true;
  }
  return false;
}

set<pt> inter_ss(pt a, pt b, pt c, pt d) {
  pt out;
  if (proper_inter(a,b,c,d,out)) return {out};
  set<pt> st;
  if (on_segment(c,d,a))  st.insert(a);
  if (on_segment(c,d,b))  st.insert(b);
  if (on_segment(a,b,c))  st.insert(c);
  if (on_segment(a,b,d))  st.insert(d);
  return st;
}


const int inf = 1e9;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  // g++ -pthread -Wall -Wshadow -std=c++17 -o main e.cpp && ./main < e.txt

  int x, y, x2, y2;
  cin >> x >> y >> x2 >> y2;
  pt a = {x, y};
  pt b = {x2, y2};
  cin >> x >> y >> x2 >> y2;
  pt c = {x, y};
  pt d = {x2, y2};

  pt A, B, C = {-1, -1};

  set<pt> P = inter_ss(a, b, c, d);
  if(!P.size()){
    cout << "0.0\n";
    return 0;
  }
  A = *P.begin();

  if(b.y < d.y){
    pt I = {-inf, b.y};
    B = b;
    P = inter_ss(c, d, b, I);
    if(P.size()) C = *P.begin();
    else{
      I = {inf, b.y};
      P = inter_ss(c, d, b, I);
      if(P.size())C = *P.begin();
    }
  }else{
    pt I = {inf, d.y};
    B = d;
    P = inter_ss(a, b, d, I);
    if(P.size()) C = *P.begin();
    else{
      I = {-inf, d.y};
      P = inter_ss(a, b, d, I);
      if(P.size())C = *P.begin();
    }
  }

  if(C.x == -1 && C.y == -1){
    cout << "0.0\n";
    return 0;
  }

  double area = abs(cross(B-A, C-A)/2.0);
  cout << fixed << setprecision(10) << area << endl;
  
}
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
  int type = -1;
  pt operator + (pt p) { return {x+p.x, y+p.y, type}; }
  pt operator - (pt p) { return {x-p.x, y-p.y, type}; }
  pt operator * (pt p) { return {x*p.x-y*p.y, x*p.y+y*p.x, type}; }
  pt operator * (T d) { return {x*d, y*d, type}; }
  pt operator / (T d) { return {x/d, y/d, type}; } /// only for floating point
  bool operator == (pt b) { return x == b.x && y == b.y; }
  bool operator != (pt b) { return !(*this == b); }
  bool operator < (const pt &o) const { return y < o.y || (y == o.y && x < o.x); }
  bool operator > (const pt &o) const { return y > o.y || (y == o.y && x > o.x); }

	pt rot(double a){
		return { x*cos(a) - y*sin(a), x*sin(a) + y*cos(a), type};
	}

};

T dot(pt a, pt b) { return a.x*b.x + a.y*b.y; }
T cross(pt a, pt b) { return a.x*b.y - a.y*b.x; }
T orient(pt a, pt b, pt c) { return cross(b-a,c-a); }

vector<pt> p;

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
	p.swap(ch);
}

const int MX = 1000;
const double PI = acos(-1);
const double ang = 2*PI/MX, ang90 = PI/3;

void getCircle(T x, int id){
	pt center = {x+0.5, 0.5, id};
	pt aux = {0.5, 0.0, id};
	forn(i, 1, MX+1){
		p.pb(center+aux.rot(ang*i));
	}
}

double dist(pt a, pt b){
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}


int main() {
  ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	
  string s;
  cin >> s;

	T x = 0.0f;

	pt mid = {1, 0};
	mid = mid.rot(ang90);

	forn(i, 0, n){
		char c = s[i];
		if(c == 'T'){
			p.pb({x, 0});
			p.pb({x+1, 0});
			p.pb({x + mid.x, mid.y});
		}else if(c == 'S'){
			p.pb({x, 0});
			p.pb({x, 1});
			p.pb({x+1, 0});
			p.pb({x+1, 1});
		}else{
			getCircle(x, i);
		}
		x++;
	}

	convex_hull();

	double per = 0;

	n = p.size();

	for(int i = 0; i < n; i++){
		pt p1 = p[i];
		pt p2 = p[(i+1)%n];
		if(p1.type != p2.type || p1.type == -1)per += dist(p1, p2);
		else per += ang/2;
	}

	cout << fixed << setprecision(10) << per << endl;
  
}
//https://codeforces.com/gym/100342/
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
typedef unsigned long long ull;
typedef pair<int, int> pii;

typedef ll T;
struct pt {
	T x, y;
	pt operator - (pt p){ return {x-p.x, y-p.y}; }
};

T cross(pt a, pt b){
	return a.x*b.y - a.y*b.x;
}

T dot(pt a, pt b){
	return a.x*b.x + a.y*b.y;
}

bool onsegment(pt a, pt b, pt p){
	T x1 = min(a.x, b.x);
	T x2 = max(a.x, b.x);
	T y1 = min(a.y, b.y);
	T y2 = max(a.y, b.y);
	return x1 <= p.x && x2 >= p.x && y1 <= p.y && y2 >= p.y;
}
 

int main() {
 ios::sync_with_stdio(0); cin.tie(0);
//  freopen("cottages.in", "r", stdin);
//  freopen("cottages.out", "w", stdout);

	int n, x, y;
	cin >> n;
	vector<pt> p;
	forn(i, 0, n){
		cin >> x >> y;
		p.pb({x, y});
	}
	ll ans = 0;

	forn(i, 0, n){
		forn(j, i+1, n){
			pt a = p[j]-p[i];
			int in = 0;
			forn(k, 0, n){
				pt b = p[k]-p[i];
				if(i == k || j == k)continue;
				if((cross(a, b) == 0) && dot(b, b) > 0 && (dot(b, b) < dot(a, a))){
					in++;
					break;
				}
			}
			if(!in)ans++;
		}
	}

	cout << ans*2 << endl;



 }

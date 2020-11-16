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
  pt operator / (T d) { return {x/d, y/d}; }
  bool operator == (pt b) { return x == b.x && y == b.y; }
  bool operator != (pt b) { return !(*this == b); }
  bool operator < (const pt &o) const { return y < o.y || (y == o.y && x < o.x); }
  bool operator > (const pt &o) const { return y > o.y || (y == o.y && x > o.x); }
};

pt rot90ccw(pt p) { return {-p.y, p.x}; }

T getDist(pt pt){
    return pt.x*pt.x + pt.y*pt.y;
}

vector<pt> p;

ll gcd(ll a, ll b){
    if(b == 0)return a;
    return gcd(b, a%b);
}

typedef __int128 big;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  freopen("points.in", "r" , stdin);

    int t;
    cin >> t;
    while(t--){
        int n;
        ll l, r;
        cin >> n >> l >> r;

        big L = big(l)*big(l)*big(4);
        big R = big(r)*big(r)*big(4);

        p.clear();

        int x, y;
        forn(i, 0, n){
            cin >> x >> y;
            p.pb({x, y});
        }

        ll ans = 0;

        forn(i, 0, n){
            map<pt, vector<big>> mapa; // dir, dist
            forn(j, 0, n){
                if(i == j)continue;
                pt dir = p[j] - p[i];
                big dist = getDist(dir);
                T g = gcd(abs(dir.x), abs(dir.y));
                dir = dir/g;
                mapa[dir].pb(dist);
            }
            for(auto &aux: mapa){
                sort(aux.S.begin(), aux.S.end());
            }
            forn(j, 0, n){
              if(i == j)continue;
                pt dir = p[j] - p[i];
                big dist = getDist(dir);
                pt dir90 = rot90ccw(dir);
                T g = gcd(abs(dir90.x), abs(dir90.y));
                dir90 = dir90/g;
                if(!mapa.count(dir90))continue;
                auto &aux = mapa[dir90];
                big val1 = (L + dist - 1)/dist;
                int l = lower_bound(aux.begin(), aux.end(), val1) - aux.begin();
                big val2 = R/dist;
                int r = upper_bound(aux.begin(), aux.end(), val2) - aux.begin();
                ans += r-l;
            }
        }

        cout << ans << endl;


    }




}
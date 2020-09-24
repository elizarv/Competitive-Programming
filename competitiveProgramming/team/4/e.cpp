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

struct min_queue{
	deque<int> og, mn;
	
	void add(int x){
		og.push_back(x);
		while(mn.size() && mn.back() > x)mn.pop_back();
		mn.push_back(x);
	}
	
	void erase(){
		if(og.front() == mn.front())mn.pop_front();
		og.pop_front();
	}
	
	int get_min(){
		return mn.front();
	}
};

 

int main() {
 ios::sync_with_stdio(0); cin.tie(0);
//  freopen("minima.in", "r", stdin);
//  freopen("minima.out", "w", stdout);

 int n, m, k, a, b, c, x, prev, prev2;
 cin >> n >> m >> k >> a >> b >> c;

ll ans = 0;
min_queue q;

 forn(i, 0, n){
     if(i < k)cin >> x;
     else {
         x = a*prev2+b*prev+c;
     }
     q.add(x);
     if(i >= m-1){
         ans += q.get_min();
        q.erase();
     }
     prev2 = prev;
     prev = x;
 }

 cout << ans << endl;
 
 }

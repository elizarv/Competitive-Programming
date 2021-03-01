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

const int inf = 1e9+5;

int LIS(vector<int>& v){
	int n = v.size();
	int i;
	vector<int> I;
	int lis = 0;
	forn(i, 0, n){
		int x = upper_bound(I.begin(), I.end(), v[i])-I.begin();
		if(x == I.size())I.pb(0);
		I[x] = v[i];
		lis = max(lis, x+1);
	}
	return lis;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	vector<int> v(n);
	map<int, int> last;
	forn(i, 0, n){
		cin >> v[i];
		last[v[i]] = i;
	}
	vector<int> mx;
	forn(i, 0, n){
		int x = lower_bound(mx.begin(), mx.end(), i)-mx.begin();
		if(x == mx.size()){
			mx.pb(last[v[i]]);
		}
		mx[x] = max(mx[x], last[v[i]]);
	}

	vector<int> newv;
	int p = 0;
	int tot = 0;
	for(auto &x: mx){
		set<int> st;
		forn(i, p, x+1){
			st.insert(v[i]);
		}
		tot += st.size()-1;
		auto it = st.rbegin();
		while(it != st.rend()){
			newv.pb(*it);
			it++;
		}
		p = x+1;
	}

	ll ans = mx.size() + tot - LIS(newv);

	cout << ans << endl;

	
}
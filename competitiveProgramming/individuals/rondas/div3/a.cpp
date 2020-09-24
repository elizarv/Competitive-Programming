#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
void debug() {cout<<endl;}
template<typename T,typename... Args>
void debug(T x,Args... args) {cout<<x<<" ";debug(args...);}
#define forn(i,a,b) for(int i=a;i<b;++i)
#define pb push_back
#define F first
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;

const int N = 3e5+5;
int bit[N+1];

void add(int k, int val){
	for(; k <= N; k += k&-k)bit[k] += val;
}

int rsq(int k){
	int sum = 0;
	for(; k >= 1; k -= k&-k)sum += bit[k];
	return sum;
}

int lower_find(int val) {
    int idx = 0;
    for(int i = 31-__builtin_clz(N); i >= 0; --i) {
        int nidx = idx | (1 << i);
        if(nidx <= N && bit[nidx] <= val) {
            val -= bit[nidx];
            idx = nidx;
        }
    }
    return idx;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

	int n, q;
	cin >> n >> q;
	vector<int> v(n);
	forn(i, 1, n+1){
		cin >> v[i];
		if(rsq(i) >= (i-v[i]))add(i, 1);
	}
	vector<pair<pii, int>> query;
	vector<int> ans(q);
	forn(i, 0, q){
		int l, r;
		cin >> l >> r;
		query.pb({{n-r, l+1}, i});
	}
	sort(query.begin(), query.end());

	int inv = 0;
	for(auto qu: query){
		int i = qu.S;
		int l = qu.F.S;
		int r = qu.F.F;
		int x = rsq(l);
		int id = lower_find(x+inv);
		if(id > r)ans[i] = 0;
		else{
			ans[i] = x-inv;
		}
		if((l-v[l]) >= 0 && (l-v[l]) <= inv)inv++;
	}

	forn(i, 0, q)cout << ans[i] << endl;



}



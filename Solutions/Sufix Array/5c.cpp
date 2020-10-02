//https://codeforces.com/edu/course/2/lesson/2/5/practice/contest/269656/problem/B
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

const int L = 300;

void counting_sort(vector<int>& p, vector<int>& c){
	int n = p.size();
	vector<int> cnt(max(n, L));
	for(auto x: c){
		cnt[x]++;
	}
	vector<int> new_arr(n);
	vector<int> pos(n);
	pos[0] = 0;
	forn(i, 1, n){
		pos[i] = pos[i-1]+cnt[i-1];
	}
	for(auto x: p){
		int i = c[x];
		new_arr[pos[i]] = x;
		pos[i]++;
	}
	p = new_arr;
}

struct sufixA {
	string s;
	vector<pii> a;
	vector<int> c, sa, lcp;
	vector<vector<int>> rmq;
	int n;

	sufixA(){}

	sufixA(string &_s){
		s = _s + (char)(20);
		n = s.size();
		a.resize(n);
		c.resize(n);
		sa.resize(n);
		buildSA();
		buildLcp();
	}

	void buildSA(){
		forn(i, 0, n)a[i] = {s[i], i};
  	    sort(a.begin(), a.end());
		forn(i, 0, n)sa[i] = a[i].S;
		c[sa[0]] = 0;
		forn(i, 1, n){
			c[sa[i]] = c[sa[i-1]];
			if(a[i].F != a[i-1].F)c[sa[i]]++;
		}
		for(int k = 1; k < n; k <<= 1){
			forn(i, 0, n){
				sa[i] = (sa[i] - k + n) % n;
			}
			counting_sort(sa, c);
			vector<int> c_new(n);
			c_new[sa[0]] = 0;
			forn(i, 1, n){
				pii prev = {c[sa[i-1]], c[(sa[i-1] + k) % n]};
				pii now = {c[sa[i]], c[(sa[i] + k) % n]};
				c_new[sa[i]] = c_new[sa[i-1]];
				if(now != prev)c_new[sa[i]]++;
			}
			c = c_new;
		}
	}

	void buildLcp(){
		int k = 0;
		lcp.resize(n);
		forn(i, 0, n-1){
			int pi = c[i];
            if(pi == 0)continue;
			int j = sa[pi - 1];
			while(s[i + k] == s[j + k])k++;
			lcp[pi] = k;
			k = max(k -1, 0);
		}
		buildTable();
	}

	void buildTable(){
		int LOG2 = 20;
		rmq.resize(LOG2, vector<int>(n+1));
		forn(i, 0, n)rmq[0][i] = lcp[i]; // i, i-1
		forn(j, 1, LOG2){
			for(int i = 0; i+(1<<j-1) < n; i++){
				rmq[j][i] = min(rmq[j-1][i], rmq[j-1][i+(1<<j-1)]);
			}
		}
	}

	int LCP(int i, int j){
		assert(i != j);
		i = c[i], j = c[j];
		if(j < i)swap(i, j);
		i++;
		int k = 31-__builtin_clz(j-i+1);
		return min(rmq[k][i], rmq[k][j-(1<<k)+1]);
	}

};
	/*
	abacaba$
	0 $
	0 a$
	1 aba$
	3 abacaba$
	1 acaba$
	0 ba$
	2 bacaba$
	*/

sufixA sa;

struct subs {
	int l, r, tam;

	bool operator < (const subs& b) const {
		// debug(l, r, b.l, b.r);
		if(l == b.l)return r < b.r;
		if(tam != b.tam){
			int lcp = min({tam, b.tam, sa.LCP(l, b.l)});
			// debug("tam != ", lcp, sa.LCP(l, b.l));
			if(lcp == tam)return true;
			else if(lcp == b.tam)return false;
		}else{
			int lcp = min(tam, sa.LCP(l, b.l));
			// debug("tam == ", lcp);
			if(lcp == tam)return l < b.l;
		}
		// debug("nada ", sa.c[l], sa.c[b.l]);
		return sa.c[l] < sa.c[b.l];
	}
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  string s;
  cin >> s;

	sa = sufixA(s);

	int q; cin >> q;

	vector<subs> query;
	int l, r;

	forn(i, 0, q){
		cin >> l >> r;
		query.pb({l-1, r-1, r-l+1});
	}

	sort(query.begin(), query.end());

	for(auto sub: query){
		cout << sub.l+1 << " " << sub.r+1 << endl;
	}

}
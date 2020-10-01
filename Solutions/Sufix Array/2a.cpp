//https://codeforces.com/edu/course/2/lesson/2/2/practice/contest/269103/problem/A
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

void counting_sort(vector<int>& p, vector<int>& c){
	int n = p.size();
	vector<int> cnt(n);
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


int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  string s;
  cin >> s;
	s += "$";
  int n = s.size();
  vector<pii> a(n);
  forn(i, 0, n)a[i] = {s[i], i};
  sort(a.begin(), a.end());

  vector<int> c(n), sa(n);
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

	forn(i, 0, n){
		cout << sa[i] << " \n"[i+1 == n];
	}





}

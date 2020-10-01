//https://codeforces.com/edu/course/2/lesson/2/1/practice/contest/269100/problem/A
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
      vector<pair<pii, int> > aux(n);
      forn(i, 0, n){
          aux[i] = {{c[i], c[(i+k)%n]}, i};
      }
      sort(aux.begin(), aux.end());
			forn(i, 0, n)sa[i] = aux[i].S;
			c[sa[0]] = 0;
      forn(i, 1, n){
					c[sa[i]] = c[sa[i-1]];
					if(aux[i].F != aux[i-1].F)c[sa[i]]++;
			}
  }

	forn(i, 0, n){
		cout << sa[i] << " \n"[i+1 == n];
	}





}

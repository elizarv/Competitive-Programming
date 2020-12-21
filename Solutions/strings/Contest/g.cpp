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

vector<int> prefix_function(string &s) {
    int n = s.size();
    vector<int> pf(n);
    pf[0] = 0;
    for (int i = 1, j = 0; i < n; i++) {
        while (j && s[i] != s[j]) j = pf[j-1];
        if (s[i] == s[j]) j++;
        pf[i] = j;
    }
    return pf;
}

const int MX =1e5+5;
bitset<MX> ans;

int kmp(string &s, string &p, int x) {
    int n = s.size(), m = p.size(), cnt = 0;
    vector<int> pf = prefix_function(p);
	bitset<MX> aux = 0, cur = 0;
    for(int i = 0, j = 0; i < n; i++) {
        while(j && s[i] != p[j]) j = pf[j-1];
        if(s[i] == p[j]) j++;
        if(j == m) {
			cur[i+1] = 1;
            cnt++;
            j = pf[j-1];
        }
    }
	forn(i, 1, n+1){
		if(!cur[i])continue;
		int nxt = i-m-x;
		if(nxt < 0)continue;
		if(ans[nxt])aux[i] = 1;
	}
	ans = aux;
    return cnt;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  string s, t;
  while(cin >> s){
	  cin >> t;
	  if(t.size() > s.size()){
		  cout << "0" << endl;
		  continue;
	  }
	  int n = t.size();
	  string p;
	  int ini = 0, wc = 0;
	  bool fst = true;
	  int cnt = 0;
	  forn(i, 0, s.size()+1)ans[i] = 1;
	  forn(i, 0, n){
		  if(t[i] == '?'){
			  wc++;
			  if(p.size()){
				  kmp(s, p, cnt);
				  cnt = 0;
			  }
			  fst = false;
			  cnt++;
			  p.clear();
		  }else{
			  p.push_back(t[i]);
		  }
	  }
	  if(p.size()){
		  kmp(s, p, cnt);
		  cnt = 0;
	  }
	  if(wc == n){
		  cout << s.size()-n+1 << endl;
		  continue;
	  }
	  int r = 0;
	  forn(i, 0, (int)s.size()-cnt+1){
	  	r += ans[i];
	  }
	  cout << r << endl;
  }


} 
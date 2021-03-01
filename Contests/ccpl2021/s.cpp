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

int kmp(string &s, string &p) {
    int n = s.size(), m = p.size();
		int ans = 0;
    vector<int> pf = prefix_function(p);
    for(int i = 0, j = 0; i < n; i++) {
        while(j && s[i] != p[j]) j = pf[j-1];
        if(s[i] == p[j]) j++;
				ans = max(ans, j);
        if(j == m) {
            j = pf[j-1];
        }
    }
    return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int t;
  cin >> t;
  string s, r;
  while(t--){
			cin >> s;
			r = s;
			reverse(r.begin(), r.end());
			int ans = kmp(r, s);
			s = s.substr(0, ans);
			reverse(s.begin(), s.end());
			cout << s << endl;
  }



}
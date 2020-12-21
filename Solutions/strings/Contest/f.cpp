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

vector<int> prefix_function(string &s, vector<int>& cnt) {
    int n = s.size();
    vector<int> pf(n);
    pf[0] = 0;
    for (int i = 1, j = 0; i < n; i++) {
        while (j && s[i] != s[j]) j = pf[j-1];
        if (s[i] == s[j]) j++;
        pf[i] = j;
				cnt[j]++;
    }
    return pf;
}

const int N = 1e5+5;
bitset<N> bs;


int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  string s;
  cin >> s;

	int n = s.size();
  
	vector<int> cnt(n+1, 0);
	vector<int> pf = prefix_function(s, cnt);

	int cur = n;
	
	while(cur && pf[cur-1]){
		bs[pf[cur-1]] = 1;
		cur = pf[cur-1];
	}

	vector<pii> ans;
	ans.pb({n, 0});
	
	for(int i = n-1; i; i--){
		cnt[pf[i-1]] += cnt[i];
		if(bs[i])ans.pb({i, cnt[i]});
	}

	reverse(ans.begin(), ans.end());

	cout << ans.size() << endl;
	for(auto x: ans){
		cout << x.F << " " << x.S+1 << endl;
	}



} 
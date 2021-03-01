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

int main() {
  ios::sync_with_stdio(0); cin.tie(0);


	int a, b;
	char c;
	cin >> a >> b >> c;
	int ans = 0;
	forn(i, a, b+1){
		string s = to_string(i);
		int n = s.size();
		forn(j, 0, n){
			if(s[j] == c)ans++;
		}
	}

	cout << ans << endl;


}
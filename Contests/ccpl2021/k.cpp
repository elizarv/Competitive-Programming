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

string s, t;
int n, m, cnt;

bool valid(int a, int b){
  if(a + b > 3)return false;
  return true;
}

bool check(int i, int j){
  while(i < n && j < m){
    if(!valid(s[i]-'0', t[j]-'0'))return false;
    i++, j++;
    cnt++;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  while(cin >> s >> t){
    n = s.size(), m = t.size();
    int ans = n+m;
    bool f = false;
    forn(i, 0, m){
      cnt = 0;
      if(check(0, i)){
        ans = min(ans, m+n-cnt);
      }
    }
    forn(i, 0, n){
      cnt = 0;
      if(check(i, 0)){
        ans = min(ans, m+n-cnt);
      }
    }
    cout << ans << endl;

  }



}
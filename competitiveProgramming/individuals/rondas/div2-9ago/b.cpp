#include <bits/stdc++.h>
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


int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int t;
  cin >> t;
  while(t--){
    int n, m;
    cin >> n >> m;
    string s;
    int ans = 0;
    forn(i, 0, n){
        cin >> s;
        if(s[m-1] == 'R')ans++;
        if(i == n-1){
            forn(j, 0, m){
                if(s[j] == 'D')ans++;
            }
        }
    }
        cout << ans << endl;
  }
  
}


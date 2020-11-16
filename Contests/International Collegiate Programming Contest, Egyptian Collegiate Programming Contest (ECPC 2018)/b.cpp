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

const int inf = 1e9;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  freopen("task.in", "r" , stdin);
  
  int t;
  cin >> t;

  while(t--){
    int n, x;
    cin >> n;
    int ans = 0;
    set<int> st;
    forn(i, 0, n){
      cin >> x;
      if(st.count(x))ans++;
      else st.insert(x);
    }
    int mn = inf;
    int sz = st.size();
    int it = 1;
    int acum = 0;
    int prev = 0;
    for(auto x: st){
      acum += x-prev-1;
      prev = x;
      int aux = sz-it + acum;
      mn = min(mn, aux);
      it++;
    }

    cout << min(n + 1, ans + mn) << endl;

  }
  
}
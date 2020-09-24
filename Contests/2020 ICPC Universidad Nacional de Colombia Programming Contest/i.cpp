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

const int N = 1e5+5;
ll ans[N], L[N], R[N];

int dist(int i, int j){
  return abs(i-j);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int n, x;
  cin >> n;
  vector<pii> H(n);
  forn(i, 0, n){
    cin >> x;
    H[i] = {x, i};
  }

  stack<pii> st;
  for(int i = n-1; i >= 0; i--){
    int pos = R[i] = i;
    while(st.size() && st.top().F <= H[i].F){
      if(st.top().F == H[i].F)pos = st.top().S;
      st.pop();
    }
    if(st.size())R[i] = st.top().S;
    st.push({H[i].F, pos});
  }

  while(st.size())st.pop();

  forn(i, 0, n){
    int pos = L[i] = i;
    while(st.size() && st.top().F <= H[i].F){
      if(st.top().F == H[i].F)pos = st.top().S;
      st.pop();
    }
    if(st.size())L[i] = st.top().S;
    st.push({H[i].F, pos});
  }

  sort(H.rbegin(), H.rend());

  for(auto x: H){
    int i = x.S;
    ans[i] = max(ans[i], ans[R[i]]+dist(i, R[i]));
    ans[i] = max(ans[i], ans[L[i]]+dist(i, L[i]));
  }

  forn(i, 0, n)cout << ans[i] << " \n"[i+1 == n];
  
  
}
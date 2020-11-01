// Solutions to constest: https://codeforces.com/gym/101173
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

  int N, M;
  cin >> N >> M;

  string S[N];
  forn(i, 0, N) cin >> S[i];

  pii lu = {-1, -1}, rd = {-1, -1};
  forn(i, 0, N) {
    if (i > 0 && lu.F < 0) {
      forn(j, 1, M) {
        if (S[i-1][j] == '#' && S[i][j-1] == '#') {
          lu = {i, j};
          break;
        }
      }
    }
    if (i > 0 && i < N-1 && rd.F < 0) {
      forn(j, 0, M-1) {
        if (S[i+1][j] == '#' && S[i][j+1] == '#') {
          rd = {i, j};
          break;
        }
      }
    }
  }
  
  int n = rd.F-lu.F+1;
  int m = rd.S-lu.S+1;
  
  unordered_set<string> st;
  for (int i = 1; i < N; i += n+1) {
    for (int j = 1; j < M; j += m+1) {
      string mn = "z", aux;
      aux = "";
      for (int a = i; a < i+n; ++a) {
        for (int b = j; b < j+m; ++b) {
          aux.pb(S[a][b]);
        }
      }
      mn = min(mn, aux);
      aux = "";
      for (int b = j; b < j+m; ++b) {
        for (int a = i+n-1; a >= i; --a) {
          aux.pb(S[a][b]);
        }
      }
      mn = min(mn, aux);
      aux = "";
      for (int a = i+n-1; a >= i; --a) {
        for (int b = j+m-1; b >= j; --b) {
          aux.pb(S[a][b]);
        }
      }
      mn = min(mn, aux);
      aux = "";
      for (int b = j+m-1; b >= j; --b) {
        for (int a = i; a < i+n; ++a) {
          aux.pb(S[a][b]);
        }
      }
      mn = min(mn, aux);
      st.insert(mn);
    }
  }
  cout << st.size() << endl;
}
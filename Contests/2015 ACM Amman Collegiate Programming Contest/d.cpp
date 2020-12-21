#include <bits/stdc++.h>
using namespace std;
void debug() { cout << endl; }
template <typename T, typename... Args>
void debug(T a, Args... args) { cout << a << " "; debug(args...);}
#define forn(i, a, b) for (int i = a; i < b; ++i)
#define SZ(x) int(x.size())
#define pb push_back
#define F first
#define S second
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1005, inf = 1e9;
int n, k;
string s;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while(t--){
    cin >> n >> k >> s;

    vector<int> dp(n+1, 0);
    for(int i = n-1; i >= 0; i--){
      bool alt = true;
      dp[i] = inf;
      for(int j = i; j-i < k && j < n; j++){
        if(j > i && s[j] == s[j-1]) alt = false;
        if(i == j || !alt) dp[i] = min(dp[i], dp[j + 1] + 1);
      }
    }

    cout << dp[0]-1 << endl;

  }
  
}

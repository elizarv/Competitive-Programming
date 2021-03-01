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

string s;
const int N = 1e5+5, M = 9;
ll dp[N][M][2][2];
int n, target;
bool zero;

ll add(int x, int y, int MOD = M){
  if(x+y < MOD)return x+y;
  return x+y-MOD;
}

ll f(int i, int mod, bool sub, bool may){
  if(i == n)return sub && may == zero && mod == target;
  ll &ans = dp[i][mod][sub][may];
  if(ans != -1)return ans;
  ans = 0;
  int ch = s[i]-'0';
  int nxtmod = add(mod, ch);
  bool nxtmay = (may || (ch > 0));
  ans += f(i+1, nxtmod, true, nxtmay); // seguir
  if(!sub)ans += f(i+1, mod, sub, may); // comenzar despues
  ans += sub && may == zero && mod == target; // terminar ahi
  return ans;
}

void init(){
  forn(i, 0, n){
    forn(j, 0,  M){
      forn(k, 0, 2){
        forn(l, 0, 2)dp[i][j][k][l] = -1;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> s;
  forn(i, 0, M+1){
    init();
    target = i%9;
    zero = i;
    cout << f(0, 0, 0, 0) << " \n"[i == M];
  }


  
  
}

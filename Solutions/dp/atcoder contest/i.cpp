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

const int N = 3000;
double dp[N][N], P[N];
bool check[N][N];
int n;


double f(int i, int j){
    if(i == n)return j > n/2;
    double &ans  = dp[i][j];
    if(check[i][j])return ans;
    check[i][j] = true;
    ans += f(i+1, j)*(1-P[i]);
    ans += f(i+1, j+1)*P[i];
    return ans;
}


int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cout << fixed << setprecision(10);
  cin >> n;
  int a, b;
  char c;
  forn(i, 0, n){
    cin >> P[i];
  }
  double ans = f(0, 0);
  cout << ans << endl;
  


}




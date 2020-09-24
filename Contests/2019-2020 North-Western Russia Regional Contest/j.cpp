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

const int N = 505, M = 10;
int g[N][N], cnt[N][N], aux[N][N], n;

int add(int a, int b){
  return (a+b)%M;
}

int subs(int a, int b){
  return (a-b+M)%M;
}

void updt(int u, int v){
  forn(i, 0, n){
    aux[u][i] = subs(aux[u][i], cnt[v][i]);
    cnt[u][i] = add(cnt[u][i], cnt[v][i]);
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  
  cin >> n;

  forn(i, 0, n){
    char c;
    forn(j, 0, n){
      cin >> c;
      aux[i][j] = cnt[i][j] = c-'0';
      if(i == j)cnt[i][j] = 1;
    }
  }

  forn(i, 0, n){
    forn(j, 0, n){
      if(aux[i][j]){
        g[i][j] = 1;
        updt(i, j);
      }
    }
  }

  forn(i, 0, n){
    forn(j, 0, n){
      cout << g[i][j];
    }cout << endl;
  }




}
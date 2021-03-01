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

const int N = 22;
int mat[N][N];
bool minas[N][N];
int n, m;
int dy[] = {1,1,0,-1,-1,-1, 0, 1};
int dx[] = {0,1,1, 1, 0,-1,-1,-1};

bool check(int i, int j){
  if(i < 0 || j < 0 || i == n || j == m)return false;
  return true;
}

map<int, int> ans;

void valid(){
  int tot = 0;
  forn(i, 0, n){
    forn(j, 0, m){
      tot += minas[i][j];
      if(!mat[i][j])continue;
      int cnt = 0;
      forn(k, 0, 8){
        int nxti = i + dx[k];
        int nxtj = j + dy[k];
        if(!check(nxti, nxtj))continue;
        cnt += minas[nxti][nxtj];
      }
      if(cnt != mat[i][j])return;
    }
  }
  ans[tot]++;
}


void f(int i, int j){
  if(j == m){
    f(i+1, 0);
    return;
  }
  if(i == n){
    valid();
    return;
  }
  if(!mat[i][j]){
    minas[i][j] = true;
    f(i, j+1);
  }
  minas[i][j] = false;
  f(i, j+1);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  forn(i, 0, n){
    forn(j, 0, m){
      char ch;
      cin >> ch;
      if(ch != '.')mat[i][j] = ch-'0';
    }
  }


  f(0, 0);
  if(!ans.size()){
    cout << "0" << endl;
    return 0;
  }
  for(auto x: ans){
    cout << x.S << " " << x.F << endl;
    break;
  }
  
}

/*
g++ -pthread -Wall -Wshadow -std=c++17 -o main main.cpp && ./main < main.txt
freopen("input.in", "r" , stdin);
freopen("output.out", "w", stdout);
*/
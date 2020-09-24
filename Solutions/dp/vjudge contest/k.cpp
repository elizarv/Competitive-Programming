#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string.h>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <set>
#include <deque>
#include <utility>
#include <sstream>
#include <queue>
#include <stack>
#include <bitset>
#include <math.h>
#include <algorithm>
#include <limits.h>
using namespace std;
#define forn(i,a,b) for(int i=a,gon=b;i<gon;++i)
#define pb push_back
#define F first
#define S second
typedef double lf;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 30;
int dp[N][N][N], keys[N], inf = 1e9 + 5;


int val(char c){
  if(c >= 'a' && c <= 'z')return c-'a';
  if(c == '+')return 26;
  if(c == '*')return 27;
  if(c == '/')return 28;
  return 29;
}

char print(int c){
  if(c == 26) return '+';
  if(c == 27) return '*';
  if(c == 28) return '/';
  if(c == 29) return '?';
  return char(c+'a');
}

int cost(int a, int b){
  int ans = 0;
  int len = b-a+1;
  forn(i, 1, len+1){
    ans += keys[a]*i;
    a++;
  }
  return ans;
}

int f(int i, int j, int prev){
  if(j == 0)return cost(i, N-1);
  if(i == N-1)return inf;
  int &ans = dp[i][j][prev];
  if(ans != -1)return ans;
  ans = inf;
  ans = min(ans, f(i+1, j, prev));
  ans = min(ans, f(i+1, j-1, i+1)+cost(prev, i));
  return ans;
}
vector<int> cuts;
void build(int i, int j, int prev){
  if(j == 0) return;
  if(i == N-1)return;
  int &ans = dp[i][j][prev];
  if(ans == f(i+1, j-1, i+1)+cost(prev, i)){
    cuts.pb(i+1);
    build(i+1, j-1, i+1);
  }else if(ans == f(i+1, j, prev))build(i+1, j, prev);
}

void init(){
  forn(i, 0, N){
    keys[i] = 0;
  }
  cuts.clear();
  memset(dp, -1, sizeof dp);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int t;
  cin >> t;
  while(t--){
    int m;
    cin >> m;
    string s;
    init();
    forn(i, 0, m){
      cin >> s;
      for(int j = 0; j < s.size(); j++){
        char c = s[j];
        keys[val(c)]++;
      }
    }
    f(0, 11, 0);
    build(0, 11, 0);
    for(int j = 0; j < cuts.size(); j++){
        int c = cuts[j];
      cout << print(c);
    }cout << endl;
  }



}




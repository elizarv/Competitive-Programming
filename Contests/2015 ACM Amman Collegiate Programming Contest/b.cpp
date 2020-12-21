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

const int N = 1005, M = 3;
int win[M][N], lose[M][N];

void init(int n){
  forn(j, 0, M){
    forn(i, 0, n+2){
      win[j][i] = lose[j][i] = 0;
    }
  }
}


int getans(int i, int l, int r){
  return win[i][r] - win[i][l];
}

int getloser(int i, int l, int r){
  return lose[i][r] - lose[i][l];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  map<char, int> W;
  W['R'] = 1;
  W['P'] = 2;
  W['S'] = 0;

  map<char, int> L;
  L['R'] = 2;
  L['P'] = 0;
  L['S'] = 1;

  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    init(n);

    char ch;

    forn(i, 0, n){
      cin >> ch;
      int w = W[ch];
      int l = L[ch];
      win[w][i+1] = 1;
      lose[l][i+1] = 1;
    }
    
    forn(j, 0, M){
      forn(i, 1, n+1){
        win[j][i] += win[j][i-1];
        lose[j][i] += lose[j][i-1];
      }
    }

    int ans = 0;

    forn(x, 0, n+1){
      forn(y, 0, n+1){
        if(x+y > n)continue;
        int z = n-x-y;
        int Wpts = getans(0, 0, x);
        Wpts += getans(1, x, y+x);
        Wpts += getans(2, y+x, z+y+x);

        int Lpts = getloser(0, 0, x);
        Lpts += getloser(1, x, y+x);
        Lpts += getloser(2, y+x, z+y+x);

        if(Wpts > Lpts)ans++;
      }
    }

    cout << ans << endl;

  }
  
}

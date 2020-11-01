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

const int N = 6;
vector<int> check, good;
int n, k;
vector<int> K;

bool valid(vector<int>& grid){
    forn(i, 0, n){
        forn(j, 0, n){
            if((grid[i] >> j & 1) && (check[i] >> j & 1))return false;
            if((good[i] >> j & 1) && !(grid[i] >> j & 1))return false;
        }
    }
    return true;
}

bool canV(int i, int j, int sz, vector<int>& grid){
    if(i + sz > n)return false;
    sz += i;
    while(i < sz){
        if(grid[i] >> j & 1)return false;
        i++;
    }
    return true;
}

void fillV(int i, int j, int sz, vector<int>& grid){
    sz += i;
    while(i < sz){
        grid[i] ^= (1 << j);
        i++;
    }
}

bool canH(int i, int j, int sz, vector<int>& grid){
    if(j + sz > n)return false;
    sz += j;
    while(j < sz){
        if(grid[i] >> j & 1)return false;
        j++;
    }
    return true;
}

void fillH(int i, int j, int sz, vector<int>& grid){
    sz += j;
    while(j < sz){
        grid[i] ^= (1 << j);
        j++;
    }
}

ll f(int id, vector<int>& grid){
    if(id == k)return valid(grid);
    ll ans = 0;
    int sz = K[id];

    forn(i, 0, n){
        forn(j, 0, n){
            if(canV(i, j, sz, grid)){
                fillV(i, j, sz, grid);
                ans += f(id+1, grid);
                fillV(i, j, sz, grid);
            }
            if(sz > 1 && canH(i, j, sz, grid)){
                fillH(i, j, sz, grid);
                ans += f(id+1, grid);
                fillH(i, j, sz, grid);
            }
        }
    }
    return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n >> k;

  char c;
  vector<int> grid(n, 0);

  forn(i, 0, n){
      int mask1 = 0, mask2 = 0;
      forn(j, 0, n){
        cin >> c;
        if(c == 'X'){
            mask1^=(1 << j);
        }else if(c == 'O'){
            mask2^=(1 << j);
        }
      }
      check.pb(mask1);
      good.pb(mask2);
  }

  int x;
  forn(i, 0, k){
      cin >> x;
      K.pb(x);
  }

  cout << f(0, grid) << endl;




}
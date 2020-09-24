/*
https://codeforces.com/gym/101635
Solution to problem C
*/
#include <bits/stdc++.h>
using namespace std;
void debug() {cout<<endl;}
template<typename T,typename... arribargs>
void debug(T a,arribargs... args) {cout<<a<<" ";debug(args...);}
#define forn(i,a,b) for(int i=a,gon=b;i<gon;++i)
#define pb push_back
#define F first
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;

#define MOD 1000000000
const int N = 1<<8; //Maximo size de la matriz

struct matrix {
    int m[N][N], r, c;

    matrix(int _r = N, int _c = N, bool iden = false) {
        r = _r; c = _c;
        memset(m, 0, sizeof(m));
        if (iden) while (_c--) m[_c][_c] = 1;
    }

    matrix operator * (const matrix &B) {
        matrix C(r, B.c);
        for(int i = 0; i < r; i++)
            for(int k = 0; k < c; k++) if (m[i][k])
                for(int j = 0; j < B.c; j++)
                    C.m[i][j] = (1ll*C.m[i][j] + 1ll*m[i][k]*B.m[k][j]) % MOD;
        return C;
    }
};

matrix pow(matrix A, ll e) {
    matrix ANS(A.r, A.c, true);
    while (e) {
        if (e&1) ANS = ANS * A;
        A = A * A;
        e >>= 1;
    }
    return ANS;
}


int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int n;
  ll m;

  cin >> n >> m;

  int mask = 1<<n;

  matrix M(mask, mask);
  vector<int> val = {1, 1, 2, 3, 5, 8, 13, 21, 34};

  forn(i, 0, mask){
      forn(j, 0, mask){
          int mask1 = i&(mask-1);
          int mask2 = j&(mask-1);
          if((mask1&mask2) > 0)continue;
          int cnt = 0;
          M.m[i][j] = 1;
          forn(k, 0, n){
              if(!(i&(1<<k)) && !(j&(1<<k))){
                  cnt++;
              }else{
                  M.m[i][j] *= val[cnt];
                  cnt = 0;
              }
          }
          M.m[i][j] *= val[cnt];
      }
  }

    M = pow(M, m);


    cout << M.m[0][0] << endl;

}


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

#define MOD 1000000009
const int N = (1<<8);
int m;

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

int dx[8] = { 1, 2, 1, 2, -1, -2, -1, -2};
int dy[8] = { 2, 1, -2, -1, 2, 1, -2, -1};

bool validate(vector<bitset<4> >& board){
    forn(i, 0, 3){
        forn(j, 0, m){
            if(!board[i][j])continue;
            forn(k, 0, 8){
                int nxt_i = i + dx[k];
                int nxt_j = j + dy[k];
                if(nxt_i < 0 || nxt_i >= 3 || nxt_j < 0 || nxt_j >= m)continue;
                if(board[nxt_i][nxt_j])return false;
            }
        }
    }
    return true;
}


int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int t, n;

  cin >> t;

  while(t--){
      cin >> m >> n;

      int mask = 1<<(2*m);
      int cmpF = (1<<m)-1;
      int cmpS = mask-1-cmpF;

      matrix M(mask, mask);

    forn(i, 0, mask){
        forn(j, 0, mask){
            bitset<4> i_fst, i_scnd, j_fst, j_scnd;
            i_fst = i&cmpF;
            i_scnd = (i&cmpS) >> m;
            j_fst = j&cmpF;
            j_scnd = (j&cmpS) >> m;
            if(i_scnd != j_fst)continue;
            vector<bitset<4> > board = {i_fst, j_fst, j_scnd};
            if(validate(board)){
                M.m[i][j] = 1;
            }
            
        }
    }

    M = pow(M, n);

    ll ans = 0;

    forn(i, 0, mask){
        ans = (ans + M.m[0][i])%MOD;
    }

    cout << ans << endl;

  }

}


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

const int N = 50;
int mod = 1e9+7, n;
ll m;

struct matrix{
    int m[N][N], r, c;
    
    matrix(int _r = N, int _c = N, bool iden = false){
        r = _r;
        c = _c;
        memset(m, 0, sizeof m);
        if(iden) while(_c--) m[_c][_c] = 1;
    }

    matrix operator * (const matrix &B){
        matrix C(r, B.c);
        forn(i, 0, r){
            forn(k, 0, c){
                if(m[i][k]){
                    forn(j, 0, B.c){
                        C.m[i][j] = (1ll*C.m[i][j] + 1ll*m[i][k]*B.m[k][j]) % mod;
                    }
                }
            }
        }
        return C;
    }
};

matrix pow(matrix A, ll e){
    matrix ANS(A.r, A.c, true);
    while(e){
        if(e&1)ANS = ANS*A;
        A = A*A;
        e >>= 1;
    }
    return ANS;
}


int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n >> m;

  matrix M(n, n);

  forn(i, 0, n){
    forn(j, 0, n){
        cin >> M.m[i][j];
    }
  }

  matrix ans = pow(M, m);

  int r = 0;

forn(i, 0, n){
    forn(j, 0, n){
        r = (r+ans.m[i][j])%mod;
    }
}
cout << r << endl;




}




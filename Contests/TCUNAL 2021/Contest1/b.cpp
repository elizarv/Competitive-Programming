#include <bits/stdc++.h>
using namespace std;
void debug() {cout<<endl;}
template<typename T,typename... Args>
void debug(T a,Args... args) {cout<<a<<" ";debug(args...);}
#define forn(i,a,b) for(int i=a;i<b;++i)
#define pb push_back
#define F first
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;

const int N = 405, mod = 1e9 + 7;
int sz[N], cnt[N], ans[N], pot[N], n;

int add(int a, int b){
    if(a + b < mod)return a + b;
    return a + b - mod;
}

int mul(int a, int b){
    if(1ll * a * b < mod)return a * b;
    return (1ll * a * b) % mod;
}

void f(int k){
    if(!k)return;
    f(k-1);
    sz[k] = add(mul(sz[k-1], 2), 1);
    cnt[k] = mul(sz[k-1], sz[k-1]);
    cnt[k] = mul(cnt[k], 2);
    cnt[k] = add(cnt[k], mul(4, sz[k-1]));
    cnt[k] = add(cnt[k], 1);
    ans[k] = cnt[k];
    if(k < 3)return;
    forn(i, 1, k+1){
        ans[k] = add(ans[k], mul(ans[i], pot[n-i]));
    }
}

void pre(){
    pot[0] = 1;
    forn(i, 1, N){
        pot[i] = mul(pot[i-1], 2);
    }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  pre();

    cin >> n;
    f(n);

    int r = 0;
    
    forn(i, 0, n+1){
        r = add(r, ans[i]);
    }

    debug(r);

}
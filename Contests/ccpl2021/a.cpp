//Solution to contest https://vjudge.net/contest/415545
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

const int inf = 1e9;
const int MX = 205; 
vector<int> g[MX]; 
int in[MX], out[MX];
int n, entr, ext;


void init(){
    forn(i, 0, n){
        g[i].clear();
        in[i] = out[i] = 0;
    }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int m;
  while(cin >> n >> m){
    init();
    forn(i, 0, m){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        in[v]++;
        out[u]++;
    }
    forn(i, 0, n){
        if(!in[i])entr = i;
        if(!out[i])ext = i;
    }
    vector<int> cur = {entr};
    int mx = 0;
    while(cur.size()){
        vector<int> aux;
        mx = max(mx, (int)cur.size());
        for(auto &u: cur){
            for(int &v: g[u]){
                in[v]--;
                if(!in[v])aux.pb(v);
            }
        }
        swap(cur, aux);
    }

    cout << mx << endl;
  }

  

}
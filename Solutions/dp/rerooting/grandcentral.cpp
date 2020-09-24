/*
Tree hashing + rerooting problem
https://www.acmicpc.net/problem/17800
*/

#include <bits/stdc++.h>
using namespace std;
#define fore(i,a,b) for(int i=a,gon=b;i<gon;++i)
#define pb push_back
#define F first
#define S second
typedef double lf;
typedef long long ll;
typedef pair<int, int> pii;



const int MAX = 300005;
ll R = 1e13;
auto rnd=bind(uniform_int_distribution<long long>(0,R), mt19937(time(0)));

vector<int> g[MAX];
map<ll, ll> mp;
set<ll> ans;
ll h[MAX];

ll f(ll sum){
    if(!mp.count(sum)){
        mp[sum] = rnd();
    }
    return mp[sum];
}


ll dfs(int u, int p){
    ll sum = 0;
    for(auto v: g[u]){
        if(v == p)continue;
        sum += dfs(v, u);
    }
    return h[u] = f(sum);
}

void dfs2(int u, int p, ll sum_up){
    ll sum_ch = 0;
    for(auto v: g[u]){
        if(v == p)continue;
        sum_ch += h[v];
    }
    ans.insert(f(sum_up+sum_ch));
    for(auto v: g[u]){
        if(v == p)continue;
        dfs2(v, u, f(sum_up+sum_ch-h[v]));
    }
}




int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    #ifdef LOCAL
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #else
        #define endl '\n'
    #endif // LOCAL

    int n, u, v;

    cin >> n;

    for(int i = 0; i < n-1; i++){
        cin >> u >> v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }

    dfs(0, -1);

    dfs2(0, -1, 0);

    cout << ans.size() << endl;



}

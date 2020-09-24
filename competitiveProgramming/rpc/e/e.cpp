#include <bits/stdc++.h>
using namespace std;
void debug() {cout<<endl;}
template<typename T,typename... Args>
void debug(T a,Args... args) {cout<<a<<" ";debug(args...);}
#define forn(i,a,b) for(int i=a,gon=b;i<gon;++i)
#define pb push_back
#define F first
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;

const int N = 122, M = 81, MAX = N*M, inf = 1e9;
int sz[N], targeti, targetj;
int d[N][M], n;
queue<pii > q;

void init(){
    memset(sz, 0, sizeof sz);
    memset(d, 63, sizeof d);
    while(q.size())q.pop();
}

void relax(int i, int j, int cnt){
    if(d[i][j] > cnt){
        d[i][j] = cnt;
        q.push({i, j});
    }
}

int bfs(int i, int j){
    d[i][j] = 0;
    q.push({i, j});

    while(q.size()){
        i = q.front().F;
        j = q.front().S;
        int cnt = d[i][j];
        q.pop();
        if(i == targeti && j == targetj)return cnt;
        // up
        if(i)relax(i-1, min(j, sz[i-1]), cnt+1);
        // down
        if(i < n-1) relax(i+1, min(j, sz[i+1]), cnt+1);
        // left
        if(j) relax(i, j-1, cnt+1);
        else if(i) relax(i-1, sz[i-1], cnt+1);
        // right
        if(j < sz[i])relax(i, j+1, cnt+1);
        else if(i < n-1)relax(i+1, 0, cnt+1);
    }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

int t, ini, fin;

cin >> t;

while(t--){
    cin >> n;
    init();
    forn(i, 0, n){
        cin >> sz[i];
    }
    cin >> ini >> fin >> targeti >> targetj;
    ini--, targeti--;
    cout << bfs(ini, fin) << endl;
    
}



  
}

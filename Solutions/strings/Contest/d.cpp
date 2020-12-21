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

const int alpha = 26; 
const char L = 'a'; 
const int MX = 4e5 + 5;
vector<int> ans;
vector<pii> query[MX]; // node, id_ans

struct node {
    int next[alpha], end;
    int link, exit, cnt, r; 
    int& operator[](int i) { return next[i]; }
};

vector<node> trie = {node()};

void add_str(string &s, int id = 1, int q = 0) {
    int u = 0;
    for (auto ch : s) {
        int c = ch-L;
        if (!trie[u][c]) {
            trie[u][c] = trie.size();
            trie.push_back(node());
        }
        u = trie[u][c];
    }
    trie[u].end = id;
	query[q].pb({u, id});
}

void build_ac() {
    queue<int> q; q.push(0);
    while (q.size()) {
        int u = q.front(); q.pop();
        for (int c = 0; c < alpha; ++c) {
            int v = trie[u][c];
            if (!v) trie[u][c] = trie[trie[u].link][c];
            else q.push(v);
            if (!u || !v) continue;
            trie[v].link = trie[trie[u].link][c];
			trie[v].exit = trie[trie[v].link].end ? trie[v].link : trie[trie[v].link].exit;
        }
    }
}

int let[MX], id[MX];
vector<int> g[MX];

void solve(int id){
	for(auto x: query[id]){
		int nx = x.F;
		int q = x.S;
		ans[q-1] = trie[nx].r;
	}
}

void dfs(int u = 0, int cur = 0){
	for(int v: g[u]){
		int c = let[v];
		int aux = trie[cur][c];
        int x = aux;
        while(x){
            trie[x].r++;
            x = trie[x].exit;
        }
		solve(v);
		dfs(v, aux);
        x = aux;
        while(x){
            trie[x].r--;
            x = trie[x].exit;
        }
	}
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int n;
  cin >> n;
  int nodes = 1;

  forn(i, 0, n){
      int t;
      cin >> t;
      id[nodes] = i;
      if(t == 1){
          char c;
          cin >> c;
          let[nodes] = c - L;
          g[0].pb(nodes++);
      }else{
          int j;
          char c;
          cin >> j >> c;
          let[nodes] = c - L;
          g[j].pb(nodes++);
      }
  }

	int q; cin >> q;
	ans = vector<int>(q+1, 0);
	forn(i, 0, q){
		int x;
		string s;
		cin >> x >> s;
		add_str(s, i+1, x);
	}

	build_ac();

	dfs();

	forn(i, 0, q){
		cout << ans[i] << endl;
	}



  
}
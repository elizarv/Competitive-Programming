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

const int alpha = 26, inf = 1e9; 
const char L = 'a'; 

struct node {
    int next[alpha] = {};
    int link = 0, exit = 0, end = inf; 
    int& operator[](int i) { return next[i]; }
};

vector<node> trie;

void add_str(string &s, int id = 1) {
    int u = 0;
    for (auto ch : s) {
        int c = ch-L;
        if (!trie[u][c]) {
            trie[u][c] = trie.size();
						node root = node();
            trie.push_back(root);
        }
        u = trie[u][c];
    }
    trie[u].end = min(trie[u].end, id);
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
						trie[v].end = min(trie[v].end, trie[trie[v].link].end);
        }
    }
}

bool run_ac(string s, int q){
	int n = s.size();
	int cur = 0;
	forn(i, 0, n){
		int c = s[i]-L;
		cur = trie[cur][c];
		if(trie[cur].end < q)return true;
	}
	return false;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int n; cin >> n;

  vector<pair<int, string>> query;

	node root = node();
	trie.pb(root);

  forn(i, 1, n+1){
	  int type;
	  string s;
	  cin >> type >> s;
	  if(type) query.pb({i, s});
	  else add_str(s, i);
  }
  build_ac();

  for(auto x: query){
	  if(run_ac(x.S, x.F))cout << "YES" << endl;
	  else cout << "NO" << endl;
  }

  
}
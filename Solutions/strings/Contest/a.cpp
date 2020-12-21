//Contest: https://vjudge.net/contest/405013
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

struct node {
    int next[alpha], end;
    int link, exit, cnt;
    int& operator[](int i) { return next[i]; }
};

vector<node> trie = {node()};

void add_str(string &s, int id = 1) {
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

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

	string s;
	cin >> s;

	int q, a, b;
	cin >> q >> a >> b;

	map<string, int> words;
	vector<int> query;

	forn(i, 1, q+1){
		string t;
		cin >> t;
		if(!words.count(t))words[t] = i;
		int id = words[t];
		add_str(t, id);
		query.pb(id);
	}

	build_ac();

	vector<ll> ans(q+1);
	int cur = 0;
	int n = s.size();
	forn(i, 0, n){
		int c = s[i]-L;
		cur = trie[cur][c];
		int aux = cur;
		while(aux){
			int id = trie[aux].end;
			ans[id]++;
			aux = trie[aux].exit;
		}
	}
	forn(i, 0, q){
		ll r = ans[query[i]];
		cout << r << endl;
		ll c = (1ll* a * r + b) % 26;
		cur = trie[cur][c];
		int aux = cur;
		while(aux){
			int id = trie[aux].end;
			ans[id]++;
			aux = trie[aux].exit;
		}
	}


  
}
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
const char L = 'A'; 

struct node {
    int next[alpha], cnt[2] = {0,0};
		bool end;
    int& operator[](int i) { return next[i]; }
};

vector<node> trie;
int ans = 0;

void init(){
    trie.clear();
    trie.pb(node());
		ans = 0;
}


void add_str(string &s, int id) {
    int u = 0;
    for (auto ch : s) {
        int c = ch-L;
        if (!trie[u][c]) {
            trie[u][c] = trie.size();
            trie.push_back(node());
        }
        u = trie[u][c];
				trie[u].cnt[id]++;
    }
    trie[u].end = true;
}

void dfs(int u){
	forn(c, 0, alpha){
		int v = trie[u][c];
		if(!v)continue;
		ans += min(trie[v].cnt[0], trie[v].cnt[1]);
		dfs(v);
	}
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

	int n;
	while(cin >> n){
		if(n == -1)break;
		init();
		string s;
		forn(it, 0, 2){
			forn(i, 0, n){
				cin >> s;
				add_str(s, it);
			}
		}
		dfs(0);
		cout << ans << endl;
	}
  
  
}
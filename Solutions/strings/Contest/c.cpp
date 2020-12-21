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

const int N = 3e5+5;
multiset<int> vals[N];
int val[N], ids[N];
int sz = 1;
string words[N];

struct node {
    int next[alpha], end;
    int link, exit; 
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
    vals[u].insert(0);
    ids[id] = u;
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



inline int run_ac(string &s){
    int ans = -1;
    int cur = 0;
    int n = s.size();
    forn(i, 0, n){
        int c = s[i]-L;
        cur = trie[cur][c];
        int aux = cur;
        while(aux){
            if(vals[aux].size()){
                int v = *vals[aux].rbegin();
                ans = v > ans ? v : ans;
            }
            aux = trie[aux].exit;
        }
    }
    return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  trie.reserve(N);

  int n, q;
  cin >> n >> q;

  forn(i, 0, n){
      string s;
      cin >> s;
      words[i+1] = s;
      add_str(s, i+1);
  }
  vals[0].insert(0);

  build_ac();

  forn(i, 0, q){
      int t; cin >> t;
      if(t == 1){
          int pos, x;
          cin >> pos >> x;
          int id = ids[pos];
          vals[id].erase(vals[id].find(val[pos]));
          val[pos] = x;
          vals[id].insert(x);
      }else{
          string s; cin >> s;
          int ans = run_ac(s);
          cout << ans << endl;
      }
  }



  
}
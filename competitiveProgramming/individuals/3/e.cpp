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

const int N = 26;
pair<pii, pii> Sna[N];
bool check[N];
string grid[2005];
pii ini = {-1, -1};
vector<int> sec;
int n, m, mx;


bool paint(vector<string>& g){
	string aux = "";
	forn(i, 0, m){
		aux += '.';
	}
	forn(i, 0, n)g[i] = aux;
	forn(c, 0, mx+1){
		if(!check[c])continue;
		sec.pb(c);
		if(Sna[c].F.F != Sna[c].S.F && Sna[c].F.S != Sna[c].S.S)return false;
		forn(i, Sna[c].F.F, Sna[c].S.F+1){
			forn(j, Sna[c].F.S, Sna[c].S.S+1){
				g[i][j] = c+'a';
			}
		}
	}
	return true;
}

void init(){
	forn(i, 0, N){
		check[i] = false;
	}
	mx = 0;
	sec.clear();
}


bool same(vector<string>& g){
	forn(i, 0, n){
		forn(j, 0, m){
			if(g[i][j] != grid[i][j])return false;
		}
	}
	return true;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

	int t;
	char c;
	cin >> t;
	while(t--){
		cin >> n >> m;
		init();
		bool f = false;
		forn(i, 0, n){
			cin >> grid[i];
			forn(j, 0, m){
				c = grid[i][j];
				if(c == '.')continue;
				mx = max(mx, c-'a');
				if(!f){
					f = true;
				}
				if(!check[c-'a']){
					check[c-'a'] = true;
					Sna[c-'a'] = {{i, j}, {i, j}};
				}else{
					Sna[c-'a'].S = {i, j};
				}
			}
		}
		if(!f){
			cout << "YES" << endl;
			cout << "0" << endl;
			continue;
		}
		vector<string> g(n);
		if(!paint(g)){
			cout << "NO" << endl;
			continue;
		}
		if(same(g)){
			cout << "YES" << endl;
			cout << mx+1 << endl;
			int id = 0;
			forn(i, 0, mx+1){
				int nxt = sec[id];
				if(nxt == i)id++;
				if(!check[i]){
					cout << Sna[nxt].F.F+1 << " " << Sna[nxt].F.S+1 << " ";
					cout << Sna[nxt].F.F+1 << " " << Sna[nxt].F.S+1 << endl;
				}else{
					cout << Sna[i].F.F+1 << " " << Sna[i].F.S+1 << " ";
					cout << Sna[i].S.F+1 << " " << Sna[i].S.S+1 << endl;
				}
			}
		}else{
			cout << "NO" << endl;
		}
	
	}
  


}




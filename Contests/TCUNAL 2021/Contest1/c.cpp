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

const int N = 700;
string mat[N];
vector<int> hor[N], ver[N];

vector<int> manacher(string s) {
    int n = s.size();
    vector<int> p(n, 0);
    int c = 0, r = 0;
    for (int i = 1; i < n-1; i++) {
        int j = c - (i-c) ;
        if (r > i) p[i] = min(r-i , p[j]);
        while (s[i+1+p[i]] == s[i-1-p[i]])
            p[i]++;
        if (i+p[i] > r) {
            c = i;
            r = i+p[i];
        }
    }
    return p;
}


ll val(int x){
	return (x+1)/2;
}


int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int n, m;
  cin >> n >> m;
  char c;
  forn(j, 0, 2*m+3){
		mat[0].pb('%');
	}
  for(int i = 1; i < 2*n+2; i++){
      mat[i].pb('%');
      if(i&1){
				forn(j, 0, 2*m){
            mat[i].pb('#');
        }
				mat[i].pb('#');
			}else{
        forn(j, 0, m){
            mat[i].pb('#');
            cin >> c;
            mat[i].pb(c);
        }
        mat[i].pb('#');
      }
      mat[i].pb('&');
  }
	n = 2*n+3;
	m = 2*m+3;
	forn(j, 0, 2*m+3){
		mat[n-1].pb('%');
	}

  forn(i, 0, n){
      hor[i] = manacher(mat[i]);
  }

	forn(j, 0, m){
		string t = "";
		forn(i, 0, n){
			t.pb(mat[i][j]);
		}
		vector<int> man = manacher(t);
		forn(i, 0, n){
			ver[i].pb(man[i]);
		}
	}


	// forn(i, 2, n-2){
	// 	forn(j, 2, m-2){
	// 		cout << hor[i][j] << " ";
	// 	}debug();
	// }
	// debug();

	// forn(i, 2, n-2){
	// 	forn(j, 2, m-2){
	// 		cout << ver[i][j] << " ";
	// 	}debug();
	// }
	// debug();

	ll ans = 0;

	forn(i, 2, n-2){
		forn(j, 2, m-2){
			if(i%2 == 0 && j%2 == 0){
				ans += val(ver[i][j]) * val(hor[i][j]);
			}else{
				if((i&1)){
					int mn = N;
					int dif = ver[i][j];
					int l = i - dif/2, r = i + dif/2;
					for(int k = l; k <= r; k += 2){
						mn = min(mn, hor[k][j]);
					}
					ans += val(mn) * val(ver[i][j]-1);
				}
		 	if((j&1)){
					int mn = N;
					int dif = hor[i][j];
					int l = j - dif/2, r = j + dif/2;
					for(int k = l; k <= r; k += 2){
						mn = min(mn, ver[i][k]);
					}
					ans += val(mn) * val(hor[i][j]-1);
				}
			}
		}
	}

	cout << ans << endl;


}
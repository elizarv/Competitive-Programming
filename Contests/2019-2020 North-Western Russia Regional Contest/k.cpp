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

const int MX = 1005;
int pre[MX][MX], suf[MX][MX], mat[MX][MX], og[MX][MX];
int N, M;
pii let[26];

int getright(int i, int j, int p){
  int l = p, r = M+1;
  int val = pre[j][p] - pre[i-1][p];
  while(l < r){
    int m = (l+r)/2;
    int aux = pre[j][m] - pre[i-1][m];
    if(aux == val) l = m+1;
    else r = m;
  }
  return l-1;
}

int getleft(int i, int j, int p){
  int l = 1, r = p;
  int val = suf[j][p] - suf[i-1][p];
  while(l < r){
    int m = (l+r)/2;
    int aux = suf[j][m] - suf[i-1][m];
    if(aux == val) r = m;
    else l = m+1;
  }
  return l;
}

void getpre(){
	forn(i, 1, N+1){
    forn(j, 1, M+2){
			pre[i][j] = mat[i][j];
      pre[i][j] += pre[i-1][j];
      pre[i][j] += pre[i][j-1];
      pre[i][j] -= pre[i-1][j-1];
    }
  }
}

void getsuf(){
	forn(i, 1, N+1){
    for(int j = M+1; j >= 0; j--){
			suf[i][j] = mat[i][j];
      suf[i][j] += suf[i][j+1];
      suf[i][j] += suf[i-1][j];
      suf[i][j] -= suf[i-1][j+1];
    }
  }
}

void up(int I, int i, int j, int c){
	while(i >= I && og[i][j] == '.'){
		og[i][j] = c;
		i--;
	}
}

void down(int J, int i, int j, int c){
	while(i <= J && og[i][j] == '.'){
		og[i][j] = c;
		i++;
	}
}

void right(int R, int i, int j, int c){
	while(j <= R && og[i][j] == '.'){
		og[i][j] = c;
		j++;
	}
}

void left(int L, int i, int j, int c){
	while(j >= L && og[i][j] == '.'){
		og[i][j] = c;
		j--;
	}
}

void fill(int I, int J, int L, int R){
	forn(i, I, J+1){
		forn(j, L, R+1){
			if(og[i][j] >= 'A' && og[i][j] <= 'Z'){
				up(I, i-1, j, og[i][j]+32);
				down(J, i+1, j, og[i][j]+32);
			}
		}
	}
	forn(i, I, J+1){
		forn(j, L, R+1){
			if(og[i][j] == '.')continue;
			int c = og[i][j];
			if(og[i][j] >= 'A' && og[i][j] <= 'Z')c += 32;
			right(R, i, j+1, c);
			left(L, i, j-1, c);
		}
	}
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  // g++ -pthread -Wall -Wshadow -std=c++17 -o main k.cpp && ./main < k.txt

  cin >> N >> M;
  pii pos;
  forn(i, 1, N+1){
    string s;
    cin >> s;
    forn(j, 1, M+1){
      char c = s[j-1];
      if(c == '.')mat[i][j] = 0;
      else{
				mat[i][j] = 1;
				if(c != 'A')let[c-'A'] = {i, j};
			}
			og[i][j] = c;
      if(c == 'A')pos = {i, j};
    }
  }

	getpre();
	getsuf();
  

//   forn(i, 0, N+1) {
//     forn(j, 0, M+2) {
//       cout << mat[i][j] << " \n"[j==M+1];
//     }
//   }

int ans = 0, I, J, L, R;
  

  forn(i, 1, pos.F+1){
    forn(j, pos.F, N+1){
		if(pre[j][pos.S] - pre[j][pos.S-1] - pre[i-1][pos.S] + pre[i-1][pos.S-1] != 1)continue;
      int r = getright(i, j, pos.S);
      int l = getleft(i, j, pos.S);
      int a = j-i+1;
      int b = r-l+1;
      if(a*b > ans){
          ans = a*b;
					I = i, J = j, L = l, R = r;
      }
    }
  }

	forn(i, I, J+1){
		forn(j, L, R+1){
			if(i == pos.F && j == pos.S)continue;
			og[i][j] = 'a';
			mat[i][j] = 1;
		}
	}

	fill(1, I-1, 1, M);
	fill(J+1, N, 1, M);
	fill(I, J, 1, L-1);
	fill(I, J, R+1, M);


	forn(i, 1, N+1){
		forn(j, 1, M+1){
			cout << (char)og[i][j];
		}cout << endl;
	}

}
#include <bits/stdc++.h>
using namespace std;
void debug() { cout << endl; }
template <typename T, typename... Args>
void debug(T a, Args... args) { cout << a << " "; debug(args...);}
#define forn(i, a, b) for (int i = a; i < b; ++i)
#define SZ(x) int(x.size())
#define pb push_back
#define F first
#define S second
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;


typedef ll big;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

	double n, a, b;

	cin >> n >> a >> b;

	double ans = 0.0;
	int m = b-a+1;
	double prob = 1.0f/m;
	debug(prob);

	forn(i, a, b+1){
		ans += double(n)/i * prob;
	}

	cout << ans << endl;



  

  
}

/*
g++ -pthread -Wall -Wshadow -std=c++17 -o main main.cpp && ./main < main.txt
freopen("input.in", "r" , stdin);
freopen("output.out", "w", stdout);
*/
#include <bits/stdc++.h>
using namespace std;
void debug() { cout << endl; }
template <typename T, typename... Args>
void debug(T a, Args... args) {
  cout << a << " ";
  debug(args...);
}
#define forn(i, a, b) for (int i = a; i < b; ++i)
#define SZ(x) int(x.size())
#define pb push_back
#define F first
#define S second
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int hh, mm, ss;
  char c;
  cin >> hh >> c >> mm;

  int a = hh*3600 + mm*60;
  int b = hh*60 + mm;

  a -= b;

  hh = a/3600;
  a -= 3600*hh;

  mm = a/60;
  a -= 60*mm;

  ss = a;

  if(hh < 10)cout << "0";
  cout << hh << ":";
  if(mm < 10)cout << "0";
  cout << mm << ":";
  if(ss < 10)cout << "0";
  cout << ss << endl;


}

#include <bits/stdc++.h>
using namespace std;
void print() {cout<<endl;}
template<typename T,typename... E>
void print(T t,E... e) {cout<<t<<(sizeof...(e)?" ":"");print(e...);}
#define forn(i,x,n) for(int i=int(x);i<int(n);++i)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define F first
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;

const int n = 4;
int v[n];
vector<int> nums;
vector<int> op;
set<int> st;
int m;

void calc(int id) {
  if (id == m) {
    int ans = 0;
    for (auto &x : op) ans += x;
    if (ans >= 0) st.insert(ans);
    return;
  }
  op.pb(nums[id]);
  calc(id+1);
  op.pop_back();

  op.pb(-nums[id]);
  calc(id+1);
  op.pop_back();

  op.back() *= nums[id];
  calc(id+1);
  op.back() /= nums[id];

  return;
}

void go(int id) {
  if (id == n) {
    m = nums.size();
    op = {nums[0]};
    calc(1);
    return;
  }
  int num = 0, lim = id ? n : n-1;
  forn(i, id, lim) {
    num = num*10 + v[i];
    nums.pb(num);
    go(i+1);
    nums.pop_back();
  }
  return;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  forn(i, 0, n) cin >> v[i];
  sort(v, v+n);

  do {
    go(0);
  } while (next_permutation(v, v+n));

  cout << st.size() << endl;
}

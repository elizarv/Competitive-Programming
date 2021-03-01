#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
#define forn(i, a, b) for (int i = a; i < b; ++i)
#define SZ(x) int(x.size())
#define pb push_back
#define F first
#define S second
void debug() { cout << endl; }
template <typename T, typename... Args>
void debug(T a, Args... args) { cout << a << " "; debug(args...);}

const int N = 17000+5, P = 1000;
int board[N];
bool safe[N];
int start[P];
int entrance[P];
int pos[P];
int k, mx;
int winner = -1;
int turn = 0;
int goal = 7777;

vector<int> lst[P];

void pre(){
    mx = k*17;
    forn(i, 0, mx+1){
        board[i] = -1;
    }
    forn(i, 0, k){
        pos[i] = -1;
        lst[i].clear();
    }
    winner = -1;
    turn = 0;
    int p = 0, i = 0;
    while(i < mx){
        
        start[p] = i;
        entrance[p] = (i-5+mx)%mx;
        lst[p].pb(-1);
        pos[p] = -1;

        safe[i] = true;
        i += 7;
        safe[i] = true;
        i += 5;
        safe[i] = true;
        i += 5;
        p++;
    }
}

void upandback(int cur, int moves){
    int dif = min(goal-cur, moves);
    cur += dif;
    moves -= dif;
    while(moves){
        cur--;
        moves--;
        if(cur+1 == 7770)cur = entrance[turn];
    }
    if(cur < mx && !safe[cur]){
        if(board[cur] != -1){ // se come la ficha
            int ficha = board[cur]; // ficha que se come
            pos[ficha] = -1; // pos de la ficha que va al inicio
            lst[ficha].pb(-1); // agrega pos de ficha en el inicio
        }
        if(!safe[cur])board[cur] = turn;
    }
    pos[turn] = cur;
    lst[turn].pb(cur);
    if(cur == goal){
        winner = turn;
    }
}

void especial(int cur, int nxt, int moves){
    int dif = entrance[turn]-cur;
    cur += dif;
    moves -= dif;
    moves--;
    cur = 7770;
    upandback(cur, moves);
}

bool validate(int cur, int moves){
    forn(i, 0, moves){
        if(cur == entrance[turn])return true;
        cur = (cur+1)%mx;
    }
    return false;
}

void play(int x, int y){
    int cur = pos[turn]; // posicion actual
    if(cur >= 7770){
        upandback(cur, x+y);
        return;
    }
    int nxt = cur+x+y; // pos siguiente
    board[cur] = -1;
    if(validate(cur, x+y)){// entra a la zona segura
        especial(cur, nxt, x+y);
    }else{
        nxt = nxt%mx;
        if(board[nxt] != -1){ // se come la ficha
            int ficha = board[nxt]; // ficha que se come
            pos[ficha] = -1; // pos de la ficha que va al inicio
            lst[ficha].pb(-1); // agrega pos de ficha en el inicio
        }
        if(!safe[nxt])board[nxt] = turn; // si no es seguro
        pos[turn] = nxt;
        lst[turn].pb(nxt);
    }
}

void par(int x, int y){
    if(pos[turn] == -1){
        pos[turn] = start[turn]; //nueva posicion
        lst[turn].pb(pos[turn]); // agrego posicion
    }else{
        play(x, y);
    }
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;

  while(cin >> k >> n){
    pre();

    char d1, d2;

    forn(i, 0, n){
        cin >> d1 >> d2;
        if(winner != -1)continue;
        int x = d1 - '0';
        int y = d2 - '0';
        //   debug(turn, x, y);
        if(d1 == d2)par(x, y);
        else{
            if(pos[turn] != -1)play(x, y);
            else{
                lst[turn].pb(pos[turn]);
            }
                turn = (turn+1) % k;
        }
        //   forn(i, 0, k) cout << pos[i] << " ";
        //   debug();
    }

    forn(i, 0, k){
        cout << "Player " << i+1 << " = {";
        int sz = lst[i].size();
        forn(j, 0, sz){
            cout << lst[i][j] << ",}"[j+1 == sz];
        }cout << endl;
    }
    if(winner != -1){
        cout << "The winner is Player " << winner+1 << endl;
    }else{
        cout << "There is no winner yet" << endl;
    }

  } 
}
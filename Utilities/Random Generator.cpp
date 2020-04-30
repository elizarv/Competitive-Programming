//unsigned int
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

// long long
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

// int en rango [L,R]
auto rnd=bind(uniform_int_distribution<int>(L,R), mt19937(time(0)));

// long long en rango [L,R]
auto rnd=bind(uniform_int_distribution<long long>(L,R), mt19937(time(0)));

// double en rango [L, R)
auto rnd=bind(uniform_real_distribution<double>(L,R), mt19937(time(0)));

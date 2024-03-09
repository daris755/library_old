#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
#include <atcoder/all>
using namespace atcoder;
#endif

#define overload4(_1, _2, _3, _4, name, ...) name
#define each1(i, a) for (auto &&i : a)
#define each2(i, j, a) for (auto &&[i, j] : a)
#define each3(i, j, k, a) for (auto &&[i, j, k] : a)
#define each(...) overload4(__VA_ARGS__, each3, each2, each1)(__VA_ARGS__)
#define all1(v) (v).begin(), (v).end()
#define all2(v, b) (v).begin(), (v).begin() + b
#define all3(v, a, b) (v).begin() + a, (v).begin() + b
#define all4(v, a, b, c) (v).begin() + a, (v).begin() + b, c
#define all(...) overload4(__VA_ARGS__, all4, all3, all2, all1)(__VA_ARGS__)
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i, j, n) for (ll i = j; i < (ll)(n); i++)
#define rrep(i, j, n) for (ll i = j; i > (ll)(n); i--)

template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;
template <class T>
using PQ = priority_queue<T>;
template <class T>
using PQgre = priority_queue<T, V<T>, greater<T>>;

using ll = long long;
using ld = long double;
using LL = __int128_t;
// using ull = unsigned long long;
using uLL = __uint128_t;
using pii = pair<int, int>;
using psi = pair<string, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using vb = V<bool>;
using vi = V<int>;
using vd = V<double>;
using vc = V<char>;
using vs = V<string>;
using vvb = V<vb>;
using vll = V<ll>;
using vld = V<ld>;
using vvi = V<vi>;
using vvd = V<vd>;
using vvll = V<vll>;
using vvld = V<vld>;
using vvc = V<vc>;
using vpii = V<pii>;
using vpll = V<pll>;
using vpil = V<pil>;
using vpli = V<pli>;

[[maybe_unused]] const int inf = 1LL << 30;
[[maybe_unused]] const ll infl = 1LL << 60;
const double pi = acos(-1.0);
const int mod1 = 998244353;
const int mod2 = 1000000007;
const int mod3 = 1000000009;

// input
// prototype
template <typename T, typename Ta>
istream &operator>>(istream &is, pair<T, Ta> &p);
template <typename T>
istream &operator>>(istream &is, vector<T> &v);
template <typename T>
istream &operator>>(istream &is, vector<vector<T>> &v);
istream &operator>>(istream &is, __int128_t &x);
template <class T>
void input(T &a);
template <class T, class... Ts>
void input(T &a, Ts &...b);

template <typename T, typename Ta>
istream &operator>>(istream &is, pair<T, Ta> &p) {
    is >> p.first >> p.second;
    return is;
}

template <typename T>
istream &operator>>(istream &is, vector<T> &v) {
    for (auto &&c : v)
        is >> c;
    return is;
}

template <typename T>
istream &operator>>(istream &is, vector<vector<T>> &v) {
    for (auto &&c : v)
        is >> c;
    return is;
}

istream &operator>>(istream &is, __int128_t &x) {
    x = 0;
    string s;
    is >> s;
    bool res = s[0] == '-';
    for (size_t i = (res ? 1 : 0); i < s.size(); i++) {
        x *= 10;
        x += s[i] - '0';
    }
    if (res) x = -x;
    return is;
}

istream &operator>>(istream &is, __uint128_t &x) {
    x = 0;
    string s;
    is >> s;
    for (size_t i = 0; i < s.size(); i++) {
        x *= 10;
        x += s[i] - '0';
    }
    return is;
}

template <class T>
void input(T &a) {
    cin >> a;
}

template <class T, class... Ts>
void input(T &a, Ts &...b) {
    cin >> a;
    input(b...);
}

// output
// prototype
template <typename T, typename Ta>
ostream &operator<<(ostream &os, const pair<T, Ta> &p);
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v);
template <typename T>
ostream &operator<<(ostream &os, const vector<vector<T>> &v);
template <typename T, typename Ta>
ostream &operator<<(ostream &os, const map<T, Ta> &mp);
template <typename T>
ostream &operator<<(ostream &os, const set<T> &s);
template <typename T>
ostream &operator<<(ostream &os, const multiset<T> &ms);
template <typename T>
ostream &operator<<(ostream &os, const priority_queue<T> &q);
template <typename T>
ostream &operator<<(ostream &os,
                    const priority_queue<T, vector<T>, greater<T>> &q);
template <typename T>
ostream &operator<<(ostream &os, const queue<T> &q);
template <typename T, size_t... index>
void printTuple(ostream &os, const T &tp, index_sequence<index...>, size_t n);
template <typename T>
void forTuple(ostream &os, const T &tp);
template <typename... T>
ostream &operator<<(ostream &os, const tuple<T...> &tp);
ostream &operator<<(ostream &os, const __int128_t &x);
ostream &operator<<(ostream &os, const __uint128_t &x);
void print();
template <class T>
void print(const T &a);
template <class T, class... Ts>
void print(const T &a, const Ts &...b);

template <typename T, typename Ta>
ostream &operator<<(ostream &os, const pair<T, Ta> &p) {
    os << "{ " << p.first << ", " << p.second << " }";
    return os;
}

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    os << "[ ";
    for (size_t i = 0; i < v.size(); i++) {
        os << v[i] << (i == v.size() - 1 ? "" : ", ");
    }
    return os << " ]";
}

template <typename T>
ostream &operator<<(ostream &os, const vector<vector<T>> &v) {
    os << "[\n";
    for (size_t i = 0; i < v.size(); i++) {
        os << "[ ";
        for (size_t j = 0; j < v[i].size(); j++) {
            os << v[i][j] << (j == v[i].size() - 1 ? "" : ", ");
        }
        os << " ]";
        os << (i == v.size() - 1 ? "" : "\n");
    }
    return os << "\n]";
}

template <typename T, typename Ta>
ostream &operator<<(ostream &os, const map<T, Ta> &mp) {
    os << "{ ";
    auto it = mp.begin();
    while (it != mp.end()) {
        os << (it == mp.begin() ? "" : ", ") << *it;
        it++;
    }
    return os << " }";
}

template <typename T>
ostream &operator<<(ostream &os, const set<T> &s) {
    os << "{ ";
    auto itr = s.begin();
    while (itr != s.end()) {
        os << (itr == s.begin() ? "" : ", ") << *itr;
        itr++;
    }
    return os << " }";
}

template <typename T>
ostream &operator<<(ostream &os, const multiset<T> &ms) {
    os << "{ ";
    auto itr = ms.begin();
    while (itr != ms.end()) {
        os << (itr == ms.begin() ? "" : ", ") << *itr;
        itr++;
    }
    return os << " }";
}

template <typename T>
ostream &operator<<(ostream &os, const priority_queue<T> &q) {
    os << "{ ";
    auto p = q;
    while (!p.empty()) {
        os << p.top() << ((int)p.size() == 1 ? "" : ", ");
        p.pop();
    }
    return os << " }";
}

template <typename T>
ostream &operator<<(ostream &os,
                    const priority_queue<T, vector<T>, greater<T>> &q) {
    os << "{ ";
    auto p = q;
    while (!p.empty()) {
        os << p.top() << ((int)p.size() == 1 ? "" : ", ");
        p.pop();
    }
    return os << " }";
}

template <typename T>
ostream &operator<<(ostream &os, const queue<T> &q) {
    os << "{ ";
    auto p = q;
    while (!p.empty()) {
        os << p.front() << ((int)p.size() == 1 ? "" : ", ");
        p.pop();
    }
    return os << " }";
}

template <typename T, size_t... index>
void printTuple(ostream &os, const T &tp, index_sequence<index...>, size_t n) {
    using swallow = vector<int>;
    (void)swallow{ (os << get<index>(tp) << (index == n - 1 ? "" : ", "),
                    0)... };
}

template <typename T>
void forTuple(ostream &os, const T &tp) {
    constexpr size_t n = tuple_size_v<T>;
    printTuple(os, tp, make_index_sequence<n>{}, n);
}

template <typename... T>
ostream &operator<<(ostream &os, const tuple<T...> &tp) {
    os << "{ ";
    forTuple(os, tp);
    return os << " }";
}

ostream &operator<<(ostream &os, const __uint128_t &x) {
    __uint128_t tmp = x;
    if (tmp == 0) return os << 0;
    vector<int> ret;
    while (tmp) {
        ret.emplace_back(tmp % 10);
        tmp /= 10;
    }
    reverse(ret.begin(), ret.end());
    for (auto &&i : ret)
        os << i;
    return os;
}

void print() {
    cout << '\n';
}

template <class T>
void print(const T &a) {
    cout << a << '\n';
}

template <class T, class... Ts>
void print(const T &a, const Ts &...b) {
    // cout << a; (cout << ... << (cout << ' ', b));
    // cout << '\n';
    {
        cout << a << ' ';
        print(b...);
    }
}

// other
void initIo() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
}

template <typename T>
bool chmax(T &a, const T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template <typename T>
bool chmin(T &a, const T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template <typename T>
vector<tuple<T>> zip(vector<T> &v) {
    vector<tuple<T>> vt(v.size());
    for (size_t i = 0; i < v.size(); i++)
        vt[i] = make_tuple(v[i]);
    return vt;
}

template <typename T, typename... Ts>
auto zip(vector<T> &v, Ts &&...vs) {
    auto vt = zip(v);
    auto vts = zip(vs...);
    size_t m = min(vt.size(), vts.size());
    auto te = decltype(vt)(1)[0];
    auto tse = decltype(vts)(1)[0];
    vector res(m, tuple_cat(te, tse));
    for (size_t i = 0; i < m; i++)
        res[i] = tuple_cat(vt[i], vts[i]);
    return res;
}

template <typename T>
T power(T n, ll k) {
    T res = 1;
    while (k) {
        if (k & 1) res *= n;
        n *= n;
        k >>= 1;
    }
    return res;
}

template <typename T>
T powerMod(T n, ll k, T mod) {
    T res = 1;
    while (k) {
        if (k & 1) res = res * n % mod;
        n = n * n % mod;
        k >>= 1;
    }
    return res;
}

vector<vector<int>> graph(int n, int m, bool directed = 0, int origin = 1) {
    vector<vector<int>> g(n);
    while (m--) {
        int u, v;
        cin >> u >> v;
        u -= origin, v -= origin;
        g[u].emplace_back(v);
        if (!directed) g[v].emplace_back(u);
    }
    return g;
}

auto weightedGraph(int n, int m, bool directed = 0, int origin = 1) {
    // struct Edge {
    //         int to; ll w;
    //         Edge(int to, ll w) : to(to), w(w) {}
    // };
    // vector<vector<Edge>> g(n);
    vector<vector<pair<int, long long>>> g(n);
    while (m--) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u -= origin, v -= origin;
        g[u].emplace_back(v, w);
        if (!directed) g[v].emplace_back(u, w);
    }
    return g;
}

template <int mod>
struct ModInt {
    ll x;
    constexpr ModInt(ll a = 0) noexcept
        : x(a >= 0 ? a % mod : (a % mod + mod)){};

    constexpr ModInt &operator+=(const ModInt &r) noexcept {
        x += r.x;
        if (x >= mod) x -= mod;
        return *this;
    }

    constexpr ModInt &operator-=(const ModInt &r) noexcept {
        x -= r.x;
        if (x < 0) x += mod;
        return *this;
    }

    constexpr ModInt &operator*=(const ModInt &r) noexcept {
        x = x * r.x % mod;
        return *this;
    }

    constexpr ModInt &operator/=(const ModInt &r) noexcept {
        return *this *= r.inverse();
    }

    constexpr ModInt operator+(const ModInt &r) const noexcept {
        return ModInt(*this) += r;
    }

    constexpr ModInt operator-(const ModInt &r) const noexcept {
        return ModInt(*this) -= r;
    }

    constexpr ModInt operator*(const ModInt &r) const noexcept {
        return ModInt(*this) *= r;
    }

    constexpr ModInt operator/(const ModInt &r) const noexcept {
        return ModInt(*this) /= r;
    }

    constexpr ModInt operator-() const noexcept {
        return ModInt(-x);
    };

    constexpr bool operator==(const ModInt &r) const noexcept {
        return x == r.x;
    }

    constexpr bool operator!=(const ModInt &r) const noexcept {
        return x != r.x;
    }

    constexpr ModInt &operator++() noexcept {
        (*this) += 1;
        return *this;
    }

    constexpr ModInt &operator--() noexcept {
        (*this) -= 1;
        return *this;
    }

    constexpr ModInt operator++(int) noexcept {
        ModInt tmp(*this);
        ++(*this);
        return tmp;
    }

    constexpr ModInt operator--(int) noexcept {
        ModInt tmp(*this);
        --(*this);
        return tmp;
    }

    constexpr ModInt inverse() const noexcept {
        ll xx = 1, u = 0, s = x, t = mod;
        ll k;
        while (t) {
            k = s / t;
            swap(s -= k * t, t);
            swap(xx -= k * u, u);
        }
        return ModInt(xx);
    }

    constexpr ModInt power(ll k) const noexcept {
        ModInt res = 1, y = x;
        while (k) {
            if (k & 1) res *= y;
            y *= y;
            k >>= 1;
        }
        return res;
    }

    friend istream &operator>>(istream &is, ModInt &r) {
        ll s;
        is >> s;
        r = ModInt<mod>(s);
        return is;
    }

    friend ostream &operator<<(ostream &os, const ModInt &r) {
        return os << r.x;
    }
};

using mint1 = ModInt<mod1>;
using mint2 = ModInt<mod2>;
using mint3 = ModInt<mod3>;
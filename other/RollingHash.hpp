struct RollingHash {
   private:
    using ull = unsigned long long;
    static const ull mod61 = (1ull << 61) - 1;
    static ull base;
    vector<ull> hashed;
    vector<ull> power_table;
    int n;
    string s;

    // 基数に原始根をとる
    static ull get_base(ull r = 37, ull A = 127) {
        mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
        ull k = 2;
        while (gcd(k, mod61 - 1) != 1 || powerMod<ull>(r, k, mod61) <= A) {
            uniform_int_distribution<ull> dist(1, mod61 - 2);
            k = dist(mt);  // k < mod61 - 1
        }
        return powerMod<ull>(r, k, mod61);
    }

    ull mul(ull a, ull b) {
        __int128_t ret = (__int128_t)a * b;
        ret = (ret >> 61) + (ret & mod61);
        return ret < mod61 ? ret : ret - mod61;
    }

   public:
    RollingHash(string &s) : n(s.size()), s(s) {
        hashed.resize(n + 1);
        power_table.resize(n + 1);
        power_table[0] = 1;
        for (int i = 0; i < n; i++) {
            hashed[i + 1] = mul(hashed[i], base) + s[i];
            if (hashed[i + 1] >= mod61) hashed[i + 1] -= mod61;
            power_table[i + 1] = mul(power_table[i], base);
        }
    }

    ull hash() {
        return hashed.back();
    }

    // [l, r) (0-based)
    ull hash(int l, int r) {
        ull ret = mod61 + hashed[r] - mul(hashed[l], power_table[r - l]);
        return ret < mod61 ? ret : ret - mod61;
    }

    // lcp of [i, n) and [j, n)
    int lcp(int i, int j) {
        int ok = 0, ng = n - max(i, j) + 1;
        while (abs(ok - ng) > 1) {
            int mid = (ok + ng) / 2;
            if (hash(i, i + mid) == hash(j, j + mid)) ok = mid;
            else ng = mid;
        }
        return ok;
    }

    // s[i, n) < t[j, n)
    bool operator()(int i, int j) {
        int k = lcp(i, j);
        return (i + k < n && j + k < n) ? (s[i + k] < s[j + k]) : (i > j);
    }
};

RollingHash::ull RollingHash::base = RollingHash::get_base();

// O(N(logN)^2)
vector<int> suffixArray(string &s) {
    vector<int> ret(s.size() + 1);
    RollingHash rh(s);
    iota(ret.begin(), ret.end(), 0);
    sort(ret.begin(), ret.end(), rh);
    return ret;
}
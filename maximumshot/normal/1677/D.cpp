#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ui = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

const int inf = 1e9;
const ll inf64 = 1e18;

const int mod = 998'244'353;

int mul(int x, int y) {
    return (1ll * x * y) % mod;
}

struct output {
    int res;

    void print() {
        cout << res << "\n";
    }

    bool operator == (const output& o) const {
        throw;
    }
};

struct input {
    int n, k;
    vector<int> v;

    input() = default;

    void read() {
        cin >> n >> k;
        v.resize(n);
        for (auto& x : v)
            cin >> x;
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        vector<int> mx(n), mn(n);
        iota(mx.begin(), mx.end(), 0);
        for (int i = 0; i < n; i++) {
            if (v[i] > 0) {
                if (i + k >= n)
                    return output{0};
                mn[i + k] = mx[i + k] = v[i] + k;
            } else if (v[i] == 0) {
                if (i + k < n) {
                    mx[i + k] = min(mx[i + k], k);
                }
            }
        }
        int res = 1;
        for (int i = 0; i < n; i++) {
            if (mn[i] > mx[i]) return output{0};
            res = mul(res, mx[i] - mn[i] + 1);
        }
        return output{res};
    }

#ifdef DEBUG
    output slow() {
        return output();
    }
#endif
};

void test_case() {
    input in;
    in.read();
    output res = in.fast();
    res.print();
}

void work() {
    int t;
    cin >> t;
    while (t--)
        test_case();
}

#ifdef DEBUG
void test() {
    for (int t = 1;;t++) {
        input in;
        in.gen();
        input in_fs = in;
        input in_sl = in;
        output fs = in_fs.fast();
        output sl = in_sl.slow();
        if (fs == sl) {
            cout << "OK" << endl;
            fs.print();
            cout << "\n=========" << endl;
        } else {
            cout << "WA " << t << "\n";
            cout << "exp\n";
            sl.print();
            cout << "\n=========\n";
            cout << "fnd\n";
            fs.print();
            cout << "\n=========\n";
            in.print();
            break;
        }
    }
}
#endif

void max_test() {
    input in;
    in.gen_max_test();
    input in_fs = in;
    output fs = in_fs.fast();
    fs.print();
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();
//    test();
//    max_test();

    return 0;
}
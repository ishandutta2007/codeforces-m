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

struct output {
    vector<int> res;

    void print() {
        for (auto x : res)
            cout << x << " ";
        cout << "\n";
    }

    bool operator == (const output& o) const {
        throw;
    }
};

struct input {
    int n, m;
    string s;

    input() = default;

    void read() {
        cin >> n >> m >> s;
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        vector<int> res(n * m);
        int col = 0;
        vector<int> rem(m);
        for (int it = 0; it < n * m; it++) {
            if (s[it] == '1') {
                if (!rem[it % m]) {
                    rem[it % m] = 1;
                    col++;
                }
            }
            res[it] += col;
        }
        vector<int> S(n * m);
        for (int i = 0; i < n * m; i++) {
            S[i] = (i > 0 ? S[i - 1] : 0) + int(s[i] == '1');
        }
        for (int any = 0, r = 0; r < m; r++) {
            any |= s[r] == '1';
            for (int tot = 0, c = 0; c < n; c++) {
                if (c > 0) {
                    int ql = r + 1 + (c - 1) * m;
                    int qr = ql + m - 1;
                    int c1 = S[qr] - (ql > 0 ? S[ql - 1] : 0);
                    if (c1 > 0) tot++;
                }
                int it = r + c * m;
                res[it] += any + tot;
            }
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
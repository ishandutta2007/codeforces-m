//#pragma GCC optimize "tree-vectorize"
#pragma GCC target "movbe,mmx,sse,sse2,sse3,ssse3,sse4.1,sse4.2,popcnt,avx,avx2,aes,pclmul,fsgsbase,rdrnd,fma,bmi,bmi2,f16c,rdseed,clflushopt,xsavec,xsaves,adx,prfchw,lzcnt,abm"
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

bool online_judge =
                    #ifdef ONLINE_JUDGE
                    1;
                    #else
                    0;
                    #endif
struct { using X = int; template <typename T = X> T operator()() { T t; cin >> t; return t; } operator X() { return operator()(); } template <typename T> operator T() { return operator()<T>(); } string operator~() { return *this; } } $;
void print(const auto&... ts) { string sep = ""; ((cout << sep << ts, sep = " "), ...); cout << '\n'; }
void prints(const auto& c) { cout << c.end() - c.begin() << ' ' << c << '\n'; }
auto operator>>(istream& in, auto&& c) -> enable_if_t<!is_same_v<decay_t<decltype(c.begin(), c)>, string>, decltype(in)> { for (auto& i: c) in >> i; return in; }
auto operator<<(ostream& out, const auto& c) -> enable_if_t<!is_same_v<decay_t<decltype(c.begin(), c)>, string>, decltype(out)> { string sep = ""; for (auto i: c) out << sep << i, sep = " "; return out; }
template <typename It> struct range { It first, last; range() {} range(It first, It last) : first{first}, last{last} {} range(It first, auto n) : range{first, first + n} {} range(auto&& c) : range{c.begin(), c.end()} {} It begin() const { return first; } It end() const { return last; } int size() const { return last - first; } const auto& operator[](int i) const { return first[i]; } auto& operator[](int i) { return first[i]; } }; range(auto&& c) -> range<decltype(c.begin())>;
bool minb(auto& a, const auto& b) { return b < a? a = b, 1: 0; } auto& mini(auto& a, const auto& b) { return minb(a, b), a; } auto mind(auto& a, const auto& b) { auto t = a; return t - mini(a, b); }
bool maxb(auto& a, const auto& b) { return a < b? a = b, 1: 0; } auto& maxi(auto& a, const auto& b) { return maxb(a, b), a; } auto maxd(auto& a, const auto& b) { auto t = a; return maxi(a, b) - t; }
auto unz(auto a) { return max(a, {}); } int sgn(auto a) { return (a > 0) - (a < 0); } auto change(auto& a, const auto& b) { auto t = a; return (a = b) - t; }

constexpr int N = 1e5, S = 4 * N;

int t[S][2];

struct STOperation {
  using T = int;

  int l, r;
  T arg;

  T call(int i = 0, int L = 0, int R = N) {
    if (r <= L || R <= l) {
      return t[i][0] + t[i][1];
    }
    if (l <= L && R <= r) {
      t[i][1] += arg;
      return t[i][0] + t[i][1];
    }
    return (t[i][0] = min(call(2 * i + 1, L, (L + R) / 2), call(2 * i + 2, (L + R) / 2, R))) + t[i][1];
  }
};

int a[N];
vector<int> g[N];
int64_t s[N];

int main() {
  cin.tie(0)->sync_with_stdio(!online_judge);
  ios::sync_with_stdio(0);
  for (int testcase = $; testcase; --testcase) {
    int n = $, m = $;
    cin >> range{a, n};
    for (int i = 0; i < n; ++i) {
      STOperation{0, a[i], 1}.call();
    }
    string ans;
    for (int i = 0; i < m; ++i) {
      g[i].resize($);
      cin >> g[i];
      s[i] = accumulate(g[i].begin(), g[i].end(), 0ll);
      STOperation{0, (s[i] + g[i].size() - 1) / g[i].size(), -1}.call();
    }
    for (int i = 0; i < m; ++i) {
      STOperation{0, (s[i] + g[i].size() - 1) / g[i].size(), 1}.call();
      for (auto x: g[i]) {
        STOperation{0, (s[i] - x + g[i].size() - 2) / (g[i].size() - 1), -1}.call();
        ans += (t[0][0] + t[0][1] >= 0) + '0';
        STOperation{0, (s[i] - x + g[i].size() - 2) / (g[i].size() - 1), 1}.call();
      }
      STOperation{0, (s[i] + g[i].size() - 1) / g[i].size(), -1}.call();
    }
    for (int i = 0; i < m; ++i) {
      STOperation{0, (s[i] + g[i].size() - 1) / g[i].size(), 1}.call();
    }
    for (int i = 0; i < n; ++i) {
      STOperation{0, a[i], -1}.call();
    }
    print(ans);
  }
}
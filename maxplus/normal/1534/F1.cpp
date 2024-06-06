//#pragma GCC optimize "tree-vectorize"
#pragma GCC target "movbe,mmx,sse,sse2,sse3,ssse3,sse4.1,sse4.2,popcnt,avx,avx2,aes,pclmul,fsgsbase,rdrnd,fma,bmi,bmi2,f16c,rdseed,clflushopt,xsavec,xsaves,adx,prfchw,lzcnt,abm"
#include <iostream>
#include <vector>

using namespace std;

bool online_judge =
                    #ifdef ONLINE_JUDGE
                    1;
                    #else
                    0;
                    #endif
struct { using X = int; template <typename T = X> T operator()() { T t; cin >> t; return t; } operator X() { return operator()(); } template <typename T> operator T() { return operator()<T>(); } template <class T = string> T operator~() { return *this; } } $;
void print(const auto&... ts) { string sep = ""; ((cout << sep << ts, sep = " "), ...); cout << '\n'; }
void prints(const auto& c) { cout << c.end() - c.begin() << ' ' << c << '\n'; }
auto operator>>(istream& in, auto&& c) -> enable_if_t<!is_same_v<decay_t<decltype(c.begin(), c)>, string>, decltype(in)> { for (auto& i: c) in >> i; return in; }
auto operator<<(ostream& out, const auto& c) -> enable_if_t<!is_same_v<decay_t<decltype(c.begin(), c)>, string>, decltype(out)> { string sep = ""; for (auto i: c) out << sep << i, sep = " "; return out; }
template <typename It> struct range { It first, last; range() {} range(It first, It last) : first{first}, last{last} {} range(It first, auto n) : range{first, first + n} {} range(auto&& c) : range{c.begin(), c.end()} {} It begin() const { return first; } It end() const { return last; } int size() const { return last - first; } const auto& operator[](int i) const { return first[i]; } auto& operator[](int i) { return first[i]; } }; range(auto&& c) -> range<decltype(c.begin())>;
bool minb(auto& a, const auto& b) { return b < a? a = b, 1: 0; } auto& mini(auto& a, const auto& b) { return minb(a, b), a; } auto mind(auto& a, const auto& b) { auto t = a; return t - mini(a, b); }
bool maxb(auto& a, const auto& b) { return a < b? a = b, 1: 0; } auto& maxi(auto& a, const auto& b) { return maxb(a, b), a; } auto maxd(auto& a, const auto& b) { auto t = a; return maxi(a, b) - t; }
auto unz(auto a) { return max(a, {}); } int sgn(auto a) { return (a > 0) - (a < 0); } auto change(auto& a, const auto& b) { auto t = a; return (a = b) - t; }

constexpr int N = 4e5;
string s[N];
int n, m;
vector<int> from[N], to[N];
vector<int> ts;
bool vis[N];

void topsort(int v) {
  if (!change(vis[v], 1)) {
    return;
  }
  for (auto u: to[v]) {
    topsort(u);
  }
  ts.push_back(v);
}

bool drop(int v) {
  if (!change(vis[v], 0)) {
    return 0;
  }
  for (auto u: to[v]) {
    drop(u);
  }
  return 1;
}

int main() {
  cin.tie(0)->sync_with_stdio(!online_judge);
  ios::sync_with_stdio(0);
  n = $, m = $;
  cin >> range{s, n};
  for (int j = 0; j < m; ++j)
  for (int i = 0; i < n; ++i) if (s[i][j] == '#')
  for (int k = i; k < n; ++k) {
    if (j && s[k][j - 1] == '#') {
      from[k * m + j - 1].push_back(i * m + j);
      to[i * m + j].push_back(k * m + j - 1);
    }
    if (j != m - 1 && s[k][j + 1] == '#') {
      from[k * m + j + 1].push_back(i * m + j);
      to[i * m + j].push_back(k * m + j + 1);
    }
    if (k != i && s[k][j] == '#') {
      from[k * m + j].push_back(i * m + j);
      to[i * m + j].push_back(k * m + j);
      if (k == i + 1) {
        to[k * m + j].push_back(i * m + j);
        from[i * m + j].push_back(k * m + j);
      }
      break;
    }
  }
  for (int j = 0; j < m; ++j)
  for (int i = 0; i < n; ++i) if (s[i][j] == '#') {
    topsort(i * m + j);
  }
  int ans = 0;
  for (auto v: range{ts.rbegin(), ts.rend()}) {
    ans += drop(v);
  }
  print(ans);
}
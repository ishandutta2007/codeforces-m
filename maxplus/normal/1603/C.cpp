#include <algorithm>
#include <iostream>

using namespace std;

bool online_judge =
                    #ifdef ONLINE_JUDGE
                    1;
                    #else
                    0;
                    #endif
struct { using X = int; template <typename T = X> T operator()() { T t; cin >> t; return t; } operator X() { return operator()(); } template <typename T> operator T() { return operator()<T>(); } } $;
void print(const auto&... ts) { string sep = ""; ((cout << sep << ts, sep = " "), ...); cout << '\n'; }
auto print(const auto& c) -> decltype(c.begin(), void()) { cout << c.end() - c.begin() << ' ' << c << '\n'; }
auto operator>>(istream& in, auto&& c) -> enable_if_t<!is_same_v<decay_t<decltype(c)>, string>, decltype(c.begin(), in)> { for (auto& i: c) in >> i; return in; }
auto operator<<(ostream& out, const auto& c) -> enable_if_t<!is_same_v<decay_t<decltype(c)>, string>, decltype(c.begin(), out)> { string sep = ""; for (auto i: c) out << sep << i, sep = " "; return out; }
template <typename It> struct range { It first, last; range(It first, It last) : first{first}, last{last} {} range(It first, auto n) : range{first, first + n} {} range(auto&& c) : range{c.begin(), c.end()} {} It begin() const { return first; } It end() const { return last; } int size() const { return last - first; } }; range(auto&& c) -> range<decltype(c.begin())>;
bool minb(auto& a, const auto& b) { return b < a? a = b, 1: 0; } auto& mini(auto& a, const auto& b) { return minb(a, b), a; } auto mind(auto& a, const auto& b) { auto t = a; return t - mini(a, b); }
bool maxb(auto& a, const auto& b) { return a < b? a = b, 1: 0; } auto& maxi(auto& a, const auto& b) { return maxb(a, b), a; } auto maxd(auto& a, const auto& b) { auto t = a; return maxi(a, b) - t; }
auto unz(auto a) { return max(a, {}); } auto change(auto& a, const auto& b) { auto t = a; return (a = b) - t; }

template <typename Tag = int, typename Val = int> struct TaggedValue {
  Val val; Tag tag; constexpr TaggedValue(const Val& val = {}, const Tag& tag = {}) : val{val}, tag{tag} { } constexpr bool operator==(const TaggedValue& oth) const { return val == oth.val; } constexpr bool operator<(const TaggedValue& oth) const { return val < oth.val; } }; using Tagged = TaggedValue<>;

constexpr int N = 1e5, mod = 998244353;

int a[N];

Tagged b[N];

int main() {
  cin.tie(0)->sync_with_stdio(!online_judge);
  ios::sync_with_stdio(0);
  for (int testcase = $; testcase; --testcase) {
    int n = $, cnt = 0;
    int64_t ans = 0;
    cin >> range{a, n};
    for (int i = n - 1; i > -1; --i) {
      for (auto& [v, t]: range{b, cnt}) {
        int am = ((a[i] + v - 1) / v);
        v = a[i] / am;
        int prv = &v == &b->val? n: *prev(&v);
        (ans += (am - 1ll) * (prv - t) % mod * (i + 1)) %= mod;
      }
      b[cnt++] = {a[i], i};
      reverse(b, b + cnt);
      cnt = unique(b, b + cnt) - b;
      reverse(b, b + cnt);
    }
    print(ans);
  }
}
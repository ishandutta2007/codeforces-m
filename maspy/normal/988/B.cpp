#line 1 "main.cpp"
#include <bits/stdc++.h>
#line 3 "/home/maspy/library/my_template.hpp"

using namespace std;

using ll = long long;
#define int ll
using pi = pair<int, int>;
using vi = vector<int>;

#define FOR(i, n) for (int i = 0; (i) < (int)(n); ++(i))
#define FOR3(i, m, n) for (int i = (m); (i) < (int)(n); ++(i))
#define FOR_R(i, n) for (int i = (int)(n)-1; (i) >= 0; --(i))
#define FOR3_R(i, m, n) for (int i = (int)(n)-1; (i) >= (int)(m); --(i))
#define all(x) x.begin(), x.end()

#define eb emplace_back
#define mp make_pair
#define mt make_tuple

template <typename T>
void print(T x) {
  cout << x << "\n";
}

template <typename A, typename B>
void print(A x, B y, string sep = " ") {
  cout << x << sep << y << "\n";
}

template <typename A, typename B, typename C>
void print(A x, B y, C z, string sep = " ") {
  cout << x << sep << y << sep << z << "\n";
}

template <typename T>
void print_seq(T begin, T end, string sep = " ") {
  if (begin != end) {
    cout << *(begin++);
    for (auto it = begin; it != end; it++) {
      cout << sep << (*it);
    }
  }
  cout << "\n";
}

template <typename T>
void print_all(T A, string sep = " ") {
  print_seq(all(A), sep);
}

template <typename T>
vector<T> cumsum(vector<T> A) {
  ll N = A.size();
  vector<T> B(N + 1);
  B[0] = T(0);
  FOR(i, N) { B[i + 1] = B[i] + A[i]; }
  return B;
}

ll read() {
  ll i;
  cin >> i;
  return i;
}

pi read2() {
  ll a, b;
  cin >> a >> b;
  return {a, b};
}

tuple<ll, ll, ll> read3() {
  ll a, b, c;
  cin >> a >> b >> c;
  return {a, b, c};
}

vi read_vec(int n, int off = 0) {
  vi A(n);
  for (auto&& x : A) {
    cin >> x;
    x += off;
  }
  return A;
}

string read_str() {
  string s;
  cin >> s;
  return s;
}
#line 3 "main.cpp"

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll N = read();
  vector<string> S(N);
  FOR(i, N) { S[i] = read_str(); }

  sort(all(S), [](string x, string y) { return x.size() < y.size(); });

  bool ok = true;

  FOR(i, N - 1) {
    string x = S[i];
    string y = S[i + 1];
    auto it = y.find(x);
    if (it == string::npos) ok = false;
  }
  if (ok) {
    print("YES");
    print_all(S, "\n");
  } else
    print("NO");
  return 0;
}
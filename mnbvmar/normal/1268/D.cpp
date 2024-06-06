//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
//~ #pragma GCC optimize("Ofast")
//~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//~ #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define st first
#define nd second

using namespace __gnu_pbds;
using namespace std;
 
template <typename T>
using ordered_set =
	tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
	*this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
 
#define shandom_ruffle random_shuffle
 
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;

const int kMaxN = 2048;

bitset<kMaxN> adj[kMaxN];
bitset<kMaxN> rev_adj[kMaxN];

bitset<kMaxN> remain;
int n;
int fst_stack;

void DfsStraight(int v) {
	debug() << imie(v) << imie(adj[v][2]);
	remain[v] = false;
	while (true) {
		const int s = (remain & adj[v])._Find_first();
		if (s >= n) { break; }
		DfsStraight(s);
	}
	fst_stack = v;
}

void DfsRev(int v) {
	remain[v] = false;
	while (true) {
		const int s = (remain & rev_adj[v])._Find_first();
		if (s >= n) { break; }
		DfsRev(s);
	}
}

bool IsSingleCompo() {
	remain.set();
	fst_stack = -1;
	for (int i = 0; i < n; ++i) {
		if (remain[i]) {
			DfsStraight(i);
		}
	}
	assert(fst_stack != -1);
	debug() << imie(fst_stack);
	remain.set();
	DfsRev(fst_stack);
	return ((int)remain._Find_first() >= n);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);

	cin >> n;

	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < n; ++j) {
			adj[i][j] = (s[j] == '1');
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			rev_adj[i][j] = adj[j][i];
		}
	}

	if (IsSingleCompo()) {
		cout << "0 1\n";
		return 0;
	}

	auto Flip = [&](int v) {
		for (int i = 0; i < n; ++i) {
			if (i == v) { continue; }
			adj[v][i] = !adj[v][i];
			adj[i][v] = !adj[i][v];
			rev_adj[v][i] = !rev_adj[v][i];
			rev_adj[i][v] = !rev_adj[i][v];
		}
	};

	int cnt_one = 0;
	for (int v = 0; v < n; ++v) {
		Flip(v);
		cnt_one += IsSingleCompo();
		Flip(v);
	}

	if (cnt_one) {
		cout << "1 " << cnt_one << "\n";
		return 0;
	}

	assert(n <= 30);
	int cnt_two = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			Flip(i); Flip(j);
			cnt_two += IsSingleCompo();
			Flip(i); Flip(j);
		}
	}
	if (cnt_two) {
		cout << "2 " << cnt_two << "\n";
		return 0;
	}
	cout << "-1\n";
}
#include <bits/stdc++.h>

#define ff	first
#define ss	second

#define templ	template <
#define tempr	>
#define typet	typename T
#define typeu	typename U
#define types	typename... Ts
#define tempt	templ typet tempr
#define tempu	templ typeu tempr
#define final	constexpr const

tempt struct range {
	T b, e;
	range(T _b, T _e): b(_b), e(_e) { }
	T begin() const { return b; }
	T end() const { return e; }
};
tempt range<T> make_range(T b, T e) { return range<T>(b, e); }

tempt struct is_cont {
	static final bool value = false;
};
tempt struct is_cont<range<T>> {
	static final bool value = true;
};
templ types tempr struct is_cont<std::vector<Ts...>> {
	static final bool value = true;
};

templ typet , typeu tempr std::ostream&
operator<<(std::ostream& os, const std::pair<T, U>& p) {
	return os << '<' << p.ff << ',' << p.ss << '>';
}

tempt std::enable_if_t<is_cont<T>::value, std::ostream>&
operator<<(std::ostream& os, const T& c) {
	if (c.begin() == c.end()) return os << "{}";
	auto iter = c.begin();
	os << '{' << *iter;
	while (++iter != c.end()) os << ',' << *iter;
	return os << '}';
}

void dbg() { std::cerr << std::endl; }
templ typet , types tempr void
dbg(T arg, Ts... args) { std::cerr << ' ' << arg; dbg(args...); }

#ifdef LOCAL
#define debug(...) std::cerr << "[ "#__VA_ARGS__" ] :", dbg(__VA_ARGS__)
#else
#define debug(...) 0
#endif

typedef unsigned int u32;
typedef unsigned long long u64;
typedef long long i64;
typedef std::pair<u32, u32> puu;
typedef std::vector<u32> vu;
typedef std::vector<u64> vul;
typedef std::vector<int> vi;
typedef std::vector<i64> vl;
typedef std::vector<vu> vvu;

template<typename T>
using heap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

#define lowbit(x)	((x) & -(x))
#define all(x)		x.begin(), x.end()
#define set_all(x, y)	std::memset(x, y, sizeof (x))
#define set_n(x, y, n)	std::memset(x, y, sizeof (decltype(*(x))) * (n))

#define md		((l + r) >> 1u)
#define ls		(i << 1u)
#define rs		(ls ^ 1u)
#define ll		l, md, ls
#define rr		md, r, rs

#define pcount		__builtin_popcount
#define pcount64	__builtin_popcountll
#define lcount		__builtin_clz
#define lcount64	__builtin_clzll
#define tcount		__builtin_ctz
#define tcount64	__builtin_ctzll

tempt T& Min(T& x, const T& y) { return x = std::min<T>(x, y); }
tempt T& Max(T& x, const T& y) { return x = std::max<T>(x, y); }

final u32 mod = 1000000007u;
u32 add(u32 x, u32 y) { return x + y < mod ? x + y : x + y - mod; }
u32 sub(u32 x, u32 y) { return x < y ? mod + x - y : x - y; }
u32 mul(u32 x, u32 y) { return (u64)x * y % mod; }
u32 fpow(u32 x, u32 y) {
	u32 z = 1;
	while (y) {
		if (y & 1) z = mul(z, x);
		x = mul(x, x);
		y >>= 1;
	}
	return z;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	u32 l, r;
	std::cin >> l >> r;
	std::vector<std::pair<puu, u32>> edges;
	auto link = [&] (u32 u, u32 v, u32 w) -> void { edges.emplace_back(puu(u, v), w); };
	u32 p = 1;
	if (--l) {
		r -= l;
		link(1, 2, l);
		p = 2;
	}
	u32 s = p;
	link(p, p + 1, 1);
	++p;
	u32 already = 1;
	while (already + already <= r) {
		link(s, p + 1, 1);
		link(p, p + 1, 1);
		for (u32 i = s + 1, j = 1; i != p; ++i, j <<= 1) {
			link(i, p + 1, already + j);
		}
		++p;
		already <<= 1;
	}
	if (already != r) {
		link(s, p + 1, 1);
		link(p, p + 1, 1);
		r -= ++already;
		for (u32 i = s + 1, j = 1; i != p; ++i, j <<= 1) if (r & j) {
			link(i, p + 1, already);
			already += j;
		}
		++p;
	}
	std::cout << "YES" << std::endl;
	std::cout << p << ' ' << edges.size() << std::endl;
	for (const auto& e : edges) std::cout << e.ff.ff << ' ' << e.ff.ss << ' ' << e.ss << std::endl;
	return 0;
}
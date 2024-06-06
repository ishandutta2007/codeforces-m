/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author majk
 */

#ifndef MAJK_LIB
#define MAJK_LIB

#include <vector>
#include <stack>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <iomanip>
#include <set>
#include <functional>
#include <fstream>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <string>
#include <sstream>
#include <queue>
#include <bitset>
using namespace std;

#define x first
#define y second
typedef std::pair<int,int> pii; typedef long long ll; typedef unsigned long long ull; typedef unsigned int ui; typedef pair<ui,ui> puu;

template <typename T, typename U> std::istream&operator>>(std::istream&i, pair<T,U>&p) {i >> p.x >> p.y; return i;}
template<typename T>std::istream&operator>>(std::istream&i,vector<T>&t) {for(auto&v:t){i>>v;}return i;}
template <typename T, typename U> std::ostream&operator<<(std::ostream&o, const pair<T,U>&p) {o << p.x << ' ' << p.y; return o;}
template<typename T>std::ostream&operator<<(std::ostream&o,const vector<T>&t) {if(t.empty())o<<'\n';for(size_t i=0;i<t.size();++i){o<<t[i]<<" \n"[i == t.size()-1];}return o;}
template<typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
template<typename T> using maxheap = priority_queue<T, vector<T>, less<T>>;
template <typename T> bool in(T a, T b, T c) { return a <= b && b < c; }
ui logceil(int x) { return 8*sizeof(int)-__builtin_clz(x); }

namespace std { template<typename T,typename U>struct hash<pair<T,U>>{hash<T>t;hash<U>u;size_t operator()(const pair<T,U>&p)const{return t(p.x)^(u(p.y)<<7);}}; }
template<typename T,typename F>T bsh(T l,T h,const F&f){T r=-1,m;while(l<=h){m=(l+h)/2;if(f(m)){l=m+1;r=m;}else{h=m-1;}}return r;}
template<typename F> double bshd(double l,double h,const F&f,double p=1e-9){ui r=3+(ui)log2((h-l)/p);while(r--){double m=(l+h)/2;if(f(m)){l=m;}else{h=m;}}return (l+h)/2;}
template<typename T,typename F>T bsl(T l,T h,const F&f){T r=-1,m;while(l<=h){m=(l+h)/2;if(f(m)){h=m-1;r=m;}else{l=m+1;}}return r;}
template<typename F> double bsld(double l,double h,const F&f,double p=1e-9){ui r=3+(ui)log2((h-l)/p);while(r--){double m=(l+h)/2;if(f(m)){h=m;}else{l=m;}}return (l+h)/2;}
template<typename T> T gcd(T a,T b) { if (a<b) swap(a,b); return b?gcd(b,a%b):a; }

template<typename T>class vector2:public vector<vector<T>>{public:vector2(){} vector2(size_t a,size_t b,T t=T()):vector<vector<T>>(a,vector<T>(b,t)){}};
template<typename T>class vector3:public vector<vector2<T>>{public:vector3(){} vector3(size_t a,size_t b,size_t c,T t=T()):vector<vector2<T>>(a,vector2<T>(b,c,t)){}};
template<typename T>class vector4:public vector<vector3<T>>{public:vector4(){} vector4(size_t a,size_t b,size_t c,size_t d,T t=T()):vector<vector3<T>>(a,vector3<T>(b,c,d,t)){}};
template<typename T>class vector5:public vector<vector4<T>>{public:vector5(){} vector5(size_t a,size_t b,size_t c,size_t d,size_t e,T t=T()):vector<vector4<T>>(a,vector4<T>(b,c,d,e,t)){}};


#endif


template <typename T> struct bounded_priority_queue {
	inline bounded_priority_queue(ui X) : A(X), B(0), s(0) {}
	inline void push(ui L, T V) { B = max(B, L); A[L].push(V); ++s; }
	inline const T &top() const { return A[B].front(); }
	inline void pop() { --s; A[B].pop(); while (B > 0 && A[B].empty()) --B; }
	inline bool empty() const { return A[B].empty(); }
	inline void clear() { s = B = 0; for (auto &a: A) a = queue<T>(); }
	inline ui size() const { return s; }
private:
	vector<queue<T>> A; ui B; int s;
};

struct 	UnionFind {
	UnionFind(size_t N) : P(N, -1), comp(N) {}
	int find(int x) { while (P[x]>=0){x = P[x];}return x; }
	bool united(int x, int y) { return find(x) == find(y); }
	bool unite(int x, int y) { x=find(x);y=find(y);if(x==y){return false;}--comp;if(P[x]>P[y]){swap(x,y);}P[x]+=P[y];P[y]=x;return true;}
	vector<int> P;
	size_t comp;
};

/** Product of two 64-bit numbers modulo another. */
ull mulull(ull a, ull z, ull mod) {
#ifdef __SIZEOF_INT128__
	__int128 result = ((__int128) a * (__int128) z) % (__int128) mod;
	return (ull) result;
#else
    // schrage method
	ull q = mod / a, r = mod % a;
	ull rzq = (r < q) ? r * (z/q) : mulull(r, z/q, mod);
	ull azq = a * (z % q);
	if (azq >= rzq) return azq-rzq; else return azq-rzq+mod;
#endif
}

/** Multiply two 64-bit unsigned integers to get a 128-bit unsigned integer (as a pair of ull) */
pair<ull,ull> mulull(ull a, ull b) {
#ifdef __SIZEOF_INT128__
	__int128 result = (__int128) a * (__int128) b;
	return {(ull) (result >> 64), (ull) result};
#else
	ull c = (ui)a, d = a>>32, e = (ui)b, f = b>>32, g = d*f, h = d*e, i = f*c, j = c*e, k = (j>>32)+(ui)h+(ui)i, l = g+(h>>32)+(i>>32)+(k>>32);
	return {l, ((h+i) << 32) + j};
#endif
}

bool fractionGreaterOrEqual(ll a, ll b, ll c, ll d) {
	if (b < 0) { b = -b; a = -a; }
	if (d < 0) { d = -d; c = -c; }
	return a < 0 && c < 0 ? mulull(-a, d) <= mulull(-c, b) : (a >= 0) && (c < 0 || mulull(a, d) >= mulull(c, b));
}

bool fractionGreaterOrEqual(pair<ll, ll> a, pair<ll, ll> b) {
	return fractionGreaterOrEqual(a.x, a.y, b.x, b.y);
}


bool fractionGreaterOrEqual(double a, double b, double c, double d) {
	return a/b >= c/d;
}

// this is based on modulus, but it's 2-3 times slower than the former
//bool fractionGreaterOrEqual(ll a, ll b, ll c, ll d) {
//	if (a<0 && c<0) return greaterOrEqual(-c,d,-a,b);
//	if (a<0) return false;
//	if (c<0) return true;
//	if (b==0) return true;
//	if (d==0) return false;
//	ll ab = a/b, cd = c/d;
//	if (ab > cd) return true;
//	if (ab < cd) return false;
//	return !greaterOrEqual(b, a%b, d, c%d);
//}


/** Computing lower and upper envelope. Useful for "convex hull trick". */
namespace Envelope {
	template<typename T>
	struct Line {
		T m, b; int id;
		mutable function<const Line<T> *()> succ;

		bool operator<(const Line &rhs) const {
			if (rhs.b != numeric_limits<T>::min()) return m < rhs.m;
			const Line *s = succ();
			if (!s) return 0;
			return b - s->b < (s->m - m) * rhs.m;
		}
	};

	template<typename T>
	struct Upper : public multiset<Envelope::Line<T>> {
		using parent = multiset<Line<T>>;

		bool bad(typename parent::iterator y) {
			auto z = next(y);
			if (y == parent::begin()) {
				return z != parent::end() && y->m == z->m && y->b <= z->b;
			} else {
				auto x = prev(y);
				if (z == parent::end()) {
					return y->m == x->m && y->b <= x->b;
				} else {
					return fractionGreaterOrEqual(x->b - y->b, y->m - x->m, y->b - z->b, z->m - y->m);
				}
			}
		}

		void insert_line(T m, T b, int i = 0) {
			auto y = parent::insert({m, b, i});
			y->succ = [=] { return next(y) == parent::end() ? 0 : &*next(y); };
			if (bad(y)) { parent::erase(y); return; }
			while (next(y) != parent::end() && bad(next(y))) parent::erase(next(y));
			while (y != parent::begin() && bad(prev(y))) parent::erase(prev(y));
		}

		T operator[](T x) const {
			auto l = parent::lower_bound({x, numeric_limits<T>::min()});
			return l == parent::end() ? numeric_limits<T>::min() : l->m * x + l->b;
		}

		int best(T x) const {
			auto l = parent::lower_bound({x, numeric_limits<T>::min()});
			return l == parent::end() ? -1 : l->id;
		}
	};

	// Lower envelope. WARNING: the internal representation changes m & b.
	template<typename T>
	struct Lower : public Upper<T> {
		void insert_line(T m, T b, int i = 0) { Upper<T>::insert_line(-m, -b, i); }
		T operator[](T x) const { return -Upper<T>::operator[](x); }
	};
}

/* UpperEnvelope that with O(N) build and amortized O(1) query.
 * The updates need be sorted by (m,b), the queries need to be sorted by x, and
 * updates need to come before queries. */
namespace LinearEnvelope {
	template<typename T> struct Line { T m, b; int id; };

	template <typename T>
	struct Upper : public vector<Line<T>> {
		using parent = vector<Line<T>>;
		using parent::at; using parent::back; using parent::size;

		T t; int i;

		Upper() : t(0), i(0) {}

		void insert_line(T m, T b, int i = 0) {
			assert(t == 0);
			while (size() > 0 && ((back().b < b) || (back().b == b && back().m < m))) parent::pop_back();
			while (size() >= 2 && fractionGreaterOrEqual(at(size()-2).b - back().b, back().m - at(size()-2).m, back().b - b, m - back().m)) parent::pop_back();
			parent::push_back({m,b,i});
		}

		pair<T,int> advance(T x) {
			assert(x >= 0);
			t += x;
			while (i+1 < size() && at(i).m * t + at(i).b < at(i+1).m * t + at(i+1).b) ++i;
			return {at(i).m * t + at(i).b, at(i).id};
		}
	};};

class limakandsquaregrid {
public:
    void solve(istream& cin, ostream& cout) {
        int K, N; cin >> N >> K;
        if (K == N) {
            cout << K*K << endl;
            return;
        }

        vector<string> S(N); cin >> S;
        UnionFind UF(N*N);
        for (int r = 0; r < N; ++r) {
            for (int c = 0; c < N; ++c) {
                if (S[r][c] == 'X') continue;
                for (int dr = -1; dr <= 1; ++dr) {
                    for (int dc = -1; dc <= 1; ++dc) {
                        if (dr*dc==0 && dr+dc!=0) {
                            int rr = r+dr, cc = c+dc;
                            if (in(0,rr,N) && in(0,cc,N) && S[rr][cc] == '.') {
                                UF.unite(r*N + c, rr*N + cc);
                            }
                        }
                    }
                }
            }
        }

        vector2<int> P(N+1,N+1,0), R(N+1,N+1,0), W(N,N);
        for (int r = 0; r < N; ++r) {
            for (int c = 0; c < N; ++c) {
                P[r+1][c+1] = P[r+1][c] + P[r][c+1] - P[r][c] + (S[r][c] == '.');
                R[r+1][c+1] = R[r+1][c] + R[r][c+1] - R[r][c] + (S[r][c] == '.'?max(0,-UF.P[r*N+c]) : 0);
                W[r][c] = UF.find(r*N+c);
            }
        }

        int tot = 0;
        vector<int> L(N*N, -1);
        int k = 0;
        for (int t = 0; t + K <= N; ++t) {
            for (int l = 0; l + K <= N; ++l) {
                int origins = R[t+K][l+K] - R[t+K][l] - R[t][l+K] + R[t][l];
                int inner = P[t+K][l+K] - P[t+K][l] - P[t][l+K] + P[t][l];
                int ans = K*K + origins - inner;

                vector<int> Z;
                if (t != 0) for (int c = l; c < l + K; ++c) if (S[t-1][c] == '.' && L[W[t-1][c]] < k) { L[W[t-1][c]] = k; Z.push_back(W[t-1][c]); }
                if (t+K != N) for (int c = l; c < l + K; ++c) if (S[t+K][c] == '.' && L[W[t+K][c]] < k) { L[W[t+K][c]] = k; Z.push_back(W[t+K][c]); }
                if (l != 0) for (int r = t; r < t + K; ++r) if (S[r][l-1] == '.' && L[W[r][l-1]] < k) { L[W[r][l-1]] = k; Z.push_back(W[r][l-1]); }
                if (l+K != N) for (int r = t; r < t + K; ++r) if (S[r][l+K] == '.' && L[W[r][l+K]] < k) { L[W[r][l+K]] = k; Z.push_back(W[r][l+K]); }

                for (int z:Z) {
                    int size = -UF.P[z], r = z/N, c = z%N;
                    bool inside = in(t,r,t+K) && in(l,c,l+K);
                    if (!inside) ans += size;
                }

                int cur = ans;
                tot = max(tot, cur);
                ++k;
            }
        }

        cout << tot << endl;

    }
};


int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	limakandsquaregrid solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
    return 0;
}
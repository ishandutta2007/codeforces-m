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
#ifndef MOD_H
#define MOD_H



template <unsigned int N> class Field {
    typedef unsigned int ui;
    typedef unsigned long long ull;
	inline ui pow(ui a, ui p){ui r=1,e=a;while(p){if(p&1){r=((ull)r*e)%N;}e=((ull)e*e)%N;p>>=1;}return r;}
	/*extended GCD(slow):ll t=0,nt=1,r=N,nr=a;while(nr){ll q=r/nr;t-=q*nt;swap(t,nt);r-=q*nr;swap(r,nr);}assert(r<=1);return(t<0)?t+N:t;*/
	inline ui inv(ui a){return pow(a,N-2);}
public:
    inline Field(int x = 0) : v(x) {}
	inline Field<N> pow(int p){return (*this)^p; }
	inline Field<N> operator^(int p){return {(int)pow(v,(ui)p)};}
    inline Field<N>&operator+=(const Field<N>&o) {if ((ll)v+o.v >= N) v += o.v - N; else v += o.v; return *this; }
    inline Field<N>&operator-=(const Field<N>&o) {if (v<o.v) v -= o.v-N; else v-=o.v; return *this; }
    inline Field<N>&operator*=(const Field<N>&o) {v=(ull)v*o.v % N; return *this; }
    inline Field<N>&operator/=(const Field<N>&o) { return *this*=inv(o.v); }
    inline Field<N> operator+(const Field<N>&o) const {Field<N>r{*this};return r+=o;}
    inline Field<N> operator-(const Field<N>&o) const {Field<N>r{*this};return r-=o;}
    inline Field<N> operator*(const Field<N>&o) const {Field<N>r{*this};return r*=o;}
    inline Field<N> operator/(const Field<N>&o) const {Field<N>r{*this};return r/=o;}
    inline Field<N> operator-() {if(v) return {(int)(N-v)}; else return {0};};
    inline Field<N>& operator++() { ++v; if (v==N) v=0; return *this; }
    inline Field<N> operator++(int) { Field<N>r{*this}; ++*this; return r; }
    inline Field<N>& operator--() { --v; if (v==-1) v=N-1; return *this; }
    inline Field<N> operator--(int) { Field<N>r{*this}; --*this; return r; }
    inline bool operator==(const Field<N>&o) const { return o.v==v; }
	inline bool operator!=(const Field<N>&o) const { return o.v!=v; }
	inline explicit operator ui() const { return v; }
	inline static vector<Field<N>>fact(int t){vector<Field<N>>F(t+1,1);for(int i=2;i<=t;++i){F[i]=F[i-1]*i;}return F;}
	inline static vector<Field<N>>invfact(int t){vector<Field<N>>F(t+1,1);Field<N> X{1};for(int i=2;i<=t;++i){X=X*i;}F[t]=1/X;for(int i=t-1;i>=2;--i){F[i]=F[i+1]*(i+1);}return F;}
private: ui v;
};
template<unsigned int N>istream &operator>>(std::istream&is,Field<N>&f){unsigned int v;is>>v;f=v;return is;}
template<unsigned int N>ostream &operator<<(std::ostream&os,const Field<N>&f){return os<<(unsigned int)f;}
template<unsigned int N>Field<N> operator+(int i,const Field<N>&f){return Field<N>(i)+f;}
template<unsigned int N>Field<N> operator-(int i,const Field<N>&f){return Field<N>(i)-f;}
template<unsigned int N>Field<N> operator*(int i,const Field<N>&f){return Field<N>(i)*f;}
template<unsigned int N>Field<N> operator/(int i,const Field<N>&f){return Field<N>(i)/f;}


typedef Field<1000000007> FieldMod;

struct Ring {
	static int div(int p, int q, int N) {
		ll t=0,nt=1,r=N,nr=q;
		while(nr){ ll q=r/nr;t-=q*nt;r-=q*nr;swap(t,nt);swap(r,nr); }
		t=(t<0)?t+N:t;
		r=(r<0)?r+N:r;
		if (gcd(p,N)%r) { return 0; }
		return (int)(((ll)t*(ll)p/r)%N);
	}
};
#endif


#include <type_traits>

// ordinary suffix array with optional LCP and LCP RMQ. look elsewhere
template<typename Index, bool PrecomputeLCP = false, bool PrecomputeRMQ = false>
class SuffixArray {
public:
	static_assert(PrecomputeLCP || !PrecomputeRMQ, "Must have RMQ for LCP");

	template<typename T>
	explicit SuffixArray(T t):N(t.size()), S(N), I(N), LCP(PrecomputeLCP ? N : 0) {
		typedef typename std::remove_reference<decltype(t[0])>::type Item;
		vector<pair<Item, Index>> TR(N);
		for (Index i = 0; i < N; ++i) { TR[i] = {t[i], i}; }
		sort(TR.begin(), TR.end());
		vector<Index> R(N);
		Index r = R[TR[0].y] = S[TR[0].y] = 0;
		for (Index i = 1; i < N; ++i) {
			R[TR[i].y] = r += (TR[i - 1].x != TR[i].x);
			S[TR[i].y] = i;
		}
		vector<Index> RA(N), SA(N), C(N);
		for (Index k = 1; k < N; k <<= 1) {
			counting_sort(R, C, SA, k);
			counting_sort(R, C, SA, 0);
			RA[S[0]] = r = 0;
			for (Index i = 1; i < N; ++i) {
				RA[S[i]] = r += (R[S[i]] != R[S[i - 1]] || S[i] + k >= N || S[i - 1] + k >= N ||
								R[S[i] + k] != R[S[i - 1] + k]);
			}
			swap(RA, R);
			if (R[S[N - 1]] == N - 1)break;
		}
		for (Index i = 0; i < N; ++i) { I[S[i]] = i; }
		if (PrecomputeLCP) {
			Index k = 0;
			for (Index i = 0; i < N; ++i) {
				if (I[i] == N - 1) {
					LCP[I[i]] = k = 0;
					continue;
				}
				while (i + k < N && S[I[i] + 1] + k < N && t[i + k] == t[S[I[i] + 1] + k]) { ++k; }
				LCP[I[i]] = k;
				if (k > 0) { --k; }
			}
		}
		if (PrecomputeRMQ) {
			RMQ.push_back(LCP);
			for (int p = 0; (1 << p) < N; ++p) {
				RMQ.push_back(RMQ[p]);
				for (int i = 0; i < N - (1 << p); ++i) { RMQ[p + 1][i] = min(RMQ[p + 1][i], RMQ[p][i + (1 << p)]); }
			}
		}
	}

	Index next(Index i) { return (I[i] == N - 1) ? -1 : S[I[i] + 1]; }

	template<typename=std::enable_if<PrecomputeLCP>>
	Index lcp(Index i) const { return LCP[I[i]]; }

	template<typename=std::enable_if<PrecomputeRMQ>>
	Index lcp(Index i, Index j) const {
		i = I[i];
		j = I[j];
		if (i > j) { swap(i, j); }
		if (i == j - 1)return LCP[i];
		Index p = 0;
		while ((1 << p) < j - i) { ++p; }
		--p;
		return min(RMQ[p][i], RMQ[p][j - (1 << p)]);
	}

	inline void counting_sort(const vector<int> &R, vector<int> &C, vector<int> &SA, int k) {
		Index i;
		fill(C.begin(), C.end(), 0);
		for (i = 0; i < N; i++) { C[i + k < N ? R[i + k] : 0]++; }
		for (Index sum = i = 0; i < N; i++) { C[i] = (sum += C[i], sum - C[i]); }
		for (i = 0; i < N; i++) { SA[C[S[i] + k < N ? R[S[i] + k] : 0]++] = S[i]; }
		swap(SA, S);
	}

	Index N;
	vector<Index> S, I, LCP;
	vector<vector<Index>> RMQ;
};

class tavasandmalekas {
public:
    void solve(istream& cin, ostream& cout) {
        int N, M; cin >> N >> M;
        string P; cin >> P;
        int R = P.size();
        P += '$';
        SuffixArray<int, true, true> SA(P);
        int rep = N;
        for (int i = 1; i < R; ++i) {
            if (SA.lcp(0, i) == R-i) {
                rep = i;
                break;
            }
        }

        vector<bool> occurs(N, false);
        for (int i = 0; i < M; ++i) {
            int q; cin >> q; occurs[q-1] = true;
        }

        int p = 0;
        for (int i = 0; i < N;) {
            if (occurs[i]) {
                for (int j = i; j < min(N, i+R); j++) {
                    if (occurs[j]) {
                        if ((j-i)%rep == 0) {
                            i = j;
                        } else {
                            cout << "0\n";
                            return;
                        }
                    }
                }

                i += R;
            } else {
                ++p;
                ++i;
            }
        }

        cout << FieldMod{26}.pow(p) << '\n';
    }
};


int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	tavasandmalekas solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
    return 0;
}
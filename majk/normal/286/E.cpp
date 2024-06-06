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
#include <array>
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
ui logceil(ll x) { return x?8*sizeof(ll)-__builtin_clzll(x):0; }

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
    inline Field<N>&operator+=(const Field<N>&o) {if (v+o.v >= N) v += o.v - N; else v += o.v; return *this; }
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
	template <typename T>
	static T div(T p, T q, T N) {
		T t=0,nt=1,r=N,nr=q;
		while(nr!=0){ T q=r/nr;t-=q*nt;r-=q*nr;swap(t,nt);swap(r,nr); }
		t=(t<0)?t+N:t;
		r=(r<0)?r+N:r;
		if (gcd(p,N)%r!=0) { return 0; }
		return (t*p/r)%N;
	}
};
#endif




template <ui P> struct Group {};
template <> struct Group<4194304001u> { constexpr static ui bits = 25, root = 199, rootInverse = 758768563u; };
template <> struct Group<998244353u> { constexpr static ui bits = 23, root = 31, rootInverse = 128805723; };
template <> struct Group<104857601u> { constexpr static ui bits = 22, root = 21, rootInverse = 49932191; };
template <> struct Group<924844033u> { constexpr static ui bits = 21, root = 3597, rootInverse = 508059997; };

template <ui Prime> class FFT {
public:
	typedef Field<Prime> F;

	FFT() {
		OMEGA[Group<Prime>::bits] = Group<Prime>::root;
		OMEGA_INV[Group<Prime>::bits] = Group<Prime>::rootInverse;
		for (size_t i = Group<Prime>::bits; i > 0; --i) {
			OMEGA[i-1] = ui((ull(OMEGA[i])*ull(OMEGA[i]))%Prime);
			OMEGA_INV[i-1] = ui((ull(OMEGA_INV[i])*ull(OMEGA_INV[i]))%Prime);
		}
	}

	void fft(std::vector<F> &V, bool inverse = false) {
		int P = 1;
		while ((1u << P) < V.size()) ++P;
		V.resize(1u << P);
		fft(V, P, inverse);
	}

	void fft(std::vector<F> &V, const int P, bool inverse = false) {
		if (P == 0) return;
		//if (P > Group<Prime>::bits) throw std::runtime_error("Number of bits in FFT too large");
		//if (V.size() != (1 << P)) throw std::runtime_error("Vector has wrong size");
		for (int i = 1, j = 0; i < (1 << P); ++i) {
			int bit = (1 << (P - 1));
			for (; j >= bit; bit >>= 1) j -= bit;
			j += bit;
			if (i < j) std::swap(V[i], V[j]);
		}

		for (int B = 1; B <= P; ++B) {
			F omega = inverse ? OMEGA_INV[B] : OMEGA[B];
			for (int i = 0; i < (1 << P); i += (1 << B)) {
				F x = 1;
				for (int j = 0; j < (1 << (B - 1)); j++) {
					F u = V[i + j], v = V[i + j + (1 << (B - 1))] * x;
					V[i + j] = u + v;
					V[i + j + (1 << (B - 1))] = u - v;
					x *= omega;
				}
			}
		}

		if (inverse) {
			F q = 1 / F(1 << P);
			for (F &v:V) v *= q;
		}
	}

private:
	std::array<ui, Group<Prime>::bits+1> OMEGA, OMEGA_INV;
};

#include <numeric>

typedef Field<998244353> FF;

class ELadiesShop {
public:
    void solve(istream& cin, ostream& cout) {
        int N, M; cin >> N >> M;
        vector<int> A(N); cin >> A;

        vector<int> C(M+1);
        vector<FF> B(2*M+1, 0);
        for (int a: A) B[a] = C[a] = 1;
        FFT<998244353> fft;
        fft.fft(B);
        for (int i = 0; i < B.size(); ++i) B[i] *= B[i];
        fft.fft(B, true);
        vector<int> Answer;
        for (int i = 1; i <= M; ++i) {
            if (B[i] != 0 && C[i] == 0) {
                cout << "NO\n";
                return;
            }

            if (B[i] == 0 && C[i] != 0) {
                Answer.push_back(i);
            }
        }
        cout << "YES\n" << Answer.size() << '\n' << Answer;
    }
};


int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	ELadiesShop solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
    return 0;
}
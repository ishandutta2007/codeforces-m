/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author
 */

#ifndef MAJK_LIB
#define MAJK_LIB

#include <vector>
#include <stack>
#include <iostream>
#include <unordered_map>
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
constexpr int MOD = 1000000007;

typedef std::pair<int,int> pii;
typedef long long ll;
typedef unsigned int ui;

template <typename T, typename U> std::istream&operator>>(std::istream&i, pair<T,U>&p) {i >> p.x >> p.y; return i;}
template<typename T>std::istream&operator>>(std::istream&i,vector<T>&t) {for(auto&v:t){i>>v;}return i;}
template<typename T>std::ostream&operator<<(std::ostream&o,const vector<T>&t) {for(size_t i=0;i<t.size();++i){o<<t[i]<<" \n"[i == t.size()-1];}return o;}
template<typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
template<typename T> using maxheap = priority_queue<T, vector<T>, less<T>>;
auto fraclt = [](const pii&a,const pii&b) { return (ll)a.x * b.y < (ll)b.x * a.y; };
struct cmpfrac { bool operator()(const pii&a,const pii&b)const { return (ll)a.x * b.y < (ll)b.x * a.y; }};
template <typename T> bool in(T a, T b, T c) { return a <= b && b < c; }
int logceil(ll x) {int b=0;while(x){x>>=1;++b;}return b;}

namespace std {
    template<typename T,typename U>struct hash<pair<T,U>>{hash<T>t;hash<U>u;size_t operator()(const pair<T,U>&p)const{return t(p.x)^(u(p.y)<<7);}};
}
template<typename T,typename F>T bsh(T l,T h,const F&f){T r=-1,m;while(l<=h){m=(l+h)/2;if(f(m)){l=m+1;r=m;}else{h=m-1;}}return r;}
template<typename T,typename F>T bsl(T l,T h,const F&f){T r=-1,m;while(l<=h){m=(l+h)/2;if(f(m)){h=m-1;r=m;}else{l=m+1;}}return r;}
template<typename T> T gcd(T a,T b) { if (a<b) swap(a,b); return b?gcd(b,a%b):a; }

template<typename T>class vector2:public vector<vector<T>>{public:vector2(){} vector2(size_t a,size_t b,T t=T()):vector<vector<T>>(a,vector<T>(b,t)){}};
template<typename T>class vector3:public vector<vector<vector<T>>>{public:vector3(){} vector3(size_t a,size_t b,size_t c,T t=T()):vector<vector<vector<T>>>(a,vector<vector<T>>(b,vector<T>(c,t))){}};
template <typename T> struct bounded_priority_queue {
	inline bounded_priority_queue(ui X) : A(X), B(0) {}
	inline void push(ui L, T V) { B = max(B, L); A[L].push(V); }
	inline const T &top() const { return A[B].front(); }
	inline void pop() { A[B].pop(); while (B > 0 && A[B].empty()) --B; }
	inline bool empty() const { return A[B].empty(); }
	inline void clear() { B = 0; for (auto &a: A) a = queue<T>(); }
private:
	vector<queue<T>> A; ui B;
};


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
    inline Field<N>&operator+=(const Field<N>&o) {if ((ll)v+o.v >= N) v = (ll)v+o.v-N; else v = v+o.v; return *this; }
    inline Field<N>&operator-=(const Field<N>&o) {if (v<o.v) v = N-o.v+v; else v=v-o.v; return *this; }
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
	inline static vector<Field<N>>invfact(int t){vector<Field<N>>F(t+1,1);for(int i=2;i<=t;++i){F[i]=F[i-1]/i;}return F;}
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


class TaskB {
public:
	int N;
	vector<FieldMod> A;

	FieldMod brute(bool m, const vector<FieldMod>&X) {
		if (X.size()==1) return X[0];

		vector<FieldMod> Y(X.size()-1);
		for (int i = 0; i < Y.size(); ++i) {
			Y[i] = X[i];
			if (m) Y[i]+= X[i+1]; else Y[i]-=X[i+1];
			m = !m;
		}

		return brute(m, Y);
	}

    void solve(istream& cin, ostream& cout) {
		cin >> N;

		A.resize(N);
		cin >> A;

//		if (N < 1000) { cout << brute(true, A); return; }

		auto F = FieldMod::fact(N);
		auto I = FieldMod::invfact(N);

		vector<FieldMod> M(N, 0);


		switch (N % 4) {
			case 0:
				for (int i = 0; i < N; ++i) {
					M[i] = F[N / 2 - 1] * I[N / 2 - 1 - i / 2] * I[i / 2];
					if (i % 2) M[i] = -M[i];
				}
				break;
			case 1:
				for (int i = 0; i < N; ++i) {
					if (i % 2) M[i] = 0; else M[i] = F[N / 2] * I[N / 2 - i / 2] * I[i / 2];
				}
				break;
			case 2:
				for (int i = 0; i < N; ++i) {
					M[i] = F[N / 2 - 1] * I[N / 2 - 1 - i / 2] * I[i / 2];
				}
				break;
			case 3:
				for (int i = 1; i < N; i+=2) {
					M[i] = 2 * F[N / 2 - 1] * I[N / 2 - 1 - i / 2] * I[i / 2];
				}
				for (int i = 0; i < N-2; i+=2) {
					M[i] += F[N / 2 - 1] * I[N / 2 - 1 - i / 2] * I[i / 2];
					M[i+2] -= F[N / 2 - 1] * I[N / 2 - 1 - i / 2] * I[i / 2];
				}
				break;
		}

		FieldMod ans = 0;
		for (int i = 0; i < N; ++i) {
			ans += M[i] * A[i];
		}
		cout << ans << endl;
//
//		cerr << N << ": ";
//		for (int i = 0; i < N; ++i) {
//
//			A = vector<FieldMod>(N, 0);
//			A[i] = 1;
//			cerr << brute(true, A) - M[i] << ' ';
//		}
//		cerr << endl;


//		cout << brute(true, A) << endl;
    }
};


int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	TaskB solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}
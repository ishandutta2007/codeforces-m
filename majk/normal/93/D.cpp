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

#ifndef MAJK_MATRIX
#define MAJK_MATRIX


template <typename T> class Matrix {
public:
	Matrix(size_t R, size_t C, T t=T(0)) : R(R), C(C), A(R,vector<T>(C,t)), def(t) {}
	Matrix(const vector<vector<T>> &a, T t=T(0)) : R(a.size()), C(a[0].size()), A(a), def(t) {}
	Matrix(const initializer_list<vector<T>> &a, T t=T(0)) : R(a.size()), C(a.begin()->size()), A(a), def(t) {}
	size_t rows() const { return R; }
	size_t columns() const { return C; }
	bool isSquare() const { return R*C; }
	bool isIdentity() const {
		for (int i = 0; i < min(R,C); ++i) {
			for (int j = 0; j < min(R,C); ++j) {
				if (i == j && A[i][j] != 1) return false;
				if (i != j && A[i][j] != 0) return false;
			}
		}
		return true;
	}

	void addColumnsRight(size_t add, T t=T()) {
		for (int i = 0; i < R; ++i) {
			A[i].resize(C + add);
			for (size_t j = C; j < C+add; ++j) A[i][j] = t;
		}
		C += add;
	}

	void removeColumnsLeft(size_t rem) {
		for (size_t i = 0; i < R; ++i) A[i].erase(A[i].begin(), rem > A[i].size() ? A[i].end() : A[i].begin()+rem);
	}

	T determinant() const {
		if (!isSquare()) { throw std::runtime_error("Cannot compute determinant of a rectangular matrix"); }
		Matrix<T> tmp(*this);
		T ans = tmp.toReducedRowEchelon();
		if (tmp.isIdentity()) return ans;
		else return 0;
	}

	vector<T> solveFor(const vector<T> &b) {
		if (!isSquare()) { throw std::runtime_error("Cannot solve a rectangular matrix"); }
		if (b.size() != R) throw new std::runtime_error("Unable to solve linear equation, dimensions do not match");
		Matrix<T> tmp(*this);
		for (int i = 0; i < R; ++i) tmp.A[i].push_back(b[i]);
		++tmp.C;
		tmp.toReducedRowEchelon();
		if (!tmp.isIdentity()) throw std::runtime_error("Cannot solve a singular matrix");
		vector<T> Ans(R);
		for (int j = 0; j < R; ++j) Ans[j] = tmp.A[j].back();
		return Ans;
	}

	Matrix<T> power(ull N) {
		if (!isSquare()) { throw std::runtime_error("Cannot compute determinant of a rectangular matrix"); }

		Matrix<T> ans(R, R, 0), pow = *this;
		for (ui r = 0; r < R; ++r) ans[r][r] = 1;
		while (N) {
			if (N&1) ans = ans * pow;
			N >>= 1;
			pow = pow * pow;
		}
		return ans;
	}

	Matrix<T> & operator+=(const Matrix<T>&m) {
		if (R != m.R) throw std::runtime_error("Cannot add matrices of different height");
		if (C != m.C) throw std::runtime_error("Cannot add matrices of different width");
		for (int i = 0; i < R; ++i) {
			for (int j = 0; j < C; ++j) {
				A[i][j] += m.A[i][j];
			}
		}
		return *this;
	}

	Matrix<T> & operator-=(const Matrix<T>&m) {
		if (R != m.R) throw std::runtime_error("Cannot substract matrices of different height");
		if (C != m.C) throw std::runtime_error("Cannot substract matrices of different width");
		for (int i = 0; i < R; ++i) {
			for (int j = 0; j < C; ++j) {
				A[i][j] -= m.A[i][j];
			}
		}
		return *this;
	}

	Matrix<T> operator*(const Matrix<T>&m) const {
		if (C != m.R) throw std::runtime_error("Matrices incompatible for multiplication");
		Matrix<T> Ans(R, m.C, T(0));
		for (int i = 0; i < R; ++i) {
			for (int j = 0; j < m.C; ++j) {
				for (int k = 0; k < C; ++k) {
					Ans[i][j] += A[i][k] * m.A[k][j];
				}
			}
		}
		return Ans;
	}

	vector<T> operator*(const vector<T>&m) const {
		if (C != m.size()) throw std::runtime_error("Matric and vector incompatible for multiplication");
		vector<T> ans(R, def);
		for (ui r = 0; r < R; ++r) {
			for (ui c = 0; c < C; ++c) {
				ans[r] += m[c]* (*this)[r][c];
			}
		}
		return ans;
	}

	class Row {
	public:
		Row(Matrix<T>*M, size_t row) : M(M), row(row) {}
		T &operator[](size_t col) {
			if (col < 0 || col >= M->C) throw std::out_of_range("Invalid column ID");
			return M->A[row][col];
		}
		const T &operator[](size_t col) const {
			if (col < 0 || col >= M->C) throw std::out_of_range("Invalid column ID");
			return M->A[row][col];
		}
	private:
		Matrix<T> *M; size_t row;
	};

	Row operator[](size_t row) {
		if (row < 0 || row >= R) throw std::out_of_range("Invalid row ID");
		return Row(this, row);
	}

	const Row operator[](size_t row) const {
		if (row < 0 || row >= R) throw std::out_of_range("Invalid row ID");
		return Row(const_cast<Matrix<T>*>(this), row);
	}

	Matrix<T> transposed() const {
		Matrix<T> M(*this);
		M.transpose();
		return M;
	}

	Matrix<T> inverted() const {
		if (R != C) throw std::runtime_error("Matrix not square");
		Matrix<T> M(*this);
		M.invert();
		return M;
	}

	Matrix<T> &transpose() {
		A.resize(max(R,C));
		for (size_t i = 0; i < C; ++i) A[i].resize(max(R,C));
		for (size_t i = 0; i < R; ++i) {
			for (size_t j = i+1; j < C; ++j) swap(A[i][j], A[j][i]);
		}
		for (size_t i = 0; i < C; ++i) A[i].resize(R);
		A.resize(C);
		return *this;
	}

	Matrix<T> &invert() {
		addColumnsRight(C, def);
		for (size_t i = 0; i < R; ++i) A[i][R + i] = 1;
		toReducedRowEchelon();
		if (!isIdentity()) throw std::runtime_error("Matrix not invertible");
		removeColumnsLeft(C/2);
		return *this;
	}


private:
	T toReducedRowEchelon() {
		size_t pivot = 0;
		T factor = 1;
		for (size_t i = 0; i < C && pivot < R; ++i) {
			pair<T, size_t> Q = {A[pivot][i], pivot};
			for (size_t j = pivot+1; j < R; ++j) if (A[j][i] != 0) Q = {A[j][i], j};
			if (Q.x == 0) continue;
			if (Q.y != i) swap(A[Q.y], A[pivot]);
			for (size_t j = i+1; j < C; ++j) A[pivot][j] /= A[pivot][i];
			factor /= A[pivot][i];
			A[pivot][i] = 1;

			for (size_t j = 0; j < R; ++j) {
				if (j != pivot) {
					for (size_t k = i + 1; k < C; ++k) A[j][k] -= A[pivot][k] * A[j][i];
					A[j][i] = 0;
				}
			}

			++pivot;
		}
		return factor;
	}

	size_t R, C;
	vector<vector<T>> A;
	T def;
};

template<typename T>std::ostream &operator<<(std::ostream&os,const Matrix<T>&m) {
	for (size_t r = 0; r < m.rows(); ++r) for (size_t c = 0; c < m.columns(); ++c) os << m[r][c] << " \n"[c == m.columns()-1];
	return os;
}

#endif

class Flags {
public:

    FieldMod count(int v, Matrix<FieldMod> M) {
        if (v == 0) return 0;
        auto N = M.power(v-1);
        vector<FieldMod> Z(17,1);
        Z[16] = 4;
        Z = N*Z;
        return Z[16];
    }

void solve(istream& cin, ostream& cout) {
    Matrix<FieldMod> M(17,17,0);
    for (int j = 0; j < 16; ++j) {
        bool ok = false;
        for (int i = 0; i < 16; ++i) {
            int a = i/4, b = i%4, c = j/4, d = j%4;
            if (b == c && c != d && a != b && (a&2) != (b&2) && (c&2) != (d&2) && (b || a == d)) {
                M[i][j] = 1;
                M[16][j] = 1;
            }
        }
        M[16][16] = 1;
    }

    int L, R; cin >> L >> R;
    FieldMod ans = count(R, M) - count(L-1, M) + count((R+1)/2, M) - count(L/2, M);
    cout << ans/2 << endl;

}
};


int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	Flags solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
    return 0;
}
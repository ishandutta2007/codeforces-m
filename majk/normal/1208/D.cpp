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
#include <algorithm>
#include <numeric>
#include <cassert>
#include <cmath>
#include <string>
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
template<typename T> struct Fenwick {
    explicit Fenwick(ui N=0, T t=T()):N(1u<<logceil(N)),F(this->N,t),t(t){}
    explicit Fenwick(const vector<T>&A, T t=T()):N(1u<<logceil(A.size())),F(A),t(t){
        F.resize(N); fill(F.begin()+A.size(),F.end(),t);
        for(int i=0;i<N;i++){int j=i+lsb(i+1);if(j<N)F[j]+=F[i];}}
    void add(int i, T v){while(i<=N){F[i]+=v;i+=lsb(i+1);}}
    T sum(int i)const{T sum(t);while(i){sum+=F[i-1];i-=lsb(i);}return sum;}
    T range(int i,int j)const{j++; T s(t);while(j>i){s+=F[j-1];j-=lsb(j);}while(i>j){s-=F[i-1];i-=lsb(i);}return s;}
    T get(int i)const{return range(i,i);}
    void set(int i, T v) {add(i, v-get(i)); }
    constexpr int lsb(int i)const{return i&-i;}
    ui N;vector<T> F;T t;
    int max_lower(T v) {
        if (F[0] >= v) return -1;
        if (F[N-1] < v) return N-1;

        int x = 0; T a = t;
        for (int s = N>>1; s > 0; s >>= 1) if (a+F[x+s-1]<v) { a += F[x+s-1]; x += s; }
        return x;
    }
};

template<typename T> struct Fenwick2 {
    explicit Fenwick2(ui N=0, T t=T()):N(1u<<logceil(N)),F(this->N,this->N,t),t(t){}
//    explicit Fenwick2(const vector<vector<T>>&A, T t=T()):N(1u<<logceil(A.size())),F(A),t(t){
//            F.resize(N);
//            for (int i=0;i<A.size();++i) { F[i].resize(N); fill(F[i].begin()+A.size(),F[i].end(),t); }
//            for (int i=A.size();i<N;++i) { F[i].resize(N); fill(F[i].begin(),F[i].end(),t); }
//
////            for(int i=0;i<N;i++){int j=i+lsb(i+1);if(j<N)F[j]+=F[i];}
//    }
    void add(int x, int y, T v){
        while(x<=N){ int z = y; while(z<=N) { F[x][z] += v; z += lsb(z+1); }x +=lsb(x+1); }
    }

    T sum(int x, int y) {
        T sum(t);
        while (x <= N) { int z = y;while (z <= N) { sum += F[x][z];z -= lsb(z + 1); }x -= lsb(x + 1); }
        return sum;
    }
    T range(int x1, int y1, int x2, int y2) {
        T ans = sum(x2, y2);
        if (x1) ans -= sum(x1-1, y2);
        if (y1) ans -= sum(x2, y1-1);
        if (x1 && y1) ans += sum(x1-1,y1-1);
        return ans;
    }
    constexpr int lsb(int i)const{return i&-i;}
    ui N;vector2<T> F;T t;
};

class DRestorePermutation {
public:
    void solve(istream& cin, ostream& cout) {
        int N; cin >> N;
        vector<ll> S(N); cin >> S;
        vector<ll> Orig(N+1, 0);
        for (int i = 1; i <= N; ++i) Orig[i] = i;
        Fenwick<ll> F(Orig, 0);
        vector<int> Ans(N);
        for (int i = N-1; i >= 0; --i) {
            int j = F.max_lower(S[i]+1);
            Ans[i] = j;
            F.add(j, -j);
        }
        cout << Ans;
    }
};


int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	DRestorePermutation solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
    return 0;
}
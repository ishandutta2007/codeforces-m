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

class CStrangeSorting {
public:
    string S;
    void dsort(int a, int k, int d) {
        string T = S.substr(a,k);
        int j = 0;
        for (int i = 0; i < d; ++i) {
            for (int l = i; l < k; l += d) {
                S[a+j++] = T[l];
                cerr << l << ' ';
            }
        }
        cerr << endl;
    }

    vector<int> dsortperm(int N, int k, int d) {
        vector<int> Ans(N);
        int j = 0;
        for (int i = 0; i < d; ++i) {
            for (int l = i; l < k; l += d) {
                Ans[j++] = l;
            }
        }
        for (int i = k; i < N; ++i) Ans[i] = i;
        return Ans;
    }

    void apply(vector<int>&perm) {
        string T = S;
        for (int i = 0; i < S.size(); ++i) {
            S[i] = T[perm[i]];
        }
    }

    vector<int> rotperm(int N) {
        vector<int> Ans(N);
        for (int i = 0; i < N; ++i) {
            Ans[i] = (i+1)%N;
        }
        return Ans;
    }

    vector<int> mul(const vector<int> &A, const vector<int> &B) {
        vector<int> C(A.size());
        for (int i = 0; i < A.size(); ++i) {
            C[i] = A[B[i]];
        }
        return C;
    }

    vector<int> exp(vector<int> A, int P) {
        vector<int> R(A.size());
        for (int i = 0; i < A.size(); ++i) R[i] = i;
        while (P) {
            if (P&1) { R = mul(R,A); }
            P >>= 1;
            A = mul(A, A);
        }
        return R;
    }


    void solve(istream& cin, ostream& cout) {
        cin >> S;
        int N = S.size();
        vector<int> Rot = rotperm(N);
        int T; cin >> T;
        for (int i = 0; i < T; ++i) {
            int K, D; cin >> K >> D;
            vector<int> Perm = dsortperm(N, K, D);
            vector<int> Real = mul(Perm,Rot);
            vector<int> Pow = exp(Real, N-K+1);
            apply(Pow);
            rotate(S.begin(),S.begin()+K-1,S.end());
            cout << S << '\n';
        }
    }
};


int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	CStrangeSorting solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
    return 0;
}
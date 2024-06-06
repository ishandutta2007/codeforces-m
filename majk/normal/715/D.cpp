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
ui logceil(int x) { return x?8*sizeof(int)-__builtin_clz(x):0; }

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
// #include "../l/mod.h"

class TaskD {
public:
void solve(istream& cin, ostream& cout) {
    int Z = 50;
    ll L; cin >> L;


    ll P = 1;
    vector<pair<pii,pii>> Ans;
    for (int i = 0; i <= Z-6; i += 2) {
        int M = L % 6;
        L = L/6;
        P *= 6;

        Ans.push_back({{i+1,i+4},{i+1,i+5}});
        if (i != Z-6) Ans.push_back({{i+2,i+6},{i+2,i+7}});

        Ans.push_back({{i+4,i+1},{i+5,i+1}});
        if (i != Z-6) Ans.push_back({{i+6,i+2},{i+7,i+2}});

        if (M == 0 || M == 3) Ans.push_back({{i+1,i+3},{i+1,i+4}});
        if (M < 3) Ans.push_back({{i+2,i+3},{i+2,i+4}});
        Ans.push_back({{i+2,i+4},{i+3,i+4}});
        Ans.push_back({{i+2,i+5},{i+3,i+5}});

        if (M != 2 && M != 5) Ans.push_back({{i+3,i+1},{i+4,i+1}});
        Ans.push_back({{i+3,i+2},{i+4,i+2}});
        Ans.push_back({{i+4,i+2},{i+4,i+3}});
        Ans.push_back({{i+5,i+2},{i+5,i+3}});

    }

    if (L == 0) Ans.push_back({{Z-1,Z-3}, {Z,Z-3}});
    Ans.push_back({{Z-1,Z-2}, {Z,Z-2}});
    Ans.push_back({{Z-1,Z-1}, {Z,Z-1}});

    Ans.push_back({{Z-3,Z-1}, {Z-3,Z}});
    Ans.push_back({{Z-2,Z-1}, {Z-2,Z}});
    Ans.push_back({{Z-1,Z-1}, {Z-1,Z}});

    cout << "50 50\n";
    cout << Ans.size() << endl;
    for (auto ans: Ans) {
        cout << ans << endl;
    }

//    vector<string> C(2*Z, string(2*Z, ' '));
//    for (int i = 0; i < Z; ++i) {
//        for (int j = 0; j < Z; ++j) {
//            C[2*i+1][2*j+1] = '+';
//        }
//    }
//    for (auto a:Ans) {
//        C[a.x.x + a.y.x - 2][a.x.y + a.y.y - 2] = 'X';
//    }
//    for (string s: C) cout << s << endl;
//    cout << P << endl;
}
};


int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	TaskD solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
    return 0;
}
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
    int N, M; cin >> N >> M;
    vector<string> S(N); cin >> S;
    vector3<bool> A(4, N, M, false);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            switch (S[i][j]) {
                case '+': A[0][i][j] = A[1][i][j] = A[2][i][j] = A[3][i][j] = true; break;
                case 'L': A[1][i][j] = A[2][i][j] = A[3][i][j] = true; break;
                case 'U': A[0][i][j] = A[2][i][j] = A[3][i][j] = true; break;
                case 'R': A[0][i][j] = A[1][i][j] = A[3][i][j] = true; break;
                case 'D': A[0][i][j] = A[1][i][j] = A[2][i][j] = true; break;
                case '-': A[0][i][j] = A[2][i][j] = true; break;
                case '|': A[1][i][j] = A[3][i][j] = true; break;
                case '<': A[0][i][j] = true; break;
                case '^': A[1][i][j] = true; break;
                case '>': A[2][i][j] = true; break;
                case 'v': A[3][i][j] = true; break;
            }
        }
    }
    int XT, YT; cin >> XT >> YT; --XT; --YT;
    int XS, YS; cin >> XS >> YS; --XS; --YS;

    vector3<int> D(4, N, M, 1e9);
    vector<pair<int,pii>> H;
    H.push_back({0,{XT,YT}});
    D[0][XT][YT] = 0;

    for (int i = 0; i < H.size(); ++i) {
        auto h = H[i];
        int x = h.y.x, y = h.y.y, t = h.x, d = D[t][x][y];
        if (x > 0 && d + 1 < D[t][x-1][y] && A[(t+1)&3][x][y] && A[(t+3)&3][x-1][y]) {
            D[t][x-1][y] = d + 1;
            H.push_back({t, {x-1,y}});
        }
        if (x < N-1 && d + 1 < D[t][x+1][y] && A[(t+3)&3][x][y] && A[(t+1)&3][x+1][y]) {
            D[t][x+1][y] = d + 1;
            H.push_back({t, {x+1,y}});
        }
        if (y > 0 && d + 1 < D[t][x][y-1] && A[(t)&3][x][y] && A[(t+2)&3][x][y-1]) {
            D[t][x][y-1] = d + 1;
            H.push_back({t, {x,y-1}});
        }
        if (y < M-1 && d + 1 < D[t][x][y+1] && A[(t+2)&3][x][y] && A[(t)&3][x][y+1]) {
            D[t][x][y+1] = d + 1;
            H.push_back({t, {x,y+1}});
        }
        if (d + 1 < D[(t+3)&3][x][y]) {
            D[(t+3)&3][x][y] = d+1;
            H.push_back({(t+3)&3, {x,y}});
        }
    }

    int ans = 1e9;
    for (int i = 0; i < 4; ++i) {
        ans = min(ans, D[i][XS][YS]);
    }
    if (ans == 1e9) ans = -1;
    cout << ans << endl;
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
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

class TaskC {
public:

    vector<pair<int,pii>> Mem;

    int brute(int N, int c) {
        if (c == 0) return 0;
        if (Mem[c].x != -1) return Mem[c].x;
        Mem[c] = {10000, {0,0}};
        for (int x = 0; x < N; ++x) {
            for (int y = x+1; y < N; ++y) {
                int z = y + y - x;
                if (z < N) {
                    int d = c^(1<<x)^(1<<y)^(1<<z);
                    Mem[c] = min(Mem[c], {brute(N, d)+1, {x,y-x}});
                }
            }
        }
        return Mem[c].x;
    }

    int solve(int N, int c) {
        Mem.assign(1<<N, {-1,{-1,-1}});
        return brute(N, c);
    }

void solve(istream& cin, ostream& cout) {
        int N; cin >> N;
        vector<int> A(N);
        cin >> A;
        int i = 0;
        vector<pair<pii,int>> S;
        auto add = [&](int a, int b, int c) {
            A[a] ^= 1;
            A[b] ^= 1;
            A[c] ^= 1;
            S.push_back({{a,b},c});
        };
        while (N - i >= 12) {
            if (A[i] == 0) ++i;
            else if (A[i+1] == 0 && A[i+2] == 0) {
                add(i, i+3, i+6);
                i += 3;
            } else if (A[i+1] == 1 && A[i+2] == 1) {
                add(i, i+1, i+2);
                i += 3;
            } else if (A[i+1] == 0 && A[i+2] == 1) {
                add(i, i+2, i+4);
                i += 3;
            } else {
                vector<int> Z(20);
                bool found = false;
                for (int d = 2; d <= 5 && !found; ++d) {
                    for (int e = 1; e <= 5 && !found; ++e) {
                        for (int j = 0; j < 6; ++j) Z[j] = A[i+j];
                        Z[0] ^= 1;
                        Z[1] ^= 1;
                        Z[d] ^= 1;
                        Z[1+e] ^= 1;
                        Z[d+d] ^= 1;
                        Z[1+e+e] ^= 1;
                        bool ok = true;
                        for (int j = 0; j < 6; ++j) ok &= Z[j] == 0;
                        if (ok) {
                            found = true;
                            add(i, i+d, i+d+d);
                            add(i+1, i+e+1, i+e+e+1);
                        }
                    }
                }

//                for (int j = 0; j < 6; ++j) {
//                    if (A[j] == 1) {
//                        cout << "Fail " << j << endl;
//                    }
//                }
//
//                if (!found) {
//                    cout << "Error\n";
//                    return;
//                }
                assert(found);
                i += 6;
            }
        }

        int g = min(12, N);
        int h = 0;
        for (int i = 0; i < g; ++i) {
            h ^= (A[N-1-i]<<i);
        }

        if (solve(g, h) != 10000) {
            while (h != 0) {
                int i = Mem[h].y.x;
                int d = Mem[h].y.y;
                add(N-1-i-d-d, N-1-i-d, N-1-i);
                h ^= (1<<i);
                h ^= (1<<(i+d));
                h ^= (1<<(i+d+d));
            }

            cout << "YES\n";
            cout << S.size() << endl;
            for (auto s: S) {
                cout << (s.x.x+1) << ' ' << (s.x.y+1) << ' ' << (s.y+1) << '\n';
            }
        } else {
            cout << "NO\n";
        }





//    for (int j = 3; j <= 12; ++j) {
//        map<int,int> Q;
//        for (int k = 0; k < (1<<j); ++k) {
//            Q[solve(j, k)]++;
//        }
//
//        cerr << j << endl;
//        for (pii q:Q) {
//            cerr << q << ' ';
//        }
//        cerr << endl;
//    }
}
};


int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	TaskC solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
    return 0;
}
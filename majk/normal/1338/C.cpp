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
#include <fstream>
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

class CPerfectTriples {
public:
    vector<ll> solve(ll j) {
        ll lo = 0;
        ll pow4 = 1;
        ll left = j;
        int s = 0;
        while (left >= lo + pow4) {
            lo += pow4;
            pow4 *= 4;
            s++;
        }
        ll ss = j - lo;
        vector<int> D, E(s), F(s);
        for (int x = 0; x < s; ++x) {
            D.push_back(ss%4);
            ss /= 4;
        }
        for (int x = 0; x < s; ++x) {
            switch (D[x]) {
                case 0: E[x] = F[x] = 0; break;
                case 1: E[x] = 2; F[x] = 3; break;
                case 2: E[x] = 3; F[x] = 1; break;
                case 3: E[x] = 1; F[x] = 2; break;
            }
        }
        ll e = 0;
        ll f = 0;
        for (int x = 0; x < s; ++x) {
            e = 4*e + E[s-1-x];
            f = 4*f + F[s-1-x];
        }
        return {pow4 + j - lo,2*pow4 + e,3*pow4 + f};
    }

    void solve(istream& cin, ostream& cout) {
        int T; cin >> T;
        for (int t = 0; t < T; ++t) {
            ll N; cin >> N;
            N--;
            auto SS = solve(N/3);
            cout << SS[N%3] << '\n';
        }
//        int MX = 1023;
//        vector<bool> U(MX+1, true);
//        vector<int> Ans, Syn(300);
//        for (int j = 0; j < 100; ++j) {
//            // 0     2^0 + x - lo
//            // 1-4   2^2 + x - lo
//            // 5-20  2^4 + x - lo
//            // 21-84 2^6 + x - lo
//            // 85-.. 2^8 + x - lo
//            ll lo = 0;
//            ll pow4 = 1;
//            ll left = j;
//            int s = 0;
//            while (left >= lo + pow4) {
//                lo += pow4;
//                pow4 *= 4;
//                s++;
//            }
//            ll ss = j - lo;
//            vector<int> D, E(s), F(s);
//            for (int x = 0; x < s; ++x) {
//                D.push_back(ss%4);
//                ss /= 4;
//            }
//            for (int x = 0; x < s; ++x) {
//                switch (D[x]) {
//                    case 0: E[x] = F[x] = 0; break;
//                    case 1: E[x] = 2; F[x] = 3; break;
//                    case 2: E[x] = 3; F[x] = 1; break;
//                    case 3: E[x] = 1; F[x] = 2; break;
//                }
//            }
//            ll e = 0;
//            ll f = 0;
//            for (int x = 0; x < s; ++x) {
//                e = 4*e + E[s-1-x];
//                f = 4*f + F[s-1-x];
//            }
//            Syn[3*j] = pow4 + j - lo;
//            Syn[3*j+1] = 2*pow4 + e;
//            Syn[3*j+2] = 3*pow4 + f;
//        }
//        for (int i = 0; i < 100; ++i) {
//            bool found = false;
//            for (int a = 1; a <= MX && !found; ++a) {
//                if (!U[a]) continue;
//                for (int b = a+1; b <= MX && !found; ++b) {
//                    if (!U[b]) continue;
//                    int c = a^b;
//                    if (c > b && U[c]) {
//                        Ans.push_back(a);
//                        Ans.push_back(b);
//                        Ans.push_back(c);
//                        U[a] = U[b] = U[c] = false;
//                        found = true;
////                        cout << (2*a == b) << ' ';
//                    }
//                }
//            }
//        }
//        cout << endl;
//        for (int i = 0; i < Ans.size(); i += 3) {
//            cout << i/3 << ' ' << Ans[i]-Syn[i] << ' ' << Ans[i+1]-Syn[i+1] << ' ' << Ans[i+2]-Syn[i+2] << endl;
//        }
    }
};



int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	CPerfectTriples solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
    return 0;
}
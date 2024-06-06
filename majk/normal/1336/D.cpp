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

class DYuiAndMahjongSet {
public:
    void solve(istream& cin, ostream& cout) {
        int N; cin >> N;
        bool test = false;
        vector<int> X, O;
        if (N < 0) {
            test = true;
            N = -N;
            X.resize(N);
            cin >> X;
            O = X;
        }

        vector<int> Added(N, 0);
        auto query = [&](int x) {
            if (test) {
                if (x != -1) {
                    Added[x]++;
                    X[x]++;
                }
                int a = 0, b = 0;
                for (int i = 0; i < N; ++i) a += X[i]*(X[i]-1)*(X[i]-2)/6;
                for (int i = 0; i < N-2; ++i) b += X[i]*X[i+1]*X[i+2];
                return pii{a,b};
            } else {
                if (x != -1) {
                    Added[x]++;
                    cout << "+ " << x + 1 << endl;
                }
                int a, b;
                cin >> a >> b;
                return pii{a, b};
            }
        };
        pii a = query(-1);
        int begTriple = a.x;
        vector<int> Cnt(N, -1);
        vector<int> Tria(10000, -1);
        for (int i = 0; i < 105; ++i) {
            Tria[i*(i-1)/2] = i;
        }

        vector<int> Diff(N, -1);
        for (int i = 0; i < N-1; ++i) {
            pii b = query(i);
            Diff[i] = b.y - a.y;
            int diff = b.x - a.x;
            if (diff != 0) Cnt[i] = Tria[diff]-Added[i]+1;
            a = b;
        }


//        cout << begTriple << endl;
        for (int i = 0; i < N-1; ++i) {
            if (Cnt[i] != -1) {
                begTriple -= Cnt[i]*(Cnt[i]-1)*(Cnt[i]-2)/6;
            }
        }

//        cout << begTriple << endl;
        for (int j = 3; j <= 100; ++j) {
            if (j*(j-1)*(j-2)/6 == begTriple) {
                Cnt[N-1] = j;
            }
        }
//        cout << "CNT " << Cnt << endl;


        int maxSize = 1;
        vector<vector<int>> Opts{{}};
        for (int i = 0; i < N; ++i) {
            vector<vector<int>> NewOpts;
            auto check = [&](const vector<int>&O, int add) {
//                cout << "check " << O << ' ' << add << endl;
                if (i >= 2) {
                    // check diff for i-2
                    if (Diff[i-2] != -1) {
                        int exp = 0;
                        if (i >= 4) exp += (O[i - 4] + Added[i - 4]) * (O[i - 3] + Added[i - 3]);
                        if (i >= 3) exp += (O[i - 3] + Added[i - 3]) * (O[i - 1]);
                        exp += O[i - 1] * add;
//                    cout << exp << ' ' << add << ' ' << Diff[i] << endl;
                        if (exp != Diff[i - 2]) return;
                    }
                }

                NewOpts.push_back(O);
                NewOpts.back().push_back(add);
            };
            for (const auto &o: Opts) {
                if (Cnt[i] != -1) check(o, Cnt[i]);
                else {
                    check(o, 0);
                    check(o, 1);
                    if (i == N-1) check(o, 2);
                }
            }
            swap(Opts,NewOpts);
            maxSize = max(maxSize, int(Opts.size()));
//            cout << "Opts " << i << endl;
//            cout << Opts;
        }

        // check last constraint
        vector<vector<int>> NewOpts;
        for (const auto&O: Opts) {
            int exp1 = 0, exp2 = 0;
            exp1 += (O[N-3]+Added[N-3])*(O[N-2]+Added[N-2]);
            exp2 += (O[N-4]+Added[N-4])*(O[N-3]+Added[N-3]);
            exp2 += (O[N-3]+Added[N-3])*(O[N-1]);
            if (Diff[N-1] != -1 && exp1 != Diff[N-1]) continue;
            if (Diff[N-2] != -1 && exp2 != Diff[N-2]) continue;
            NewOpts.push_back(O);
        }

        pii e = query(0);
        Opts.clear();
        for (const auto&O: NewOpts) {
            if (a.x+(O[0]+Added[0]-1)*(O[0]+Added[0]-2)/2 != e.x) continue;
            if (a.y+(O[1]+Added[1])*(O[2]+Added[2]) != e.y) continue;
            Opts.push_back(O);
        }
        swap(Opts, NewOpts);

        auto answer = [&](const vector<int>&answer) {
            if (test) {
                if (NewOpts.size() > 1) {
                    cout << "FAIL TOO MANY OPTS " << NewOpts << '\n';
                }
                if (answer != O) {
                    cout << "FAIL\n" << answer << O;
                } else {
                    cout << "OK\n";
                }
                if (maxSize > 100) {
                    cout << "MAXSIZE" << maxSize << '\n';
                }
            } else {
                cout << "! " << answer << flush;
            }
        };

        answer(NewOpts.back());
    }
};



int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	DYuiAndMahjongSet solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
    return 0;
}
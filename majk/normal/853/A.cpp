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
typedef unsigned long long ull;
typedef unsigned int ui;

template <typename T, typename U> std::istream&operator>>(std::istream&i, pair<T,U>&p) {i >> p.x >> p.y; return i;}
template<typename T>std::istream&operator>>(std::istream&i,vector<T>&t) {for(auto&v:t){i>>v;}return i;}
template<typename T>std::ostream&operator<<(std::ostream&o,const vector<T>&t) {for(size_t i=0;i<t.size();++i){o<<t[i]<<" \n"[i == t.size()-1];}return o;}
template<typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
template<typename T> using maxheap = priority_queue<T, vector<T>, less<T>>;
auto fraclt = [](const pii&a,const pii&b) { return (ll)a.x * b.y < (ll)b.x * a.y; };
struct cmpfrac { bool operator()(const pii&a,const pii&b)const { return (ll)a.x * b.y < (ll)b.x * a.y; }};
template <typename T> bool in(T a, T b, T c) { return a <= b && b < c; }
ui logceil(ll x) {ui b=0;while(x){x>>=1;++b;}return b;}

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
// #include "../l/mod.h"

class TaskA {
public:
    void solve(istream& cin, ostream& cout) {
        int N,K; cin >> N >> K;
        vector<int> C(N); cin >> C;
        maxheap<pii> H;

        for (int i = 1; i <= K; ++i) {
            H.push({C[i-1], i});
        }

        vector<int> A(N);
        ll ans = 0;
        for (int i = K+1; i <= N+K; ++i) {
            if (i <= N) H.push({C[i-1], i});

            auto h = H.top(); H.pop();
            ans += ll(i - h.y)*h.x;
            A[h.y-1] = i;
        }
        cout << ans << endl << A;
    }
};


int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	TaskA solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
    return 0;
}
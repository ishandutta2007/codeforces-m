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
#ifndef UTIL_H
#define UTIL_H



template <typename T> struct bounded_priority_queue {
	inline bounded_priority_queue(ui X) : A(X), B(0), s(0) {}
	inline void push(ui L, T V) { B = max(B, L); A[L].push(V); ++s; }
	inline const T &top() const { return A[B].front(); }
	inline void pop() { --s; A[B].pop(); while (B > 0 && A[B].empty()) --B; }
	inline bool empty() const { return A[B].empty(); }
	inline void clear() { s = B = 0; for (auto &a: A) a = queue<T>(); }
	inline ui size() const { return s; }
private:
	vector<queue<T>> A; ui B; int s;
};

struct 	UnionFind {
	UnionFind(size_t N) : P(N, -1), comp(N) {}
	int find(int x) { while (P[x]> 0){x = P[x]-1;}return x; }
	bool united(int x, int y) { return find(x) == find(y); }
	bool unite(int x, int y) { x=find(x);y=find(y);if(x==y){return false;}--comp;if(P[x]>P[y]){swap(x,y);}P[x]+=P[y];P[y]= x+1;return true;}
	inline ui size(int u) { return -P[find(u)]; }
	vector<int> P;
	size_t comp;
};



#endif


// PUSH RELABEL MAX-FLOW
template<class T>
struct Edge {
	ui u, v; T c, f; ui i;
	inline bool hasResidual() const { return c > f; }
};

template<class T>
struct PushRelabel {
	ui V;
	vector<Edge<T>> E;
	vector<T> excess;
	vector<ui> level,levelCount,LastEdge,PrevEdge;
	vector<bool> active;
	bounded_priority_queue<ui> Q;

	PushRelabel(ui n) : V(n), excess(n), level(n), levelCount(n+1), active(n), Q(n), LastEdge(n, ui(-1)) {}

	void AddEdge(ui u, ui v, T c = 1) {
		PrevEdge.push_back(LastEdge[u]);
		LastEdge[u] = (ui)E.size();
		E.push_back({u, v, c, 0, 0});
		PrevEdge.push_back(LastEdge[v]);
		LastEdge[v] = (ui)E.size();
		E.push_back({v, u, 0, 0, 0});
	}

	void activate(ui vertex) {
		if (!active[vertex] && excess[vertex] > 0 && level[vertex] < V) {
			active[vertex] = true;
			Q.push(level[vertex], vertex);
		}
	}

	void pushFlow(int f) {
		Edge<T> &e = E[f];
		T flow = min(excess[e.u], e.c - e.f);
		if (level[e.u] == level[e.v] + 1 && flow > T(0)) {
			e.f += flow;
			E[f^1].f -= flow;
			excess[e.v] += flow;
			excess[e.u] -= flow;
			activate(e.v);
		}
	}

	inline void setLevel(ui vertex, ui newLevel) {
		--levelCount[level[vertex]];
		level[vertex] = newLevel;
		++levelCount[level[vertex]];
		activate(vertex);
	}

	void gap(ui k) {
		for (ui v = 0; v < V; v++) {
			if (level[v] >= k) {
				setLevel(v, max(level[v], V));
			}
		}
	}

	void raise(ui vertex) {
		ui newLevel = V;
		for (ui e = LastEdge[vertex]; e != ui(-1); e = PrevEdge[e]) {
			if (E[e].hasResidual()) {
				newLevel = min(newLevel, level[E[e].v] + 1);
			}
		}
		setLevel(vertex, newLevel);
	}

	void discharge(ui vertex) {
		active[vertex] = false;
		for (ui e = LastEdge[vertex]; e != ui(-1); e = PrevEdge[e]) {
			pushFlow(e);
			if (excess[vertex] <= 0) { return; }
		}

		if (levelCount[level[vertex]] == 1) {
			gap(level[vertex]);
		} else {
			raise(vertex);
		}
	}

	T GetMaxFlow(ui source, ui sink) {
		fill(level.begin(), level.end(), 0);
		fill(excess.begin(), excess.end(), T(0));
		fill(levelCount.begin(), levelCount.end(), 0);
		fill(active.begin(), active.end(), false);
		Q.clear();

		for (ui e = LastEdge[source]; e != ui(-1); e = PrevEdge[e]) excess[source] += E[e].c;
		levelCount[0] = V;
		activate(source);
		active[sink] = true;
		while (!Q.empty()) {
			ui v = Q.top(); Q.pop();
			discharge(v);
		}
		return excess[sink];
	}
};
// PUSH RELABEL MAX-FLOW

class GZoningRestrictions {
public:
    void solve(istream& cin, ostream& cout) {
        int N, M, H; cin >> N >> H >> M;
        PushRelabel<int> P(N*H+M+3);

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < H; ++j) {
                P.AddEdge(0, 1+i*H + j, 2*j+1);
            }
        }

        vector<int> S(M);
        for (int k = 0; k < M; ++k) {
            int L, R, X, C;
            cin >> L >> R >> X >> C;
            for (int i = L-1; i < R; ++i) {
                for (int j = X; j < H; ++j) {
                    P.AddEdge(1 + i * H + j, N * H + 1 + k, 100000);
                    S[k] += 2*j+1;
                }
            }

            P.AddEdge(N*H+1+k, N*H+M+2, C);
        }

        auto a = P.GetMaxFlow(0, N*H+M+2);

        cout << N*H*H - a << endl;
    }
};


int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	GZoningRestrictions solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
    return 0;
}
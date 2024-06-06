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
 #ifndef MAJK_MINCOST_MAXFLOW
#define MAJK_MINCOST_MAXFLOW


// MIN-COST MAX-FLOW ALGORITHM. LOOK ELSEWHERE
template<typename T> struct MinCostMaxFlow {
    ui V, E;
    std::vector<ui> LastEdge, Parent, PrevEdge, EdgeTarget;
    std::vector<T> Capacity, Residual, Cost, Distance;

    MinCostMaxFlow(ui v, ui e = 0) : V(v), E(0), LastEdge(V, ui(-1)), Parent(V), Distance(V) {
        Capacity.reserve(2*e);
        Residual.reserve(2*e);
        EdgeTarget.reserve(2*e);
        PrevEdge.reserve(2*e);
        Cost.reserve(2*e);
    }

    void AddEdge(ui x, ui y, T capacity = 1, T cost = 0) {
        EdgeTarget.push_back(y);
        Capacity.push_back(capacity);
        Residual.push_back(capacity);
        Cost.push_back(cost);
        PrevEdge.push_back(LastEdge[x]);
        LastEdge[x] = E++;
        EdgeTarget.push_back(x);
        Capacity.push_back(0);
        Residual.push_back(0);
        Cost.push_back(-cost);
        PrevEdge.push_back(LastEdge[y]);
        LastEdge[y] = E++;
    }

    void bellman(ui source) {
        fill(Parent.begin(),Parent.end(),ui(-1));
        fill(Distance.begin(),Distance.end(),std::numeric_limits<T>::max()/4);
        Distance[source] = 0;
        int ch = 1;
        while (ch--) {
            for (ui e = 0; e < E; ++e) {
                if (Residual[e] > 0) {
                    ui u = EdgeTarget[e^1], v = EdgeTarget[e];
                    if (Distance[u] + Cost[e] < Distance[v]) {
                        Distance[v] = Distance[u] + Cost[e];
                        Parent[v] = e;
                        ch = 1;
                    }
                }
            }
        }
    }

    pair<T,T> push(ui source, ui sink) {
        bellman(source);
//        Q.push({0,source});
//        Distance[source] = 0;
//        while (!Q.empty()) {
//            ui u = Q.top().y;
//            T d = Q.top().x;
//            Q.pop();
//            if (u == sink) break;
//            if (Distance[u] != d) continue;
//            for (ui e = LastEdge[u]; e != -1; e = PrevEdge[e]) {
//                int v = EdgeTarget[e];
//                if (Residual[e] > 0 && Distance[v] > d + Cost[e]) {
//                    Distance[v] = d + Cost[e];
//                    Parent[v] = e;
//                    Q.push({Distance[v], v});
//                }
//            }
//        }

        if (Distance[sink] == std::numeric_limits<T>::max()/4) return {0,0};
        T flow = std::numeric_limits<T>::max(), cost = 0;
        for (ui e = Parent[sink]; e != -1; e = Parent[EdgeTarget[e^1]]) {
            cost += Cost[e];
            flow = min(flow, Residual[e]);
        }

        for (ui e = Parent[sink]; e != -1; e = Parent[EdgeTarget[e^1]]) {
            Residual[e] -= flow;
            Residual[e^1] += flow;
        }

        return {flow,flow*cost};
    }

    pair<T,T> GetMaxFlow(int u, int v) {
        bellman(u);
        T piSink = Distance[v];
        for (int e = 0; e < E; e+=2) {
            Cost[e] = Cost[e] + Distance[EdgeTarget[e^1]] - Distance[EdgeTarget[e]];
            Cost[e^1] = 0;
        }

        pair<T,T> ret = {0,0};
        while (true) {
            pair<T,T> f = push(u, v);
            if (f.x == 0) break;
            ret.x += f.x;
            ret.y += f.y;
        }

        ret.y += ret.x * piSink;
        return ret;
    }


    vector<std::tuple<ui, ui, T>> GetEdgesWithFlow() {
        vector<std::tuple<ui, ui, T>> Ans;
        for (ui u = 0; u < V; ++u) {
            for (ui e = LastEdge[u]; e != ui(-1); e = PrevEdge[e]) {
                if (Residual[e] < Capacity[e]) {
                    Ans.push_back({u, EdgeTarget[e], Capacity[e] - Residual[e]});
                }
            }
        }
        return Ans;
    };
};
// DINIC MAX-FLOW ALGORITHM
#endif

class buildstring {
public:
    void solve(istream& cin, ostream& cout) {
        string S; cin >> S;
        int N; cin >> N;
        MinCostMaxFlow<int> MF(N+26+2);
        for (char s: S) MF.AddEdge(0, s-'a'+1, 1, 0);

        for (int i = 0; i < N; ++i) {
            string T; int cap; cin >> T >> cap;
            for (char t: T) MF.AddEdge(t-'a'+1, 27+i, 1, 0);
            MF.AddEdge(27+i, 27+N, cap, i+1);
        }

        auto F = MF.GetMaxFlow(0, 27+N);
        if (F.x == S.size()) {
            cout << F.y << '\n';
        } else {
            cout << -1 << '\n';
        }

    }
};


int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	buildstring solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
    return 0;
}
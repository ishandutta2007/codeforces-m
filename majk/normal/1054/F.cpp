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
 // ordinary rooted tree with level ancestry and LCA. look elsewhere
struct Tree {
	explicit Tree(int N=1) : N(N), logN(logceil(N)), _root(0), E(N) {}
	void addEdge(int u,int v){E[u].push_back(v);E[v].push_back(u);}
	int la(int u, int depth){/*calcLA();*/return _la(u,depth);}
	inline int lca(int u, int v){/*calcLA();*/return _lca(u,v);}
	int parent(int u) { return P[u]; }
	void setRoot(int r) { _root = r; }
	int root() { return _root; }
	const vector<int>& neighbors(int u) const { return E[u]; }
    int depth(int u) { return D[u]; }
	bool isAncestor(int top, int bottom) { return lca(top, bottom) == top; }
	bool sameBranch(int top, int bottom) { int l = lca(top, bottom); return l == top || l == bottom; }

	int _la(int u, int d)const{for(int i=0;i<logN&&u!=-1;++i){if(d&(1<<i))u=PP[i][u];}return u;}
	int _lca(int u, int v) { if(D[u]<D[v]){swap(u,v);} u=_la(u,D[u]-D[v]);
		for(int i=logN-1;i>=0;--i)if(PP[i][u]!=PP[i][v]){u=PP[i][u];v=PP[i][v];}
		return u==v?u:PP[0][v];
	}
	inline void calcParents(){if(P.size()==0){P.resize(N);D.resize(N);dfs(_root,-1,0);}}
	void dfs(int u,int v,int d){P[u]=v;D[u]=d;for(int w:E[u])if(v!=w)dfs(w,u,d+1);}
	inline void calcLA(){calcParents();if(PP.size()==0){PP=vector2<int>(logN,N,-1);for(int i=0;i<N;++i){PP[0][i]=P[i];}
			for(int i=1;i<logN;++i)for(int j=0;j<N;++j)if(PP[i-1][j]!=-1)PP[i][j]=PP[i-1][PP[i-1][j]];}}
	int N,logN,_root; vector<vector<int>> E;vector<int> P,D;vector2<int>PP;
};

template <typename EdgeType>
class DFSOrder {
public:
    DFSOrder(const vector<vector<EdgeType>> &_E) : T(0), N(_E.size()), E(_E), RevEnter(N), Enter(N), Exit(N) {
        dfs(0, -1);
    }

    vector<vector<EdgeType>> linearize() {
        vector<vector<EdgeType>> F(N);
        for (int i = 0; i < N; ++i) {
            for (auto v:E[i]) {
                F[conv(i)].push_back(conv(v));
            }
        }
        return F;
    }

    void dfs(int u, int p) {
        RevEnter[T] = u;
        Enter[u] = T++;
        for (auto v:E[u]) if (t(v) != p) dfs(t(v), u);
        Exit[u] = T;
    }

    inline int t(const int&e) const { return e; }
    template <typename U> inline int t(const pair<int, U>&e) const { return e.x; }

    inline int conv(const int&e) const { return Enter[e]; }
    template <typename U> inline pair<int, U> conv(const pair<int, U>&e) const { return {Enter[e.x], e.y}; }

    const vector<int> &revEnter() const { return RevEnter; }
    const vector<int> &enter() const { return Enter; }
    const vector<int> &exit() const { return Exit; }

    int T, N;
    const vector<vector<EdgeType>> &E;
    vector<int> Enter, Exit, RevEnter;
};

/** Centroid decomposition.
 *
 * Input: graph as adjacency list (either int or pair<int,T>)
 * Output: array U of intergers of size |V|
 *
 * Here, U[v] is the bfs order in the centroid tree. For DFS, only process
 * vertices with higher U[w] when processing centroid v, for instance:
 *
 * void dfs(int u, int p, int ctr, ...) {
 *      ....
 *      for (int v:E[u]) {
 *          if (v != p && U[u] > U[ctr]) {
 *              dfs(v, u, ctr, ...);
 *          }
 *      }
 * }
 */
template <typename EdgeType>
class CentroidDecomposition {
public:
    CentroidDecomposition(const vector<vector<EdgeType>> &E) : E(E) {}

    const vector<int>& findCentroids() {
        N = E.size(); U.assign(N, -1);
        int L = 0;

        for (int j = 0; j < N; ) {
            for (int i = N-1; i >= 0; --i) {
                if (U[i] >= 0) continue;

                U[i] = -1;
                bool root = true;
                for (auto v:E[i]) {
                    if (U[t(v)]<0) {
                        if (t(v) > i) U[i] += U[t(v)];
                        else root = false;
                    }
                }

                if (root) {
                    int n = -U[i], u = i, p = -1;
                    while (true) {
                        int s = n + U[u];
                        for (auto v:E[u]) if (t(v)!=p && U[t(v)] < 0) s = max(s, -U[t(v)]);
                        if (2 * s <= n) { U[u] = j++; break; }
                        else { for (auto v:E[u]) if (t(v)!=p && -U[t(v)] > n / 2) { p = u;u = t(v);break; } }
                    }
                }
            }
        }
        return U;
    }

    inline int t(const int&e) const { return e; }
    template <typename U> inline int t(const pair<int, U>&e) const { return e.x; }

    int N;
    const vector<vector<EdgeType>> &E;
    vector<int> U;
};


// ordinary bipartite graph, with max. matching, max. indep. set and min. vertex cover. look elsewhere
struct Bipartite {
	explicit Bipartite(ui A, ui B) : A(A), B(B), N(A+B), ms(-1), H(N,-1), used(A) {}
	void addEdge(int u,int v){G.push_back(v);P.push_back(H[u]);H[u]=(ui)G.size()-1;}
	ui matchingSize(){calcMatching();return ms;}
	int matched(int v){calcMatching();return M[v];}
	vector<int>cover(){calcCover();vector<int>C;for(int i=0;i<N;++i){if(Z[i]!=(i<A))C.push_back(i);}return C;}
	vector<int>indep(){calcCover();vector<int>I;for(int i=0;i<N;++i){if(Z[i]==(i<A))I.push_back(i);}return I;}
//private:
	void konigDfs(int u){
        if(Z[u]){return;}
        Z[u]=true;
        if(u<A){
            for (ui p = H[u]; p != -1; p = P[p]) {
                ui v = G[p];
                if (v != M[u])konigDfs(v);
            }
        }
        else if(M[u]!=-1)
            konigDfs(M[u]);
    }
    bool matchingDfs(int u) {
        if (used[u]) return false;
        used[u] = true;

        for (ui p = H[u]; p != -1; p = P[p]) {
            ui v = G[p];
            if (M[v]==-1) { M[u] = v; M[v] = u; ++ms; return true; }
        }

        for (ui p = H[u]; p != -1; p = P[p]) {
            ui v = G[p];
            if (matchingDfs(M[v])) { M[u] = v; M[v] = u; return true; }
        }
        return false;

    }
	inline void calcMatching(){
        if(ms!=-1){return;}
        M = vector<ui>(N,-1);
        size_t cur; ms = 0;
        do {
            cur = ms;
            for(int i=0;i<A;++i) used[i] = false;
            for(int i=0;i<A;++i) if(M[i]==-1) matchingDfs(i);
        } while(cur != ms);
    }
	inline void calcCover(){if(Z.size()==N){return;}calcMatching();Z=vector<bool>(N,false);for(int i=0;i<A;++i)if(M[i]==-1)konigDfs(i);}
	ui N,A,B,ms;vector<ui>M,H,G,P;vector<bool>Z,used;
};

struct DirectedGraph {
	explicit DirectedGraph(int N) : N(N), E(N) {}
	void addEdge(int u,int v){E[u].push_back({v});}
	int stronglyConnectedComponent(int v){calcStronglyConnectedComponents();return SCC[v];}
	bool stronglyConnected(int u,int v){calcStronglyConnectedComponents();return SCC[u]==SCC[v];}
	const vector<int>& stronglyConnectedPermutation() {calcStronglyConnectedComponents(); return O;}
//private:
	inline void calcReverseEdges(){if(ER.size()==N){return;}ER.resize(N);for(int i=0;i<N;++i)for(int u:E[i])ER[u].push_back(i);}
	inline void calcStronglyConnectedComponents(){
		if(SCC.size()==N){return;}SCC.resize(N);O.resize(N);calcReverseEdges();
		vector<bool>V(N,false);vector<int>F(N,0);int t=0;for(int i=N-1;i>=0;i--){if(!V[i]){dfsReverse(i,V,F,t);}O[N-1-F[i]] = i;}
		fill(V.begin(),V.end(),false);for(int i=0;i<N;i++){if(!V[O[i]])dfsForward(O[i],O[i],V);}
	}
	void dfsForward(int i,int p,vector<bool>&V){V[i]=true;SCC[i]=p;for(int v:E[i])if(!V[v])dfsForward(v,p,V);}
	void dfsReverse(int i,vector<bool>&V,vector<int>&F,int&t){V[i]=true;for(int v:ER[i]){if(!V[v])dfsReverse(v,V,F,t);}F[i] = t++;}
	int N; vector<vector<int>>E,ER;vector<int>SCC,O;
};

struct TwoSat {
	explicit TwoSat(int N=0) : N(N), G(2*N) {}
	void forbid(int u,bool w){G.addEdge(u+N*(1-w),u+N*w);}
	void addClause(int u,bool w,int v,bool x){G.addEdge(u+N*w,v+N*(1-x));G.addEdge(v+N*x,u+N*(1-w));}
	bool satisfiable() {calculateAssignment();return ok;}
	const vector<int>& assignment() {calculateAssignment();return A;}
//private:
	inline void calculateAssignment(){if(A.size()==N){return;}A.resize(N);ok=true;map<int,bool>Q;
		for(int u:G.stronglyConnectedPermutation()){
			int c1=G.stronglyConnectedComponent(u),c2=G.stronglyConnectedComponent((u+N)%(2*N));
			if(c1==c2){ok=false;return;}if(Q.find(c1)==Q.end()){Q[c1]=true;Q[c2]=false;}}
		for(int i=0;i<N;++i){A[i]=Q[G.stronglyConnectedComponent(i)];}
	}
	int N; DirectedGraph G;vector<int>A;bool ok;
};

class TaskF {
public:
    void solve(istream& cin, ostream& cout) {
        int N;
        cin >> N;
        vector<pii> P(N);
        cin >> P;
        set<int> CX, CY;
        for (int i = 0; i < N; ++i) {
            CX.insert(P[i].x);
            CY.insert(P[i].y);
        }

        map<int, int> CMPX, CMPY;
        vector<int> BX, BY;
        for (int c : CX) {
            CMPX[c] = BX.size();
            BX.push_back(c);
        }
        for (int c : CY) {
            CMPY[c] = BY.size();
            BY.push_back(c);
        }

        for (int i = 0; i < N; ++i) P[i] = {CMPX[P[i].x], CMPY[P[i].y]};
        vector<pair<pii, pii>> Blue, Red;

        int MX = BX.size(), MY = BY.size();
        vector2<bool> S(MX, MY, true);
        for (pii p: P) S[p.x][p.y] = false;

        vector<pair<pii, pii>> Horiz, Vert;
        for (int i = 0; i < MX; ++i) {
            int j = 0;
            while (j < MY && S[i][j]) ++j;
            while (j < MY) {
                while (j < MY && !S[i][j]) ++j;
                if (j < MY) {
                    int k = j;
                    while (j < MY && S[i][j]) ++j;
                    if (j != MY) {
                        Horiz.push_back({{i, k},
                                         {i, j - 1}});
                    }
                }
            }
        }

        for (int i = 0; i < MY; ++i) {
            int j = 0;
            while (j < MX && S[j][i]) ++j;
            while (j < MX) {
                while (j < MX && !S[j][i]) ++j;
                if (j < MX) {
                    int k = j;
                    while (j < MX && S[j][i]) ++j;
                    if (j != MX) {
                        Vert.push_back({{k, i}, {j - 1, i}});
                    }
                }
            }
        }


        Bipartite G(Horiz.size(), Vert.size());
        for (int i = 0; i < Horiz.size(); ++i) {
            for (int j = 0; j < Vert.size(); ++j) {
                if (Horiz[i].x.x >= Vert[j].x.x && Horiz[i].x.x <= Vert[j].y.x && Vert[j].x.y >= Horiz[i].x.y && Vert[j].x.y <= Horiz[i].y.y) {
                    G.addEdge(i, Horiz.size()+j);
                }
            }
        }

        G.calcMatching();
        vector<int> Cover = G.cover();
        vector<vector<pii>> RemX(MX), RemY(MY);
        vector<int> LOX(MY, MX), HIX(MY, 0), LOY(MX, MY), HIY(MX, 0);
        for (int i : Cover) {
            if (i < Horiz.size()) {
                RemX[Horiz[i].x.x].push_back({Horiz[i].x.y,Horiz[i].y.y});
            } else {
                i -= Horiz.size();
                RemY[Vert[i].x.y].push_back({Vert[i].x.x,Vert[i].y.x});
            }
        }

        for (pii p:P) {
            LOX[p.y] = min(LOX[p.y], p.x);
            HIX[p.y] = max(HIX[p.y], p.x);
            LOY[p.x] = min(LOY[p.x], p.y);
            HIY[p.x] = max(HIY[p.x], p.y);
        }

        for (int i = 0; i < MX; ++i) {
            int l = LOY[i], r = HIY[i];
            if (RemX[i].empty()) {
                Red.push_back({{i,l},{i,r}});
            } else {
                for (int j = 0; j < RemX[i].size()-1; ++j) {
                    Red.push_back({{i,RemX[i][j].y+1}, {i,RemX[i][j+1].x-1}});
                }
                Red.push_back({{i,l},{i,RemX[i][0].x-1}});
                Red.push_back({{i,RemX[i].back().y+1},{i,r}});
            }
        }

        for (int i = 0; i < MY; ++i) {
            int l = LOX[i], r = HIX[i];
            if (RemY[i].empty()) {
                Blue.push_back({{l,i},{r,i}});
            } else {
                for (int j = 0; j < RemY[i].size()-1; ++j) {
                    Blue.push_back({{RemY[i][j].y+1,i}, {RemY[i][j+1].x-1,i}});
                }
                Blue.push_back({{l,i},{RemY[i][0].x-1,i}});
                Blue.push_back({{RemY[i].back().y+1,i},{r,i}});
            }
        }

        cout << Blue.size() << '\n';
        for (auto b:Blue) cout << BX[b.x.x] << ' ' << BY[b.x.y] << ' ' << BX[b.y.x] << ' ' << BY[b.y.y] << '\n';
        cout << Red.size() << '\n';
        for (auto b:Red) cout << BX[b.x.x] << ' ' << BY[b.x.y] << ' ' << BX[b.y.x] << ' ' << BY[b.y.y] << '\n';
    }
};


int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	TaskF solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
    return 0;
}
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
#ifndef MAJK_DINIC
#define MAJK_DINIC


// DINIC MAX-FLOW ALGORITHM. LOOK ELSEWHERE
template<typename T> struct Dinic {
	ui V, E;
	std::vector<ui> LastEdge, EdgeToProcess, BfsDistance, PrevEdge, EdgeTarget;
	std::vector<T> Capacity, Residual;

	Dinic(ui v, ui e = 0) : V(v), E(0), LastEdge(V, ui(-1)), BfsDistance(V), EdgeToProcess(V) {
		Capacity.reserve(2*e);
		Residual.reserve(2*e);
		EdgeTarget.reserve(2*e);
		PrevEdge.reserve(2*e);
	}

	void AddEdge(ui x, ui y, T c1 = 1, T c2 = 0) {
//		cerr << x << ' ' << y << endl;
		EdgeTarget.push_back(y);
		Capacity.push_back(c1);
		Residual.push_back(c1);
		PrevEdge.push_back(LastEdge[x]);
		LastEdge[x] = E++;
		EdgeTarget.push_back(x);
		Capacity.push_back(c2);
		Residual.push_back(c2);
		PrevEdge.push_back(LastEdge[y]);
		LastEdge[y] = E++;
	}

	T push(int x, int v, T flow) {
		if (x == v) return flow;
		for (ui &e = EdgeToProcess[x]; e != -1; e = PrevEdge[e]) {
			ui y = EdgeTarget[e];
			if (Residual[e] && BfsDistance[x] + 1 == BfsDistance[y]) {
				if (T f = push(y, v, min(flow, Residual[e]))) {
					Residual[e] -= f;
					Residual[e ^ 1] += f;
					return f;
				}
			}
		}
		return 0;
	}

	T GetMaxFlow(int u, int v) {
		T ret = 0;
		while (true) {
			fill(BfsDistance.begin(), BfsDistance.end(), (ui)-1);
			BfsDistance[u] = 0;
			std::queue<int> Q{{u}};
			while (!Q.empty()) {
				int x = Q.front(); Q.pop();
				for (int e = LastEdge[x]; e != ui(-1); e = PrevEdge[e]) {
					ui y = EdgeTarget[e];
					if (Residual[e] && BfsDistance[y] == ui(-1)) {
						Q.push(y);
						BfsDistance[y] = BfsDistance[x] + 1;
					}
				}

			}

			if (BfsDistance[v] == ui(-1)) break;
			copy(LastEdge.begin(), LastEdge.end(), EdgeToProcess.begin());
			while (T f = push(u, v, std::numeric_limits<T>::max())) ret += f;
		}

		return ret;
	}

	std::vector<bool> GetMinCut(int u) {
		std::queue<int> Q;
		Q.push(u);
		vector<bool> R(V, false);
		R[u] = true;
		while (!Q.empty()) {
			int x = Q.front();
			Q.pop();
			for (int e = LastEdge[x]; e != -1; e = PrevEdge[e]) {
				int y = EdgeTarget[e];
				if (!R[y] && Residual[e] > 0) {
					Q.push(y);
					R[y] = true;
				}
			}
		}
		return R;
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

// ordinary rooted tree with level ancestry and LCA. look elsewhere
struct Tree {
	explicit Tree(int N=1) : N(N), logN(logceil(N)), _root(0), E(N) {}
	void addEdge(int u,int v){E[u].push_back(v);E[v].push_back(u);}
	int la(int u, int depth){calcLA();return _la(u,depth);}
	int lca(int u, int v){calcLA();return _lca(u,v);}
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

// ordinary bipartite graph, with max. matching, max. indep. set and min. vertex cover. look elsewhere
struct Bipartite {
	explicit Bipartite(ui A, ui B) : A(A), B(B), N(A+B), ms(-1), H(N,-1), used(A) {}
	void addEdge(int u,int v){G.push_back(v);P.push_back(H[u]);H[u]=(ui)G.size()-1;}
	ui matchingSize(){calcMatching();return ms;}
	int matched(int v){calcMatching();return M[v];}
	vector<int>cover(){calcCover();vector<int>C;for(int i=0;i<N;++i){if(Z[i]!=(i<A))C.push_back(i);}return C;}
	vector<int>indep(){calcCover();vector<int>I;for(int i=0;i<N;++i){if(Z[i]==(i<A))I.push_back(i);}return I;}
private:
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
private:
	inline void calculateAssignment(){if(A.size()==N){return;}A.resize(N);ok=true;map<int,bool>Q;
		for(int u:G.stronglyConnectedPermutation()){
			int c1=G.stronglyConnectedComponent(u),c2=G.stronglyConnectedComponent((u+N)%(2*N));
			if(c1==c2){ok=false;return;}if(Q.find(c1)==Q.end()){Q[c1]=true;Q[c2]=false;}}
		for(int i=0;i<N;++i){A[i]=Q[G.stronglyConnectedComponent(i)];}
	}
	int N; DirectedGraph G;vector<int>A;bool ok;
};

class foolsandroads {
public:
    int N;
    vector<vector<pii>> E;
    vector<int> V, A;

    int dfs(int u, int p) {
        int s = V[u];
        for (pii v:E[u]) {
            if (v.x!=p) {
                int x = dfs(v.x, u);
                A[v.y] = x;
                s += x;
            }
        }
        return s;
    }

    void solve(istream& cin, ostream& cout) {
        cin >> N;
        E.resize(N);
        Tree T(N);
        V = vector<int>(N, 0);
        A.resize(N-1);
        for (int i = 0; i < N-1; ++i) {
            int u, v;
            cin >> u >> v;
            --u;
            --v;
            E[u].push_back({v,i});
            E[v].push_back({u,i});
            T.addEdge(u,v);
        }

        int K; cin >> K;
        for (int i = 0; i < K; ++i) {
            int u,v; cin >> u >> v;
            --u; --v;
            V[u]++;
            V[v]++;
            V[T.lca(u,v)] -= 2;
        }

        dfs(0, -1);
        cout << A;
    }
};


int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	foolsandroads solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
    return 0;
}
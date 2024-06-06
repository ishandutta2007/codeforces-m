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
 template <typename K, typename V> struct avlnode {
	avlnode(K k, V v) : l(0),r(0),h(1),s(1),k(k),v(v) {}
	~avlnode() { delete l; delete r; }
	avlnode<K,V> *l,*r;int h,s;K k;V v;
	int size() const { return s; }
	void u() { s=(l?l->s:0)+(r?r->s:0)+1; h=max(l?l->h:0,r?r->h:0)+1; }
	avlnode<K,V>*rr() {auto x = l; l = x->r; u(); x->r = this; x->u(); return x; }
	avlnode<K,V>*lr() {auto y = r; r = y->l; u(); y->l = this; y->u(); return y; }
	avlnode<K,V>*insert(K k, V v) {
		if (k<this->k) l=l?l->insert(k,v):new avlnode<K,V>(k,v);
		else r=r?r->insert(k,v):new avlnode<K,V>(k,v);
		return balance();
	}
	int getBalance() const { return (l?l->h:0) - (r?r->h:0); }
	avlnode<K,V>* get(K k) {
		if (k<this->k) { return l ? l->get(k) : nullptr; }
		else if (k>this->k) { return r ? r->get(k) : nullptr; }
		else { return this; }
	};
	ui smaller(K k) {
		if (k<this->k) return l ? l->smaller(k) : 0;
		else {
			ui s = l ? l->s : 0;
			if (k==this->k) return s;
			else return s+1+ (r?r->smaller(k):0);
		}
	};
	avlnode<K,V>* remove(K k) {
		if (k<this->k) { if(l) l = l->remove(k); else return this; }
		else if (k>this->k) { if (r) r = r->remove(k); else return this; }
		else if (!l) { avlnode<K,V>*t = r; r = nullptr; delete this; return t; }
		else if (!r) { avlnode<K,V>*t = l; l = nullptr; delete this; return t; }
		else { avlnode<K,V>* q = l; while (q->r) { q = q->r; } this->k = q->k; this->v = q->v; l = l->remove(this->k); }
		return balance();
	};
	avlnode<K,V>* balance() {
		int b = getBalance();
		if (b > 1) { if (l->getBalance() >= 0) return rr(); else { l = l->lr(); return rr(); } }
		if (b < -1) { if (r->getBalance() > 0) { r=r->rr(); return lr(); } else { return lr(); } }
		u(); return this;
	};
	template<typename T> void foreach(T f) {if(l){l->foreach(f);}f(k,v);if(r){r->foreach(f);}}
	avlnode<K,V>* at(int c) {if (l) {if (l->s > c) return l->at(c); else c -= l->s;} return c ? r->at(c-1) : this; }
	avlnode<K,V>* merge(avlnode<K,V> *n) {auto q = this; n->foreach([&q](K k,V v){ q=q->insert(k,v); }); return q; }
};
template<typename K,typename V>ostream& operator<<(ostream &os, const avlnode<K,V>& t) {os<<'<';if (t.l){os<<t.l<<',';}os<<'('<<t.k<<','<<t.v<<')';if(t.r){os<<','<<t.r;}os<<'>';return os;}

template<typename K, typename V> struct avl {
	avl() : r(0) {}
	~avl() { delete r; }
	avlnode<K,V>* get(K k) { return r?r->get(k):0; };
	ui smaller(K k) { return r?r->smaller(k):0; }
	void insert(K k, V v) { r=r?r->insert(k,v):new avlnode<K,V>(k,v); };
	void remove(K k) { r=r?r->remove(k):r; }
	avlnode<K,V>* select(int c) { if (!r||r->s<=c||c<0) return 0; else return r->at(c); };
	int size() const { return r?r->s:0; }
	template<typename T> void foreach(T f) {if(r)r->foreach(f);}
	avlnode<K,V> *r;
};

class TaskD {
public:
void solve(istream& cin, ostream& cout) {
    int N; cin >> N;
    map<int, avl<int,int>> A, R;
    for (int n = 0; n < N; ++n) {
        int a,t,x; cin >> a >> t >> x;
        if (a == 1) {
            A[x].insert(t, t);
        } else if (a == 2) {
            R[x].insert(t, t);
        } else {
            cout << A[x].smaller(t) - R[x].smaller(t) << '\n';
        }
    }

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
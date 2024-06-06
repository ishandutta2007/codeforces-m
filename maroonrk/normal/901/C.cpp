#include <bits/stdc++.h>
using namespace std;

using ll=long long;
//#define int ll

#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define pb push_back
#define eb emplace_back
#define a first
#define b second
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
#define si(x) int(x.size())
#ifdef LOCAL
#define dmp(x) cerr<<__LINE__<<" "<<#x<<" "<<x<<endl
#else
#define dmp(x) void(0)
#endif

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;

using pi=pair<int,int>;
using vi=vc<int>;

template<class t,class u>
ostream& operator<<(ostream& os,const pair<t,u>& p){
	return os<<"{"<<p.a<<","<<p.b<<"}";
}

template<class t> ostream& operator<<(ostream& os,const vc<t>& v){
	os<<"{";
	for(auto e:v)os<<e<<",";
	return os<<"}";
}

#define mp make_pair
#define mt make_tuple
#define one(x) memset(x,-1,sizeof(x))
#define zero(x) memset(x,0,sizeof(x))
#ifdef LOCAL
void dmpr(ostream&os){os<<endl;}
template<class T,class... Args>
void dmpr(ostream&os,const T&t,const Args&... args){
	os<<t<<" ";
	dmpr(os,args...);
}
#define dmp2(...) dmpr(cerr,__LINE__,##__VA_ARGS__)
#else
#define dmp2(...) void(0)
#endif

using uint=unsigned;
using ull=unsigned long long;

template<class t,size_t n>
ostream& operator<<(ostream&os,const array<t,n>&a){
	return os<<vc<t>(all(a));
}

template<int i,class T>
void print_tuple(ostream&,const T&){
}

template<int i,class T,class H,class ...Args>
void print_tuple(ostream&os,const T&t){
	if(i)os<<",";
	os<<get<i>(t);
	print_tuple<i+1,T,Args...>(os,t);
}

template<class ...Args>
ostream& operator<<(ostream&os,const tuple<Args...>&t){
	os<<"{";
	print_tuple<0,tuple<Args...>,Args...>(os,t);
	return os<<"}";
}

template<class t>
void print(t x,int suc=1){
	cout<<x;
	if(suc==1)
		cout<<"\n";
	if(suc==2)
		cout<<" ";
}

ll read(){
	ll i;
	cin>>i;
	return i;
}

vi readvi(int n,int off=0){
	vi v(n);
	rep(i,n)v[i]=read()+off;
	return v;
}

template<class T>
void print(const vector<T>&v,int suc=1){
	rep(i,v.size())
		print(v[i],i==int(v.size())-1?suc:2);
}

string readString(){
	string s;
	cin>>s;
	return s;
}

template<class T>
T sq(const T& t){
	return t*t;
}

//#define CAPITAL
void yes(bool ex=true){
	#ifdef CAPITAL
	cout<<"YES"<<"\n";
	#else
	cout<<"Yes"<<"\n";
	#endif
	if(ex)exit(0);
}
void no(bool ex=true){
	#ifdef CAPITAL
	cout<<"NO"<<"\n";
	#else
	cout<<"No"<<"\n";
	#endif
	if(ex)exit(0);
}
void possible(bool ex=true){
	#ifdef CAPITAL
	cout<<"POSSIBLE"<<"\n";
	#else
	cout<<"Possible"<<"\n";
	#endif
	if(ex)exit(0);
}
void impossible(bool ex=true){
	#ifdef CAPITAL
	cout<<"IMPOSSIBLE"<<"\n";
	#else
	cout<<"Impossible"<<"\n";
	#endif
	if(ex)exit(0);
}

constexpr ll ten(int n){
	return n==0?1:ten(n-1)*10;
}

const ll infLL=LLONG_MAX/3;

#ifdef int
const int inf=infLL;
#else
const int inf=INT_MAX/2-100;
#endif

int topbit(signed t){
	return t==0?-1:31-__builtin_clz(t);
}
int topbit(ll t){
	return t==0?-1:63-__builtin_clzll(t);
}
int botbit(signed a){
	return a==0?32:__builtin_ctz(a);
}
int botbit(ll a){
	return a==0?64:__builtin_ctzll(a);
}
int popcount(signed t){
	return __builtin_popcount(t);
}
int popcount(ll t){
	return __builtin_popcountll(t);
}
bool ispow2(int i){
	return i&&(i&-i)==i;
}
ll mask(int i){
	return (ll(1)<<i)-1;
}

bool inc(int a,int b,int c){
	return a<=b&&b<=c;
}

template<class t> void mkuni(vc<t>&v){
	sort(all(v));
	v.erase(unique(all(v)),v.ed);
}

ll rand_int(ll l, ll r) { //[l, r]
	#ifdef LOCAL
	static mt19937_64 gen;
	#else
	static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
	#endif
	return uniform_int_distribution<ll>(l, r)(gen);
}

template<class t>
void myshuffle(vc<t>&a){
	rep(i,si(a))swap(a[i],a[rand_int(0,i)]);
}

template<class t>
int lwb(const vc<t>&v,const t&a){
	return lower_bound(all(v),a)-v.bg;
}

//find  lazy ()

//cf16-tournament-round1-open A
//JOISC2013 day4 Spaceships
//AOJ2450
//CF Hello2020
template<class N>
struct linkcut{
	struct Node{
		using np=Node*;
		np l,r,p;
		bool rev;
		N x;
		Node():l(0),r(0),p(0),rev(false),x(){}
		void reverse(){
			rev^=true;
			x.reverse();
		}
		void propagate(){
			if(rev){
				swap(l,r);
				if(l)l->reverse();
				if(r)r->reverse();
				rev=false;
			}
			if(l)x.push(l->x);
			if(r)x.push(r->x);
			x.clear();
		}
		void update(){
			x.single();
			if(l)
				x.updatel(l->x);
			if(r)
				x.updater(r->x);
		}
		int pos(){
			if(p&&p->l==this) return -1;
			if(p&&p->r==this) return 1;
			return 0;
		}
		void prepare(){
			if(pos())
				p->prepare();
			propagate();
		}
		void rotate(){
			np q=p,c;
			if(pos()==1){
				c=l;
				l=p;
				p->r=c;
			}else{
				c=r;
				r=p;
				p->l=c;
			}
			if(c)c->p=p;
			p=p->p;
			q->p=this;
			if(p&&p->l==q)p->l=this;
			if(p&&p->r==q)p->r=this;
			q->update();
		}
		void splay(){
			prepare();
			while(pos()){
				int a=pos(),b=p->pos();
				if(b&&a==b)p->rotate();
				if(b&&a!=b)rotate();
				rotate();
			}
			update();
		}
		void expose(){
			for(np a=this;a;a=a->p)a->splay();
			for(np a=this;a->p;a=a->p){
				a->p->r=a;
				a->p->update();
			}
			splay();
		}
		void evert(){
			expose();
			if(l){
				l->reverse();
				l=0;
				update();
			}
		}
		void link(np a){
			evert();
			p=a;
		}
		template<class F,class...Args>
		np find(F f,Args&&...args){
			if(!(x.*f)(forward<Args>(args)...))return 0;
			propagate();
			x.single();
			np a=0;
			if(l)a=l->find(f,forward<Args>(args)...);
			if(a)return a;
			if((x.*f)(forward<Args>(args)...)){
				splay();
				return this;
			}
			return r->find(f,forward<Args>(args)...);
		}
		void cutchild(){
			expose();
			r=0;
			update();
		}
		void cutpar() {
			expose();
			assert(l);
			l->p=0;
			l=0;
			update();
		}
	}*x;
	linkcut(int n){
		x=new Node[n];
	}
	~linkcut(){delete[] x;}
	
	using np=typename Node::np;
	int lca(int aa,int bb){
		np a=x+aa,b=x+bb;
		a->expose();
		b->expose();
		if(!a->p)return -1;
		
		np d=a;
		while(a->p!=b){
			if(a->pos()==0)
				d=a->p;
			a=a->p;
		}
		if(a==b->l)return d-x;
		else return b-x;
	}
	void link(int a,int b){
		x[a].link(x+b);
	}
	void cutpar(int a){
		x[a].cutpar();
	}
	void expose(int a){
		x[a].expose();
	}
	void evert(int a){
		x[a].evert();
	}
	void expose_path(int a,int b){
		x[a].evert();
		x[b].cutchild();
	}
	N&operator[](int i){
		return x[i].x;
	}
	template<class F,class...Args>
	int find(int a,F f,Args&&...args){
		np res=x[a].find(f,forward<Args>(args)...);
		if(res)return res-x;
		else return -1;
	}
};
//N::reverse
//N::push
//,push
//N::clear
//lazy tag
//N::single
//
//N::updatel,updater
//N::find

//v  1 
struct N{
	void init(){
	}
	void reverse(){
	}
	void push(N&){
	}
	void clear(){
	}
	void single(){
	}
	void updatel(const N&){
	}
	void updater(const N&){
	}
};

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int n,m;cin>>n>>m;
	vvc<pi> g(n);
	vi used(m);
	rep(i,m){
		int a,b;cin>>a>>b;
		a--;b--;
		g[a].eb(b,i);
		g[b].eb(a,i);
	}
	vi left(n);
	{
		linkcut<N> lc(n);
		int l=0,r=0;
		auto deledge=[&](int a,int b,int i){
			if(!used[i])return;
			lc.evert(a);
			lc.cutpar(b);
			used[i]=0;
		};
		auto delvert=[&](){
			assert(l<r);
			for(auto e:g[l]){
				deledge(l,e.a,e.b);
			}
			l++;
		};
		auto addvert=[&](){
			assert(r<n);
			for(auto e:g[r]){
				while(inc(l,e.a,r-1)&&lc.lca(r,e.a)!=-1){
					delvert();
				}
				if(inc(l,e.a,r-1)){
					lc.link(r,e.a);
					used[e.b]=1;
				}
			}
			r++;
		};
		rep(i,n){
			addvert();
			left[i]=l;
		}
	}
	dmp(left);
	//vi sum(n+1);
	vc<ll> sum(n+1);
	rep(i,n)sum[i+1]=sum[i]+left[i];
	
	int q;cin>>q;
	rep(_,q){
		int l,r;cin>>l>>r;
		l--;
		ll ans=ll(r-l)*(r-l+1)/2;
		int i=max(lwb(left,l),l);
		if(i<r){
			ans-=sum[r]-sum[i]-ll(r-i)*l;
		}
		print(ans);
	}
}
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

template<class t>
bool inc(t a,t b,t c){
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
    static random_device rd;
    static mt19937_64 gen(rd());
    #endif
    return uniform_int_distribution<ll>(l, r)(gen);
}

template<class t>
int lwb(const vc<t>&v,const t&a){
	return lower_bound(all(v),a)-v.bg;
}

using uint=unsigned;
using ull=unsigned long long;

struct modinfo{uint mod,root;};
template<modinfo const&ref>
struct modular{
	static constexpr uint const &mod=ref.mod;
	static modular root(){return modular(ref.root);}
	uint v;
	//modular(initializer_list<uint>ls):v(*ls.bg){}
	modular(ll vv=0){s(vv%mod+mod);}
	modular& s(uint vv){
		v=vv<mod?vv:vv-mod;
		return *this;
	}
	modular operator-()const{return modular()-*this;}
	modular& operator+=(const modular&rhs){return s(v+rhs.v);}
	modular&operator-=(const modular&rhs){return s(v+mod-rhs.v);}
	modular&operator*=(const modular&rhs){
		v=ull(v)*rhs.v%mod;
		return *this;
	}
	modular&operator/=(const modular&rhs){return *this*=rhs.inv();}
	modular operator+(const modular&rhs)const{return modular(*this)+=rhs;}
	modular operator-(const modular&rhs)const{return modular(*this)-=rhs;}
	modular operator*(const modular&rhs)const{return modular(*this)*=rhs;}
	modular operator/(const modular&rhs)const{return modular(*this)/=rhs;}
	modular pow(int n)const{
		modular res(1),x(*this);
		while(n){
			if(n&1)res*=x;
			x*=x;
			n>>=1;
		}
		return res;
	}
	modular inv()const{return pow(mod-2);}
	/*modular inv()const{
		int x,y;
		int g=extgcd(v,mod,x,y);
		assert(g==1);
		if(x<0)x+=mod;
		return modular(x);
	}*/
	friend modular operator+(int x,const modular&y){
		return modular(x)+y;
	}
	friend modular operator-(int x,const modular&y){
		return modular(x)-y;
	}
	friend modular operator*(int x,const modular&y){
		return modular(x)*y;
	}
	friend modular operator/(int x,const modular&y){
		return modular(x)/y;
	}
	friend ostream& operator<<(ostream&os,const modular&m){
		return os<<m.v;
	}
	friend istream& operator>>(istream&is,modular&m){
		ll x;is>>x;
		m=modular(x);
		return is;
	}
	bool operator<(const modular&r)const{return v<r.v;}
	bool operator==(const modular&r)const{return v==r.v;}
	bool operator!=(const modular&r)const{return v!=r.v;}
	explicit operator bool()const{
		return v;
	}
};

//extern constexpr modinfo base{998244353,3};
extern constexpr modinfo base{1000000007,0};
using mint=modular<base>;

//const int vmax=(1<<21)+10;
const int vmax=110;
mint fact[vmax],finv[vmax],invs[vmax];
void initfact(){
	fact[0]=1;
	rng(i,1,vmax){
		fact[i]=fact[i-1]*i;
	}
	finv[vmax-1]=fact[vmax-1].inv();
	for(int i=vmax-2;i>=0;i--){
		finv[i]=finv[i+1]*(i+1);
	}
	for(int i=vmax-1;i>=1;i--){
		invs[i]=finv[i]*fact[i-1];
	}
}
mint choose(int n,int k){
	return fact[n]*finv[n-k]*finv[k];
}
mint binom(int a,int b){
	return fact[a+b]*finv[a]*finv[b];
}
mint catalan(int n){
	return binom(n,n)-(n-1>=0?binom(n-1,n+1):0);
}

//VERIFY: yosupo
//KUPC2017J
//AOJDSL1A
//without rank
struct unionfind{
	vi p,s;
	int c;
	unionfind(int n):p(n,-1),s(n,1),c(n){}
	int find(int a){
		return p[a]==-1?a:(p[a]=find(p[a]));
	}
	//set b to a child of a
	bool unite(int a,int b){
		a=find(a);
		b=find(b);
		if(a==b)return false;
		p[b]=a;
		s[a]+=s[b];
		c--;
		return true;
	}
	bool same(int a,int b){
		return find(a)==find(b);
	}
	int sz(int a){
		return s[find(a)];
	}
};

map<ll,mint> memo;

mint rec(ll cur,ll nx,const vc<ll>&adj){
	int n=si(adj);
	int rem=n-popcount(cur);
	if((cur|nx)==mask(n))return fact[rem];
	if(memo.count(cur))return memo[cur];
	ll org=cur;
	mint w=1;
	rep(i,n)if(!(cur&1LL<<i)&&(nx&1LL<<i)){
		if((adj[i]&(cur|nx))==adj[i]){
			cur|=1LL<<i;
			w*=rem--;
		}
	}
	mint res=0;
	rep(i,n)if(!(cur&1LL<<i)&&(nx&1LL<<i))
		res+=rec(cur|1LL<<i,nx|adj[i],adj);
	return memo[org]=res*w;
}

mint sub(const vc<ll>&adj){
	dmp(adj);
	int n=si(adj);
	memo.clear();
	mint ans=0;
	rep(i,n)ans+=rec(1LL<<i,adj[i],adj);
	return ans*finv[n-1];
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	initfact();
	
	int n;cin>>n;
	
	unionfind uf(n);
	
	vi a=readvi(n);
	
	vvc<int> g(n);
	rep(i,n)rep(j,n)if(i!=j&&a[j]%a[i]==0)rep(k,n)if(i!=k&&j!=k&&a[k]%a[i]==0){
		uf.unite(j,k);
		g[k].pb(j);
		g[j].pb(k);
	}
	
	vvc<int> ls(n);
	rep(i,n)ls[uf.find(i)].pb(i);
	
	mint ans=1;
	
	int sz=0;
	
	rep(i,n)if(si(ls[i])>1){
		int m=si(ls[i]);
		sz+=m-1;
		vc<ll> adj(m);
		sort(all(ls[i]));
		dmp(ls[i]);
		rep(j,m)for(auto k:g[ls[i][j]]){
			adj[j]|=1LL<<lwb(ls[i],k);
		}
		ans*=sub(adj);
	}
	
	ans*=fact[sz];
	cout<<ans<<endl;
}
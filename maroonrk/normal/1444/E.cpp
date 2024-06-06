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

template<class t,class u> bool chmax(t&a,u b){if(a<b){a=b;return true;}else return false;}
template<class t,class u> bool chmin(t&a,u b){if(b<a){a=b;return true;}else return false;}

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

pi readpi(int off=0){
	int a,b;cin>>a>>b;
	return pi(a+off,b+off);
}

template<class t,class u>
void print(const pair<t,u>&p,int suc=1){
	print(p.a,2);
	print(p.b,suc);
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
	#ifdef LOCAL
	cout.flush();
	#endif
}
void no(bool ex=true){
	#ifdef CAPITAL
	cout<<"NO"<<"\n";
	#else
	cout<<"No"<<"\n";
	#endif
	if(ex)exit(0);
	#ifdef LOCAL
	cout.flush();
	#endif
}
void possible(bool ex=true){
	#ifdef CAPITAL
	cout<<"POSSIBLE"<<"\n";
	#else
	cout<<"Possible"<<"\n";
	#endif
	if(ex)exit(0);
	#ifdef LOCAL
	cout.flush();
	#endif
}
void impossible(bool ex=true){
	#ifdef CAPITAL
	cout<<"IMPOSSIBLE"<<"\n";
	#else
	cout<<"Impossible"<<"\n";
	#endif
	if(ex)exit(0);
	#ifdef LOCAL
	cout.flush();
	#endif
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

vvc<int> readGraph(int n,int m){
	vvc<int> g(n);
	rep(i,m){
		int a,b;
		cin>>a>>b;
		//sc.read(a,b);
		a--;b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	return g;
}

vvc<int> readTree(int n){
	return readGraph(n,n-1);
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

//ps[i] 1  ****  vector
//
pair<vi,vvc<int>> sub(vvc<int> ps){
	int n=si(ps);
	int s=0;
	{
		rep(i,n)chmax(s,ps[i][0]);
		s++;
		vi tmp(s);
		rep(i,n)tmp[ps[i][0]]++;
		rep(i,s-1)tmp[i+1]+=max(0,tmp[i]-1);
		s+=max(0,tmp[s-1]-1);
		s+=10;
	}
	vvc<int> idx(s);
	rep(i,n)for(auto j:ps[i])idx[j].pb(i);
	{
		vi cur(n);iota(all(cur),0);
		int head=n;
		rep(lv,s){
			sort(all(idx[lv]),[&](int i,int j){return cur[i]<cur[j];});
			for(auto i:idx[lv])
				cur[i]=head++;
		}
	}
	vc<bool> del(n);
	unionfind uf(s+1);
	//lv bitmax
	auto getmaxid=[&](int lv){
		while(1){
			lv=uf.find(lv);
			if(lv==0)return -1;
			auto&z=idx[lv-1];
			while(si(z)){
				int i=z.back();
				if(del[i]||ps[i].back()>=lv){
					z.pop_back();
					continue;
				}
				return i;
			}
			uf.unite(lv-1,lv);
		}
		assert(false);
	};
	vi cnt(s);
	rep(i,n)for(auto j:ps[i])cnt[j]++;
	set<int> vacant;
	rep(i,s)if(!cnt[i])vacant.insert(i);
	per(pos,s){
		while(cnt[pos]>=2){
			auto itr=vacant.lower_bound(pos);
			assert(itr!=vacant.ed);
			int nx=*itr;
			assert(cnt[nx]==0);
			cnt[nx]++;
			vacant.erase(itr);
			int i=getmaxid(nx);
			while(si(ps[i])){
				int x=ps[i].back();
				if(x<nx){
					ps[i].pop_back();
					cnt[x]--;
					if(cnt[x]==0){
						vacant.insert(x);
					}
				}else break;
			}
			if(ps[i].empty()){
				del[i]=true;
			}
			ps[i].pb(nx);
		}
	}
	vi res;
	per(i,s)if(cnt[i])res.pb(i);
	return mp(res,ps);
}

vi add1(vi x){
	int n=si(x);
	rep(i,n){
		if(x[n-1-i]>i){
			x.pb(i);
			return x;
		}
		x.pop_back();
	}
	return {n};
}

void slv(){
	int n;cin>>n;
	vvc<pi> t(n);
	vc<pi> es;
	rep(i,n-1){
		int a,b;cin>>a>>b;
		a--;b--;
		t[a].eb(b,i);
		t[b].eb(a,i);
		es.eb(a,b);
	}
	vi w(n-1);
	{
		auto rec=[&](auto self,int v,int p)->vi{
			vvc<int> buf;
			for(auto [to,e]:t[v])if(to!=p){
				buf.pb(add1(self(self,to,v)));
			}
			auto [res,sol]=sub(buf);
			int head=0;
			for(auto [to,e]:t[v])if(to!=p){
				w[e]=sol[head++].back();
			}
			return res;
		};
		rec(rec,0,-1);
	}
	vc<bool> del(n-1);
	int root=0;
	while(1){
		int mx=-1,idx=-1;
		auto rec=[&](auto self,int v,int p)->void{
			for(auto [to,e]:t[v])if(to!=p&&!del[e]){
				if(chmax(mx,w[e]))idx=e;
				self(self,to,v);
			}
		};
		rec(rec,root,-1);
		if(mx==-1){
			cout<<"! "<<root+1<<endl;
			break;
		}
		del[idx]=true;
		cout<<"? "<<es[idx].a+1<<" "<<es[idx].b+1<<endl;
		root=read()-1;
	}
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	//int t;cin>>t;rep(_,t)
	slv();
}